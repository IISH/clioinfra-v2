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

#$site = "http://node-149.dev.socialhistoryservices.org";
$scriptdir = "/home/clio-infra/cgi-bin";
$countrylink = "datasets/countries";
$indicatorlink ="indicator.html";

$htmltemplate = "$Bin/../templates/countries.tpl";
@html = loadhtml($htmltemplate);

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$site = $dbconfig{root};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{webdbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh_web = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
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
    'dataset=s' => \$dataset_name,
    'user=s' => \$user,
    'showtopics=s' => \$showtopics,
    'showindicators=s' => \$showindicators,
    'showcountries=s' => \$showcountries,
    'topicuri=s' => \$topicuri,
    'indicatoruri=s' => \$indicatoruri,
    'uri=s' => \$uri
);

$origuri = $uri;
$filter = "United";
$topicuri = "topic_" unless ($topicuri);
$indicatoruri = "indicatoruri_" unless ($indicatoruri);

if ($uri=~/topic\?topicuri\=topic\_(\d+)/)
{
   $topic_ID = $1;
}

if ($uri=~/indicators\?indicatoruri=indicatoruri\_(\d+)/)
{
    $indicator_id = $1;
    $showindicators= "";
    $showcountries = "";
}

if ($uri=~/country\=(.+)$/)
{
   $country = $1;
   $country=~s/^\"|\"$//g;
   $filtercountry = $country;
   $loadblock = "Country Page";
   $showcountries = "";
   $countrycode = "";
}
if ($uri=~/country\?/)
{
   $loadblock = "All about Country"; 
}

if ($dbh)
{
    ($codeshash, $country2idhash, $code2regionhash, $country2regionhash) = loadcodes($dbh);

    %countries = %{$codeshash} if ($codeshash);

    %countryids = %{$country2idhash} if ($country2idhash);
    $countrycode = $countries{$country};

    %country2id = %{$country2idhash} if ($country2idhash);
    %country2region = %{$country2regionhash} if ($country2regionhash);
    %datasets = loaddatasets($dbh);
    %datasetmap = loaddatasets($dbh, 'showmap');

    ($mainregionhash, $regionhash, $roothash) = loadregions($dbh);
    %mainregions = %{$mainregionhash} if ($mainregionhash);
    %regions = %{$regionhash} if ($regionhash);
    %root4regions = %{$roothash} if ($roothash);
    %topics = loadtopics($dbh, $topic);
    %rtopics = reverse %topics;
    %years = loadyears($dbh);
    %id2year = reverse %years;
    %indicators = loadindicators($dbh, $indicator);

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    $topic_id = 1 unless ($topic_id);
}

if ($indicator_id)
{
    %rind = %datasets;
    print "IndicatorID: $indicator_id $rind{$indicator_id}\n";
    exit(0);
}

if ($topic_ID)
{
    print "TopicID: $topic_ID\n";
    exit(0);
}

if ($showcountries)
{
    foreach $region (sort keys %regions)
    {
        $region_id = $regions{$region};
        print "$region\n" if ($DEBUG);
    }

    %columns = ("A", 1, "E", 2, "L", 3, "S", 4);
    $basicletter = "A";
    $countrypage="<table width=\"100%\">";
    foreach $country (sort keys %countries)
    {
        my $id = $country2id{$country};
        print "$country $country2id{$country}\n" if ($DEBUG);
        $countryblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\" valign=\"top\">";

        $currentletter = $startletter || 'A';
        if ($country=~/^(\w)/)
        {
            $startletter = $1;
        }

        if ($columns{$startletter})
        {
            unless ($done{$startletter})
            {
                if ($basicletter ne 'A')
                {
                   $countrypage.="</td>\n";
                }
                $countrypage.="<td width=\"25%\" valign=\"top\">\n";
                $done{$startletter} = "done";
                $blockid++;
            }
        }

        if (($startletter ne $currentletter) || $blockid < 2)
        {
           $basicletter = $startletter;
  	       $countrypage.="</ul></div>\n" if ($startletter ne 'A');
  	       $countrypage.="\n<div class=\"letter\"><div class=\"startletter\">$startletter</div>\n<ul>\n";
           $blockid++;
        }

        $countrypage.="<li><a href=\"/$countrylink?country=$countryids{$country}\">$country</a></li>\n";
    }
    $countrypage.="</ul></div></td>";

    $countrypage = '<div class="datasets countrypage">' . $countrypage . '</div>';
    $countrypage.="</table>";
    print "$countrypage\n";
    exit(0);
}

