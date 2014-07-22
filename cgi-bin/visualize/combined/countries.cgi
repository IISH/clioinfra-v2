#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../../libs";

use DB_File;
use DBI;
use ClioInfra;
use ClioTemplates;
$| = 1;

#$site = "http://beta.clio-infra.eu:8081";
$DIR = "/home/www/clio_infra/clioinfra";
#$script = "http://beta.clio-infra.eu:8081/cgi-bin/visualize/combined/countries.cgi";

$htmltemplate = "$Bin/../templates/combinedsearch.tpl";

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../../clioinfra.config");
$script = $dbconfig{root}.'/cgi-bin/visualize/combined/countries.cgi';
$site = $dbconfig{root};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

$head = 1;
use Getopt::Long;

my $result = GetOptions(
    \%options,
    'init' => \$init,
    'showsubregions=s' => \$showsubregions,
    'showcountries=s' => \$showcountries,
    'region=s' => \$showregion,
    'showsubregion=s' => \$showsubregion,
    'showall=s' => \$showall
);

if ($dbh)
{
    ($codeshash, $country2idhash, $code2regionhash, $country2regionhash) = loadcodes($dbh);

    %countries = %{$codeshash} if ($codeshash);
    %country2id = %{$country2idhash} if ($country2idhash);
    %id2country = reverse %country2id;
    %country2region = %{$country2regionhash} if ($country2regionhash);
    %datasets = loaddatasets($dbh);

    ($mainregionhash, $regionhash, $roothash, $region2roothash) = loadregions($dbh);
    %mainregions = %{$mainregionhash} if ($mainregionhash);
    %regions = %{$regionhash} if ($regionhash);
    %root4regions = %{$roothash} if ($roothash);
    %region2root = %{$region2roothash} if ($region2roothash);
    %topics = loadtopics($dbh, $topic);
    %years = loadyears($dbh);
    %id2year = reverse %years;
    %indicators = loadindicators($dbh, $indicator);
}

my $controluri;
if (!$showsubregions && !$showcountries)
{
    $init++;
}
$init++;

