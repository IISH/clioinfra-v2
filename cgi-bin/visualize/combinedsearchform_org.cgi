#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";

use DB_File;
use DBI;
use ClioInfra;
use ClioTemplates;
$| = 1;

#$DIR = "/home/www/clio_infra/clioinfra";

$htmltemplate = "$Bin/../templates/combinedsearch.tpl";

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$site = $dbconfig{root};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
$scripturl = $dbconfig{scripturl};
$root = $dbconfig{root};
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

$head = 1;
use Getopt::Long;

my $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'output=s' => \$output,
    'link=s' => \$link,
    'source=s' => \$source,
    'debug=i' => \$DEBUG,
    'author=s' => \$author,
    'dataset=s' => \$dataset_name,
    'user=s' => \$user,
    'uri=s' => \$uri,
    'showcountries' => \$showcountries,
    'showsubregions' => \$showsubregions,
    'showyears' => \$showyears,
    'showtopics' => \$showtopics,
    'showindicators' => \$showindicators
);

$filter = "United";
$author = "default" unless ($author);

unless ($uri)
{
    use CGI;
    my $q = new CGI;

    $showall = $q->param('showall');
    $showsubregions = $q->param('showsubregions');
    $showcountries = $q->param('showcountries');
    $stopblocks = $q->param('stopblocks');
    $showregion = $q->param('showregion');
    $showyears = $q->param('showyears');
    $showindicators = $q->param('showindicators');
    $showtopics = $q->param('showtopics');
    $showblock = $q->param('showblock');
    $action = $q->param('action');
    $fromdate = $q->param('fromdate');
    $todate = $q->param('todate');
    $dateselected = $q->param('dateselected');
    $showregion = "" if ($action eq 'close');
    $showsubregions = "" if ($action eq 'close');
    $nojavascript = $q->param('nojavascript');

    print "Content-type: text/html\n\n";
    #print "X $dateselected\n";
}
else
{
    #$showsubregions = "yes";
    $showall++;
    $showcountries = "yes";
    $showtopics = "yes";
    $showyears = "yes";
    $showindicators = "yes";
}

$showyears++;
if ($showyears)
{
    $htmltemplate = "$Bin/../templates/combinedyears.tpl";
}
if ($showindicators)
{
    $htmltemplate = "$Bin/../templates/combinedindicators.tpl";
}
if ($showtopics)
{
    $htmltemplate = "$Bin/../templates/combinedtopics.tpl";
}

$showall++;
$htmltemplate = "$Bin/../templates/new_combinedsearch.tpl" if ($showall);
$htmltemplate = "$Bin/../templates/$showblock.tpl" if ($showblock);
print "$htmltemplate\n" if ($DEBUG);
@html = loadhtml($htmltemplate);