if ($showtopics)
{
    $descriptions = loadtemplate($dbh_web, "Topics Descriptions");

    my @topics = split(/\n/, $descriptions);
    foreach $topicname (sort keys %topics)
    {
        $topicname=~s/\s+$//g;
        $topicdesc=~s/^(.{5,500}\.)\s+.+$/$1/g;
        $topicintro{$topicname} = $topicdesc if ($topics{$topicname});
      	$topicblock.="<li><a href=\"?topicuri=$topicuri$topics{$topicname}\">$topicname</a></li>\n";
        print "$topicname <b>$topics{$topicname}</b> => $topicdesc <br/>\n" if (!$topics{$topicname} && $DEBUG);
    }
    $topicblock = '<div class="datasets topicpage"><ul>' . $topicblock . '</ul></div>';
    print "$topicblock\n";
    exit(0);
}

if ($showindicators)
{
    %indicators = %datasets;
    my (%known, %inblock);
    foreach $topic (sort keys %topics)
    {
      	$max++ if ($topic);
        foreach $indicator (sort keys %indicators)
        {
    	    $dID = $datasetmap{$indicator}{topic_id};
            if ($indicator=~/\w+/ && $dID == $topics{$topic})
            {
          		$inblock{$topic}++;
      	    }
      	}
    }
    foreach $indicator (sort keys %indicators)
    {
    	$max++ unless ($known{$indicator});
    }

    $on_column = int(($max / 4) + 1);

    my $MAX = 10;
    $indicatorsblock="<div class=\"datasets indicatorpage\"><ul><table width=100%><tr><td valign=top width=25%>";
    foreach $topic (sort keys %topics)
    {
      	unless ($inblock{$topic})
      	{
    	    if ($indicatorID % ($on_column+1) == 0)
            {
                $indicatorsblock.="</td><td valign=top width=25%>";
            }
  	    }
	      $indicatorID++;
	
	      $indicatorsblock.="<li class=\"topics\"><a href=\"/datasets/topics?topicuri=topic_$topics{$topic}\" style=\"color:#FFFFFF\">$topic </a></li>\n";
	      my $inblock;
        foreach $indicator (sort keys %indicators)
        {
            print "$indicator $indicators{$indicator}\n" if ($DEBUG);
            my $ind_id = $indicators{$indicator};
      	    $dID = $datasetmap{$indicator}{topic_id};
            if ($indicator=~/\w+/ && $dID == $topics{$topic})
            {
    	         if ($indicatorID % ($on_column+1) == 0)
                 {
          		      $indicatorsblock.="</td><td valign=top width=25%>";
	               }
          		 $indicatorID++;
               $indicatorsblock.="<li><a href=\"?indicatoruri=$indicatoruri$ind_id\">$indicator </a></li>\n";
            };
        }

    };
    $indicatorsblock.="</td></tr></table></ul></div>";

    print "$indicatorsblock\n";
    exit(0);
}