unless ($uri)
{
    use CGI;
    my $q = new CGI;
    print "Content-type: text/html\n\n";

    $showall = $q->param('showall');
    $showsubregions = $q->param('showsubregions');
    $showcountries = $q->param('showcountries');
    $showregion = $q->param('showregion') || $q->param('region');
    $showsubregion = $q->param('showsubregion');
    $subregion = $regions{$showsubregion};
    $showall = $q->param('showall');
    $removecountry = $q->param('remove');
    $removecountry{$removecountry} = 'remove' if ($removecountry);
    
    $uri = $ENV{REQUEST_URI};
#    print "$uri<br>";

    if ($showall)
    {
	$showsubregions = "yes";
	$showcountries = "yes";
    }

    while ($uri=~s/\&removecountry\=(\d+)//)
    {
	my $id = $1;
	$removecountry{$id} = 'remove';
	print "Remove country $id <br>\n" if ($DEBUG);
    }

    while ($uri=~s/\&countrystatus\=(\d+)\:(\w+)//)
    {
	my ($id, $status) = ($1, $2);
	my $country = $id2country{$id};
	my $reg_id = $country2region{$country}; 
 	my $mainregion_id = $region2root{$reg_id};
	print "$reg_id $country $region2root{$reg_id}<br>" if ($DEBUG);
	unless ($removecountry{$id})
	{
	   if ($status && !$saved{mainregion}{$mainregion_id}{$id})
	   {
	        $countrystatus{$id} = $status;
		$count{mainregion}{$mainregion_id}++;
		$saved{mainregion}{$mainregion_id}{$id}++;
		$controluri.="&countrystatus=$id:$status";
	   };
	}
	else
	{
	   #$removecountry{$id} = 'remove';
	}
    }

}
AJAXscript() if ($uri!~/countrystatus/i);

if ($init)
{
    #$regionsblock="<form name=\"country\">";
    $regionsblock.="<div class=\"countriesblock\"><div id=\"refreshcountries\"><ul class=\"countries mainregions\">";
    $regionsblock.="<table border=0 width=100% align=left>";

    foreach $mainregion (sort keys %mainregions)
    {
        my $reg_id = $mainregions{$mainregion};
        print "$mainregion $reg_id\n" if ($DEBUG);
        #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$reg_id\"><td style=\"padding: 2px;\">$mainregion</td></tr>\n";
        $regionsblock.="<tr><td width=90%><input type=\"checkbox\" name=\"region$reg_id\" value=\"$mainregion\"> $mainregion %%count_mainregion$reg_id%%</td>";
        $OPEN = "+";
        $ACTION = "open";

        if ($showregion && $showregion eq $mainregion)
        {
            $OPEN = "-";
            $ACTION = "close";
        };

	# ./combined/countries.cgi --showsubregions=yes --region Europe --subregion 'Western Europe' --showcountries 'yes'
        $regionsblock.="<td width=10%><input style=\"width:25px\" value=\"$OPEN\" type=\"button\" onclick='JavaScript:xmlhttpPost(\"$script?showsubregions=yes&showregion=$mainregion&showsubregion=$subregion&%%removecountry%%&%%controluri%%\", \"refreshcountries\")'></td></tr>\n<tr><td>";
#       print "http://beta.clio-infra.eu:8081/cgi-bin/visualize/customdatasets.cgi?showregion=$mainregion&stopblocks=yes&showsubregions=yes&showcountries=yes&action=$ACTION <br>\n";

	my $active = "";
	$active = "yes" if ($showsubregions && (!$showregion || $showregion && $showregion eq $mainregion));
	#$active++ if ($showall);

	if ($active)
        {
            $regionsblock.="<ul class=\"countries regions\">";

            foreach $region (sort keys %regions)
            {
                my $root = $root4regions{$region};
		#print "$region $showsubregion<Br>";

		my $show = "no";
		my $checkedsubregion = "";
		$show = "yes" if ($subregion && ($subregion eq $region));
                $show = "yes" if (!$subregion && ($root eq $reg_id));
		if ($showsubregion)
	        {
		   $show = 'no';
		   $show = 'selected' if ($region eq $showsubregion);
		   $checkedsubregion = "checked" if ($region eq $showsubregion);
	        }
		$show = "yes" if ($showall);
		$show = "yes" if ($root eq $reg_id);
#$regionsblock.="<li class=\"collapsible\"><input type=\"checkbox\" $checkedsubregion onclick='JavaScript:xmlhttpPost(\"$script?showsubregions=yes&showregion=$mainregion&subregion=$subregion&showcountries=yes&showsubregion=$region&uri=$uri&%%removecountry%%&%%controluri%%\", \"refreshcountries\")'; name=\"region$regions{$region}\" value=\"$region\">&nbsp; $region %%count_region$regions{$region}%%</li>\n";

		if ($show eq 'yes' || $show eq 'selected')
                {
                    print "$region $regions{$region} ROOT$root\n" if ($DEBUG);
                    #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$regions{$region}\"><td style=\"padding: 2px;\">$root $region</td></tr>\n";
                    $regionsblock.="<li class=\"collapsible\"><input type=\"checkbox\" $checkedsubregion onclick='JavaScript:xmlhttpPost(\"$script?showsubregions=yes&showregion=$mainregion&subregion=$subregion&showcountries=yes&showsubregion=$region&uri=$uri&%%removecountry%%&%%controluri%%\", \"refreshcountries\")'; name=\"region$regions{$region}\" value=\"$region\">&nbsp; $region %%count_region$regions{$region}%% </li>\n";
	    	    $showcountries = "" if ($showsubregion);
		    $showcountries = "yes" if ($region eq $showsubregion);

                    if ($showcountries)
                    {
                        $regionsblock.="<ul class=\"countries\">";
			my $checkedcountry;
			$checkedcountry = "checked" if ($show eq 'selected' || $show eq 'yes'); # || '';
                        foreach $country (sort keys %countries)
                        {
			     my $country_id = $country2id{$country};
			     my $thischeckedcountry = $checkedcountry;
			     $thischeckedcountry = "" if ($removecountry{$country_id});
			     my $countrystatus = $thischeckedcountry; # || $checkedcountry;

                             print "            $country $country2region{$country}\n" if ($country2region{$country} eq $regions{$region} && $DEBUG);
                             if ($country2region{$country} eq $regions{$region})
                             {
				my $region_id = $regions{$region};
                                #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\"><td style=\"padding: 2px;\">&nbsp;&nbsp;&nbsp;$country</td></tr>\n";
                                $regionsblock.="<li><input type=\"checkbox\" $countrystatus name=\"country$id\" value=\"$country\" onclick='JavaScript:xmlhttpPost(\"$script?showsubregions=yes&showregion=$mainregion&subregion=$subregion&showcountries=yes&showsubregion=$region&remove=$country_id&%%removecountry%%&%%controluri%%\", \"refreshcountries\")';>&nbsp;$country</li>\n";
				$count{region}{$region_id}++ if ($countrystatus && !$saved{mainregion}{$reg_id}{$country_id});
				$count{mainregion}{$reg_id}++ if ($countrystatus && !$saved{mainregion}{$reg_id}{$country_id});
				$saved{mainregion}{$reg_id}{$country_id}++;
				$controluri.="&countrystatus=$country_id:$countrystatus";
                             };
                        }
                        $regionsblock.="</ul>";
                    }
                };
        }
        $regionsblock.="</ul>";
       }
    };

    $regionsblock.="</td></tr></table></ul></div></div>";

    foreach $token (sort keys %count)
    {
	my %counter = %{$count{$token}};
	foreach $count (sort keys %counter)
	{
	    my $htmlcount="<b>($counter{$count})</b>";
	    $count{$token}{$count} = $htmlcount;
	}
    }

    foreach $id (keys %removecountry)
    {
	$removecountry.="&removecountry=$id";
    }

    while ($regionsblock=~s/\%\%count\_(\w+?)(\d+)\%\%/$count{$1}{$2}/g) { }; # print "$1 $2<br>"; };-
    $regionsblock=~s/\%\%controluri\%\%/$controluri/gsxi;
    $regionsblock=~s/\%\%removecountry\%\%/$removecountry/gsxi;
    print "$regionsblock\n";
#    print "$controluri<br>";
};

sub AJAXscript
{
print <<"EOF";
<script language="Javascript">
function xmlhttpPost(strURL,blockname) {
    var xmlHttpReq = false;
    var self = this;
    //alert(strURL);
    // Mozilla/Safari
    if (window.XMLHttpRequest) {
        self.xmlHttpReq = new XMLHttpRequest();
    }
    // IE
    else if (window.ActiveXObject) {
        self.xmlHttpReq = new ActiveXObject("Microsoft.XMLHTTP");
    }

    var sURL = strURL;
    //alert(sURL);

    self.xmlHttpReq.open('GET',sURL,false);
    self.xmlHttpReq.setRequestHeader("User-Agent",navigator.userAgent);
    self.xmlHttpReq.send(null);
    if (self.xmlHttpReq.status==200) { updatepage(self.xmlHttpReq.responseText,blockname) };

    self.xmlHttpReq.onreadystatechange = function() {
        if (self.xmlHttpReq.readyState == 4) {
            updatepage(self.xmlHttpReq.responseText);
        }
    }
}

function updatepage(str,blockname){
    //blockname = "refreshcountries";
    document.getElementById(blockname).innerHTML = str;
}
</script>
EOF
}
