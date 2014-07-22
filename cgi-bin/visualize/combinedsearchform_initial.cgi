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

#$site = "http://beta.clio-infra.eu:8081";
$DIR = "/home/www/clio_infra/clioinfra";

$htmltemplate = "$Bin/../templates/combinedsearch.tpl";

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$site = $dbconfig{root};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
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
    $stopblocks = $q->param('stopblocks') || 'yes';
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
$htmltemplate = "$Bin/../templates/combinedsearch.tpl" if ($showall);
$htmltemplate = "$Bin/../templates/$showblock.tpl" if ($showblock);
#print "$htmltemplate\n";
@html = loadhtml($htmltemplate);

#$fromdate= "2012";
$actionurl = "$site/cgi-bin/visualize/customdatasets.cgi?showyears=yes&showblock=combinedyears";
if ($showyears)
{
    $actionurl = "$site/cgi-bin/visualize/customdatasets.cgi?showyears=yes&showblock=combinedyears";
    #$actionurl.="&dateselected=$dateselected" if ($dateselected);
    #$actionurl.="&fromdate=$fromdate" if ($fromdate);
    #$actionurl.="&todate=$todate" if ($todate);
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
    var from_date = document.getElementById('from_date').value;
    var to_date = document.getElementById('to_date').value;
    var dateselected = document.getElementById('date_selected').value;
    if (from_date && to_date)
    {
	dateselected=dateselected+from_date+'-'+to_date+',';
    }
    else
    {
        if (from_date)
        {
	    strURL=strURL+'&fromdate='+from_date;
	    dateselected=dateselected+from_date+',';
        }
        if (to_date)
        {
            strURL=strURL+'&todate='+to_date;
	    dateselected=dateselected+to_date+',';
        }
    }
    //alert(dateselected);

    if (dateselected)
    {
	//document.getElementById('date_selected').value=document.getElementById('date_selected').value+','+dateselected;
	strURL=strURL+'&dateselected='+dateselected;
    }
    //alert(strURL+' '+dateselected);

    var sURL = strURL;
    //alert(sURL);

    self.xmlHttpReq.open('GET',sURL,false);
    //self.xmlHttpReq.setRequestHeader('Content-Type','text/html');
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

if ($dbh)
{
    ($codeshash, $country2idhash, $code2regionhash, $country2regionhash) = loadcodes($dbh);

    %countries = %{$codeshash} if ($codeshash);
    %country2id = %{$country2idhash} if ($country2idhash);
    %country2region = %{$country2regionhash} if ($country2regionhash);
    %datasets = loaddatasets($dbh);

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

    foreach $topic (sort keys %topics)
    {
      my $topic_id = $topics{$topic};
      #$indicatorsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$ind_id\"><td style=\"padding: 2px;\">$indicator</td></tr>\n";
    	if ($topic)
    	{
            $topicsblock.="<input type=\"checkbox\" id=\"topic\" name=\"topic\" value=\"$topic_id\"> $topic<br>";
    	};
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
$showcountries = "yes";
if ($showcountries)
{
    #$regionsblock="<form name=\"country\">";
    $regionsblock.="<div id=\"refreshcountries\"><ul class=\"countries mainregions\">"; 

    foreach $mainregion (sort keys %mainregions)
    {
  	my $reg_id = $mainregions{$mainregion};
  	print "$mainregion $reg_id\n" if ($DEBUG);
  	#$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$reg_id\"><td style=\"padding: 2px;\">$mainregion</td></tr>\n";
  	$regionsblock.="<li class=\"collapsible\"><input type=\"checkbox\" name=\"region$reg_id\" value=\"$mainregion\"> $mainregion";
  	$OPEN = "+";
  	$ACTION = "open";

  	if ($showregion && $showregion eq $mainregion)
  	{
	    $OPEN = "-";
	    $ACTION = "close";
  	};

  	$regionsblock.="&nbsp;<input style=\"width:25px\" value=\"$OPEN\" type=\"button\" onclick='JavaScript:xmlhttpPost(\"$site/cgi-bin/visualize/combined/countries.cgi?showregion=$mainregion\", \"refreshcountries\")'>";
#	print "http://beta.clio-infra.eu:8081/cgi-bin/visualize/customdatasets.cgi?showregion=$mainregion&stopblocks=yes&showsubregions=yes&showcountries=yes&action=$ACTION <br>\n";
  	$regionsblock.="</li>";

  	if ($showsubregions && (!$showregion || $showregion && $showregion eq $mainregion))
  	{
  	    $regionsblock.="<ul class=\"countries regions\">"; 
  
	    foreach $region (sort keys %regions)
  	    {
    		my $root = $root4regions{$region};

  		if ($root eq $reg_id)
   		{
   	  	    print "$region $regions{$region} ROOT$root\n" if ($DEBUG);
   	  	    #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$regions{$region}\"><td style=\"padding: 2px;\">$root $region</td></tr>\n";
	    	    $regionsblock.="<li class=\"collapsible\"><input type=\"checkbox\" name=\"region$regions{$region}\" value=\"$region\">&nbsp;$region</li>";

	    	    if ($showcountries)
	    	    {
      			$regionsblock.="<ul class=\"countries\">"; 
	        	foreach $country (sort keys %countries)
 	        	{
		    	     print "		$country $country2region{$country}\n" if ($country2region{$country} eq $regions{$region} && $DEBUG);
		    	     if ($country2region{$country} eq $regions{$region})
		    	     {
  		   	        #$regionsblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\"><td style=\"padding: 2px;\">&nbsp;&nbsp;&nbsp;$country</td></tr>\n";
  		   	         $regionsblock.="<li><input type=\"checkbox\" name=\"country$id\" value=\"$country\">&nbsp;$country</li>";
		    	     };
   	        	}
      			$regionsblock.="</ul>"; 
	      	    }
	  	};
  	}
  	$regionsblock.="</ul>"; 
       }
    };

    $regionsblock.="</ul></div>"; 

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