#$fromdate= "2012";
$actionurl = "$root/cgi-bin/visualize/combinedsearchform.cgi?showyears=yes&showblock=combinedyears";
if ($showyears)
{
    $actionurl = "$root/cgi-bin/visualize/combinedsearchform.cgi?showyears=yes&showblock=combinedyears";
    unless ($dateselected)
    {
    if ($fromdate && $todate)
    {
	$dateselected.= "$fromdate-$todate,";
    }
    elsif ($fromdate)
    {
        $dateselected.="$fromdate,";
    };
    };
    #$extrayears = $dateselected;
    my @dates = split(/\,/, $dateselected);
    if ($#dates > -1)
    {
	$extrayears.="<table border=0>";
	my %knowndate;
	foreach $date (@dates)
	{
	    unless ($knowndate{$date})
	    {
	        $extrayears.="<tr><td><input type=checkbox name=year value=\"$date\" checked>$date</td></tr>\n";
	    };
	    $knowndate{$date}++;
	}
	$extrayears.="</table>";
    }
    #print "<input type=hidden name=dateselected value=\"$extrayears\">\n";
}

unless ($nojavascript)
{
print <<"EOF";
<script language="Javascript">
function xmlhttpPost(strURL,blockname) {
    var xmlHttpReq = false;
    var self = this;
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
    //self.xmlHttpReq.setRequestHeader('Content-Type','text/html');
    self.xmlHttpReq.setRequestHeader("User-Agent",navigator.userAgent);
    self.xmlHttpReq.send(null);
    //document.getElementById(blockname).innerHTML = '';
    if (self.xmlHttpReq.status==200) { updatepage(self.xmlHttpReq.responseText,blockname) };

    self.xmlHttpReq.onreadystatechange = function() {
        if (self.xmlHttpReq.readyState == 40) {
            updatepage(self.xmlHttpReq.responseText);
        }
    }
}

function updatepage(str,blockname){
    //blockname = "refreshcountries";
    //alert(str);
    document.getElementById(blockname).innerHTML = str;
}
</script>
EOF
};

if ($dbh)
{
    ($codeshash, $country2idhash, $code2regionhash, $country2regionhash) = loadcodes($dbh);

    %countries = %{$codeshash} if ($codeshash);
    %country2id = %{$country2idhash} if ($country2idhash);
    %country2region = %{$country2regionhash} if ($country2regionhash);
    %datasets = loaddatasets($dbh);
    %datasetmap = loaddatasets($dbh, 'showmap');

    ($mainregionhash, $regionhash, $roothash) = loadregions($dbh);
    %mainregions = %{$mainregionhash} if ($mainregionhash);
    %regions = %{$regionhash} if ($regionhash);
    %root4regions = %{$roothash} if ($roothash);
    %topics = loadtopics($dbh, $topic);
    %years = loadyears($dbh);
    %id2year = reverse %years;
    %indicators = loadindicators($dbh, $indicator);

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    $topic_id = 1 unless ($topic_id);
}

# Store meta information about dataset
if ($dbh)
{
    my $DEBUG = 0;
    foreach $region (sort keys %regions)
    {
	    $region_id = $regions{$region};
	    print "$region\n" if ($DEBUG);
    }

    foreach $country (sort keys %countries)
    {
    	my $id = $country2id{$country};
    	print "$country $country2id{$country}\n" if ($DEBUG);
    	$countryblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\"><td style=\"padding: 2px;\">$country</td></tr>\n";
    }

    %indicators = %datasets;
    foreach $indicator (sort keys %indicators)
    {
	    print "$indicator $indicators{$indicator}\n" if ($DEBUG);
	    my $ind_id = $indicators{$indicator};
	    if ($indicator=~/\w+/)
    	{
      	#$indicatorsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$ind_id\"><td style=\"padding: 2px;\">$indicator</td></tr>\n";
  	    $indicatorsblock.="<input type=\"checkbox\" id=\"indicator\" name=\"indicator\" value=\"$ind_id\"> $indicator<br>";
    	};
    }

    my $showsubs = 1;
    foreach $topic (sort keys %topics)
    {
        my $topic_id = $topics{$topic};
       #$indicatorsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$ind_id\"><td style=\"padding: 2px;\">$indicator</td></tr>\n";
	$topicsblock.="<table width=100%>";
        if ($topic)
        {
	   $OPEN = "-";
           $topicsblock.="<tr><td width=90%><input type=\"checkbox\" id=\"topic\" name=\"topic\" value=\"$topic_id\"> <b>$topic</b></td>";
        };

	if ($showsubs)
	{
            foreach $indicator (sort keys %indicators)
	    {
		my $indicator_id = $datasets{$indicator};
		$dID = $datasetmap{$indicator}{topic_id};	        
		my $ind_id = $datasetmap{$indicator}{indicator_id};
		if ($dID eq $topic_id)
		{
	            $topicsblock.="<tr><td colspan=2>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"checkbox\" id=\"indicator$indicator_id\" name=\"indicator$ind_id\" value=\"$indicator\">&nbsp;$indicator</td></tr>"; 
		};
	    }
	};
	$topicsblock.="</table>";
    }

    foreach $year (sort keys %years)
    {
    	if ($year > 1500 && $year < 2020)
    	{
  	    $order{$year} = $year;
    	}
    }

    foreach $year (sort {$order{$a} <=> $order{$b}} keys %order)
    { 
	    $year_id = $years{$year};
	    #$yearsblock.="<tr style=\"cursor: pointer;\" id=\"$year_id\"><td style=\"padding: 2px;\">$year</td></tr>\n";

	    if ($year=~/00/)
	    {
  #	    $yearsblock.="<input type=\"checkbox\" name=\"years$year_id\" value=\"$year\"> $year<br>";
	    };
    }
  };

#print "$countryblock\n";
#print "$indicatorsblock\n";
#print "$yearsblock\n";
#$showcountries = "yes";
$showmainregions = "yes" unless ($stopblocks);
$showmainregions = '' if ($stopblocks);
my $regionsblock;

$script = "$site/cgi-bin/visualize/combined/countries.cgi";
unless ($nojavascript)
{
$regionsblock.="<div id=\"refreshcountries\"></div>";
$regionsblock.="<script type=\"text/javascript\"> xmlhttpPost(\"$script\", \"refreshcountries\"); </script>";
};

$DEBUG = 0;
if ($showmainregions eq 'yes1')
{
    #$regionsblock="<form name=\"country\">";
    $regionsblock.="<table width=100%>";
    $regionsblock.="<ul class=\"countries mainregions\">" unless ($nojavascript); 

    foreach $mainregion (sort keys %mainregions)
    {
  	my $reg_id = $mainregions{$mainregion};
  	print "$mainregion $reg_id\n" if ($DEBUG);
        $OPEN = "+";
        $ACTION = "open";

  	#$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$reg_id\"><td style=\"padding: 2px;\">$mainregion</td></tr>\n";
  	$regionsblock.="<tr><td width=90%><input type=\"checkbox\" name=\"region$reg_id\" id=\"region$reg_id\" value=\"$mainregion\" onclick='JavaScript:xmlhttpPost(\"$script\", \"refreshcountries\")'> $mainregion </td>";
        #$regionsblock.="<tr><td width=90%><input type=\"checkbox\" name=\"region$reg_id\" id=\"region$reg_id\" value=\"$mainregion\"> $mainregion</td>";

  	if ($showregion && $showregion eq $mainregion)
  	{
	    $OPEN = "-";
	    $ACTION = "close";
  	};

        $showcountries = "yes";
  	$regionsblock.="<td>&nbsp;<input style=\"width:25px\" value=\"$OPEN\" type=\"button\" onclick='JavaScript:xmlhttpPost(\"$script?showregion=$mainregion&stopblocks=yes&showsubregions=yes&showcountries=$showcountries&action=$ACTION&showblock=combinedcountries&nojavascript=yes\", \"refreshcountries\")'>";
  	$regionsblock.="</td></tr>";

        #$showsubregions = "yes";
	print "DEBUG $showsubregions $showregion <br>" if ($DEBUG);
  	if ($showsubregions && (!$showregion || $showregion && $showregion eq $mainregion))
  	{
  	    #$regionsblock.="<ul class=\"countries regions\">"; 
  
	    foreach $region (sort keys %regions)
  	    {
    		my $root = $root4regions{$region};

  		if ($root eq $reg_id)
   		{
   	  	    print "$region $regions{$region} ROOT$root\n" if ($DEBUG);
   	  	    #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$regions{$region}\"><td style=\"padding: 2px;\">$root $region</td></tr>\n";
	    	    $regionsblock.="<tr><td>&nbsp;&nbsp;<input type=\"checkbox\" name=\"region$regions{$region}\" value=\"$region\">&nbsp;$region $showsubregions</td></tr>";

	    	    if ($showcountries)
	    	    {
#      			$regionsblock.="<ul class=\"countries\">"; 
	        	foreach $country (sort keys %countries)
 	        	{
		    	     print "		$country $country2region{$country}\n" if ($country2region{$country} eq $regions{$region} && $DEBUG);
		    	     if ($country2region{$country} eq $regions{$region})
		    	     {
  		   	        #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\"><td style=\"padding: 2px;\">&nbsp;&nbsp;&nbsp;$country</td></tr>\n";
  		   	         $regionsblock.="<tr><td>&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"checkbox\" name=\"country$id\" value=\"$country\">&nbsp;$country</td></tr>";
		    	     };
   	        	}
      	#		$regionsblock.="</ul>"; 
	      	    }
	  	};
  	}
#  	$regionsblock.="</ul>"; 
       }
    };

    $regionsblock.="</ul>" unless ($nojavascript);
    $regionsblock.="</table>"; 

    #$stopblocks = "10";
    if ($stopblocks)
    {
         #print "$regionsblock\n";
	$cleanall++;
#        exit(0); # if ($stopblocks);
    };
};

($filterstring, %filter) = getparams($uri);
$yearsblock = "" unless ($showyears);
$topicsblock = "" unless ($showtopics);
$indicatorsblock = "" unless ($showindicators);
$yearsblock = "" if ($cleanall);
#print "XXX\n";
foreach $string (@html)
{
    $string=~s/\%\%countriesblock\%\%/$regionsblock/gsxi;
    $string=~s/\%\%indicatorsblock\%\%/$indicatorsblock/gsxi;
    $string=~s/\%\%yearsblock\%\%/$yearsblock/gsxi;
    $string=~s/\%\%topicsblock\%\%/$topicsblock/gsxi;
    $string=~s/\%\%filterstring\%\%/$filterstring/gsxi;
    $string=~s/\%\%actionurl\%\%/\"$actionurl\"/gsxi;
    $string=~s/\%\%extrayears\%\%/$extrayears/gsxi;
    $string=~s/\%\%showblock\%\%/\"$showblock\"/gsxi;
    $string=~s/\%\%fromdate\%\%/$fromdate/gsxi;
    $string=~s/\%\%todate\%\%/$todate/gsxi;
    $string=~s/\%\%dateselected\%\%/$dateselected/gsxi;

    print "$string\n";
}

sub getparams
{
   my ($uri, $DEBUG) = @_;
   my ($filterstring, %filter, $filterquery, $CTRcount);
 
   $uri=~s/\/searchall\.html//gsxi;
   $uri=~s/^.+?\?//gsxi;
   $uri=~s/^\"|\"$//g;
   $uri=~s/\+/ /gsxi;

   if ($uri=~/\w+/)
   {
     my @filters = split(/\&/, $uri);
     foreach $param (@filters)
     {
	     my ($name, $value) = split(/\=/, $param);
	     $filter{$name} = $value;
	     $fname = $name;
	     $fname=~s/\d+$//g;
	     $filterstring.="$fname => $value<br /> ";

	     $CTRcount++ if ($name=~/country/i);

	     if ($name=~/(\S+?)(\d+)/)
	     {
	       $filterquery.="$1=$value&";
	     }
	     else
	     {
	       $filterquery.="$name=$value&";
	     }
	     print "$name => $value <br>\n" if ($DEBUG);
     } 
   
     $filterstring=~s/\,\s*$//g;

     $link = "$site/cgi-bin/reader/combinedb.cgi?$filterquery"; #indicator=Female%20life%20expectancy%20at%20birth&topic=Demography&region=Western%20Europe";
     $chartlink = "$site/charts/showchart/$filterquery";
     $chartlink = "$site/indicator.html?$filterquery";
     $chartlink.="visualize=lines" if ($CTRcount > 1);
     $filestring="You can <a href=\"$link\">download</a> your custom dataset or visualize it on <a href=\"$link\">map</a> or <a href=\"$chartlink\">chart</a>"; 
     $filterstring="<b>$filestring. <br />Filters are: <br /> $filterstring</b>";
   }

   return ($filterstring, %filter);
}

sub loadhtml
{
   my ($file, $DEBUG) = @_;
   my @content;
 
   open(file, $file);
   @content = <file>;
   close(file);

   return "@content";
}

sub loadconfig
{
    my ($configfile, $DEBUG) = @_;
    my %config;

    open(conf, $configfile);
    while (<conf>)
    {
        my $str = $_;
        $str=~s/\r|\n//g;
        my ($name, $value) = split(/\s*\=\s*/, $str);
        $config{$name} = $value;
    }
    close(conf);

    return %config;
}