if ($dbh_web && $country)
{
    $country=~s/\%20/ /g;
    $template = loadtemplate($dbh_web, $loadblock); 
    $descriptions = loadtemplate($dbh_web, "Topics Descriptions");

    my @topics = split(/\n/, $descriptions);
    foreach $str (@topics)
    {
	    my ($topicname, $topicdesc) = split(/\;\;/, $str);
	    $topicname=~s/\s+$//g;
	    $topicdesc=~s/^(.{5,500}\.)\s+.+$/$1/g;
	    $topicintro{$topicname} = $topicdesc if ($topics{$topicname});
	    print "$topicname <b>$topics{$topicname}</b> => $topicdesc <br/>\n" if (!$topics{$topicname} && $DEBUG);
    }

    foreach $dataset (sort keys %datasetmap)
    {
	    $topicid = $datasetmap{$dataset}{topic_id};
	    my $topic;
      
	    if ($topicid)
    	    {
  	        $topic = $rtopics{$topicid};
    	    }

	      $topicname{$dataset} = $topic;
	      $linksinfo{$topic}{$dataset} = $datasets{$dataset};
	      $url = "$site/map/all";
	      $urldata = $dataset;
	      $url = "/$indicatorlink?indicator=$dataset&country=$country";
	      $linksmap{$topic}.="<a href=\"$url\">$dataset</a> <br>\n";

	      print "$dataset $datasetmap{$dataset}{indicator_id} $datasetmap{$dataset}{topic_id} => $topicid <b>$topic</b> <br />\n" if ($DEBUG);
      }

    $uri = "$indicatorlink?country=$filtercountry&indicator=Inflation";
    my $tmptemplate = $template;
    while ($tmptemplate=~s/\%\%countrychart(\d+)\%\%//sxi)
    {
	    $filtercountry = $country;
	    $countrychart = `$scriptdir/charts/charts.cgi --uri=\"$origuri\" --indicatorID=\"$1\"`;
	    print "Chart No $1 <br/>\n" if ($DEBUG);
	    $charts{$1} = $countrychart;
    }

    if ($loadblock=~/All\s+about/)
    {
    	foreach $topic (sort keys %topicintro)
    	{
	      my $showdataset;
	      my %alldata = %{$linksinfo{$topic}};
	      foreach $dataset (sort keys %alldata)
	      {
      		$showdataset = $dataset;
	      }
	      if ($showdataset)
	      {
      		$indicator = $showdataset;
          $uri = "$indicatorlink?country=$filtercountry&indicator=$indicator";
          $chartID++;
          $runchart = "$scriptdir/charts/charts.cgi --uri=\"$uri\" --indicator=\"$indicator\" --indicatorID=\"$chartID\"";
          $countrychart = `$runchart`;
      		$charts{$indicator} = $countrychart;
	      }
    	}
    }

    while ($tmptemplate=~s/\%\%countrychart\:(.+?)\%\%//sxi)
    {
	     $indicator = $1;
	     print "Indicator: $indicator<br />" if ($DEBUG);
	     $indicator=~s/^\(|\)//g;
       $filtercountry = $country;
	     $uri = "$indicatorlink?country=$filtercountry&indicator=$indicator";
	     $chartID++;
       $runchart = "$scriptdir/charts/charts.cgi --uri=\"$uri\" --indicator=\"$indicator\" --indicatorID=\"$chartID\"";
    	 $countrychart = `$runchart`;
       print "Chart No $1 $runchart <br/>\n" if ($DEBUG);
       $charts{$indicator} = $countrychart;
    }

    foreach $chart (sort keys %charts)
    {
	    print "Chart $chart <br>\n" if ($DEBUG);
	    $tmpchart = $chart;
	    $tmpchart=~s/\s+/\\s\+/g;
	    $topic = $topicname{$chart};
	    $template=~s/\%\%countrychart\:\($tmpchart\)\%\%/$charts{$chart}/gsxi;
	    $template=~s/\%\%intro\:\($tmpchart\)\%\%/<small>$topicintro{$topic}<\/small>/gsxi;
	    $template=~s/\%\%topic\:\($tmpchart\)\%\%/&nbsp;<b>$topicname{$chart}<\/b>/gsxi;
	    $template=~s/\%\%links\:\($tmpchart\)\%\%/$linksmap{$topic}/gsxi;
    }

    my $all;
    foreach $chart (sort keys %charts)
    {
        print "Chart $chart <br>\n" if ($DEBUG);
        $tmpchart = $chart;
        $tmpchart=~s/\s+/\\s\+/g;
        $topic = $topicname{$chart};
      	$all.="$charts{$chart}";	
        $template=~s/\%\%countrychart\:\($tmpchart\)\%\%/$charts{$chart}/gsxi;
        $template=~s/\%\%intro\:\($tmpchart\)\%\%/<small>$topicintro{$topic}<\/small>/gsxi;
        $template=~s/\%\%topic\:\($tmpchart\)\%\%/&nbsp;<b>$topicname{$chart}<\/b>/gsxi;
        $template=~s/\%\%links\:\($tmpchart\)\%\%/$linksmap{$topic}/gsxi;
    }
    $template=~s/\%\%countrychart\:all\%\%/$all/g;

    @html = ();
    $template=~s/\%\%countryname\%\%/<h1>$country<\/h1>/gsxi;
    push(@html, $template);

    foreach $string (@templatehtml)
    {
	    $string=~s/\%\%countryname\%\%/<h1>$country<\/h1>/g;
    }

  }

if ($dbh && $stop)
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

    %columns = ("A", 1, "F", 2, "M", 3, "S", 4);
    $basicletter = "A";
    foreach $country (sort keys %countries)
    {
	    my $id = $country2id{$country};
	    print "$country $country2id{$country}\n" if ($DEBUG);
      $countryblock.="<tr class=\"alt\" style=\"cursor: pointer;\" id=\"$id\">";

	    $currentletter = $startletter || 'A';
	    if ($country=~/^(\w)/)
	    {
	        $startletter = $1;
	    }

	    if ($columns{$startletter})
	    {
	      unless ($done{$startletter})
	      {
		      if ($basicletter ne 'A')
		      {
            $countrypage.="</td>\n";
	       	}
          $countrypage.="<td width=\"25%\">\n";	
          $done{$startletter} = "done";
	        $blockid++;
	      }
	    }

	    if (($startletter ne $currentletter) || $blockid < 2)
	    {
	       $basicletter = $startletter;
	       $countrypage.="</ul></div>\n" if ($startletter ne 'A');
	       $countrypage.="\n<div class=\"letter\"><div class=\"startletter\">$startletter</div>\n<ul>\n";
	       $blockid++;
	    }

	    $countrypage.="<li><a href=\"/$countrylink?country=$countryids{$country}\">$country</a></li>\n";
    }
    $countrypage.="</ul></div></td>";

    $countrypage = '<div class="datasets countrypage">' . $countrypage . '</div>';

    %indicators = %datasets;
    foreach $indicator (sort keys %indicators)
    {
	    print "$indicator $indicators{$indicator}\n" if ($DEBUG);
	    my $ind_id = $indicators{$indicator};
	    if ($indicator=~/\w+/)
	    {
	      $indicatorsblock.="<input type=\"checkbox\" name=\"indicator$ind_id\" value=\"$indicator\"> $indicator<br>";
	    };
    }

    foreach $topic (sort keys %topics)
    {
        my $topic_id = $topics{$topic};
      	if ($topic)
      	{
          $topicsblock.="<input type=\"checkbox\" name=\"topic$topic_id\" value=\"$topic\"> $topic<br>";
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

	    if ($year=~/00/)
	    {
	        $yearsblock.="<input type=\"checkbox\" name=\"years$year_id\" value=\"$year\"> $year<br>";
	    };
    }
  };

my $regionsblock;
foreach $mainregion (sort keys %mainregions)
{
   my $reg_id = $mainregions{$mainregion};
   print "$mainregion $reg_id\n" if ($DEBUG);
   $regionsblock.="<input type=\"checkbox\" name=\"region$reg_id\" value=\"$mainregion\"> $mainregion<br>";

   foreach $region (sort keys %regions)
   {
     my $root = $root4regions{$region};
    	if ($root eq $reg_id)
    	{
   	    print "$region $regions{$region} ROOT$root\n" if ($DEBUG);
  	    $regionsblock.="&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"checkbox\" name=\"region$regions{$region}\" value=\"$region\">&nbsp;$region<br>";
   
	      foreach $country (sort keys %countries)
   	    {
      		print "		$country $country2region{$country}\n" if ($country2region{$country} eq $regions{$region} && $DEBUG);
      		if ($country2region{$country} eq $regions{$region})
      		{
    		   $regionsblock.="&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"checkbox\" name=\"country$id\" value=\"$country\">&nbsp;$country<br>";
      		};
     	  }
	    }
   } 
};

($filterstring, %filter) = getparams($uri);
foreach $string (@html)
{
    $string=~s/\%\%countriesblock\%\%/$countrypage/gsxi;
    $string=~s/\%\%indicatorsblock\%\%/$indicatorsblock/gsxi;
    $string=~s/\%\%yearsblock\%\%/$yearsblock/gsxi;
    $string=~s/\%\%topicsblock\%\%/$topicsblock/gsxi;
    $string=~s/\%\%filterstring\%\%/$filterstring/gsxi;

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
	    $chartlink = "$site/$indicatorlink?$filterquery";
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
