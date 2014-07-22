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

    print "Content-type: text/html\n\n";
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
}

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
  	    $indicatorsblock.="<input type=\"checkbox\" id=\"indicator\" name=\"indicator\" value=\"$ind_id\"> $indicator<br>";
    	};
    }

# Create topics block

   	$topicsblock.="<ul class=\"topicsblock bef-tree\">";
    foreach $topic (sort keys %topics)
    {
      my $topic_id = $topics{$topic};
      if ($topic)
      {
        $topicsblock.="<li><div><input type=\"checkbox\" id=\"topic\" name=\"topic\" value=\"$topic_id\"> <b>$topic</b></div><ul>";
      };

      foreach $indicator (sort keys %indicators)
	    {
		    my $indicator_id = $datasets{$indicator};
		    $dID = $datasetmap{$indicator}{topic_id};	        
		    my $ind_id = $datasetmap{$indicator}{indicator_id};
		    if ($dID eq $topic_id)
		    {
	        $topicsblock.="<li><input type=\"checkbox\" id=\"indicator$indicator_id\" name=\"indicator$ind_id\" value=\"$indicator\">$indicator</li>"; 
		    };
	    }
	    $topicsblock.="</ul></li>";
    }
   	$topicsblock.="</ul>";


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
    }
  };

# Create country block

$showmainregions = "yes" unless ($stopblocks);
$showmainregions = '' if ($stopblocks);
my $regionsblock;

#  $regionsblock.="<div class=\"countriesblock\">";
  $regionsblock.="<ul class=\"countries mainregions bef-tree\">";

  foreach $mainregion (sort keys %mainregions)
  {
    my $reg_id = $mainregions{$mainregion};
    $regionsblock.="<li><div><input type=\"checkbox\" name=\"region$reg_id\" value=\"$mainregion\"> $mainregion</div>";

    $regionsblock.="<ul class=\"countries regions\">";

    foreach $region (sort keys %regions)
    {
      my $root = $root4regions{$region};

      if ($root eq $reg_id)
      {
        $regionsblock.="<li><div><input type=\"checkbox\" name=\"region$regions{$region}\" value=\"$region\">&nbsp; $region </div>\n";
        $regionsblock.="<ul class=\"countries\">";
        foreach $country (sort keys %countries)
        {
  	      my $country_id = $country2id{$country};

          if ($country2region{$country} eq $regions{$region})
          {
            my $region_id = $regions{$region};
            $regionsblock.="<li><input type=\"checkbox\" name=\"country$id\" value=\"$country\">&nbsp;$country</li>\n";
          };
        }
        $regionsblock.="</ul></li>";
      };
    }
    $regionsblock.="</ul></li>";
  };
  $regionsblock.="</ul>";
#  $regionsblock.="</div>";


($filterstring, %filter) = getparams($uri);
$yearsblock = "" unless ($showyears);
$topicsblock = "" unless ($showtopics);
$indicatorsblock = "" unless ($showindicators);
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

     $link = "$site/cgi-bin/reader/combinedb.cgi?$filterquery"; 
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
