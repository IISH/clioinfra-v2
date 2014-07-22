#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";

use DB_File;
use DBI;
use CGI;
use ClioInfra;
$| = 1;
my $q = new CGI;
my $uri = $ENV{'REQUEST_URI'};
my $charttype = $ARGV[1];

$topic = $q->param('topic');
$indicator = $q->param('indicator');
$author = $q->param('author');
$country = $q->param('country');
$region = $q->param('region');
$html++;

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my ($path, $root) = ($dbconfig{path}, $dbconfig{root});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
$head = 1;
use Getopt::Long;
#$DIR = "/home/www/clio_infra/clioinfra";

#unless ($indicator)
unless ($uri)
{
    $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'indicatorID=s' => \$indicatorID,
    'output=s' => \$output,
    'link=s' => \$link,
    'source=s' => \$source,
    'debug=i' => \$DEBUG,
    'author=s' => \$author,
    'country=s' => \$country,
    'region=s' => \$region,
    'uri=s' => \$uri,
    'excel=s' => \$excel,
    'zip=s' => \$zip,
    'showlink=s' => \$showlink
    );
}

$uri=~s/indicator\d+/indicator/g;
$uri=~s/\+/ /gsxi;

print $q->header( "text/html" ) unless ($showlink);

if ($uri=~s/excel\=(.+?\.xlsx)//)
{
    $excel = $1;
}
if ($uri=~s/zip\=(.+?)\.zip//)
{
    $excel = "$1.xlsx";
    $zip = $1;
    $zipfile = $zip;
}

$author = "default" unless ($author);

if ($dbh)
{
    %codes = loadcodes($dbh);
    $country_id = $codes{$country} if ($country);
    %regions = loadregions($dbh);
    %regionsR = reverse %regions;
    %topics = loadtopics($dbh, $topic, '', $DEBUG);
    %topicsR = reverse %topics;
    %indicators = loadindicators($dbh, $indicator, '', $DEBUG);
    %indicatorsR = reverse %indicators;
    %years = loadyears($dbh, @years);
    %datasets = loaddatasets($dbh);
    %yearsR = reverse %years;

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = $indicatorID if ($indicatorID);
    $topic_id = $topics{$topic} if ($topic);

    if ($country)
    {
	$code = $codes{$country};
	$country_id = $country2id{$code};
	%country2idR = reverse %country2id;
	$region_id = $country2region{$code}; 
	%country2regionR = reverse %country2regionR;

#	print "$country_id $country\n"; exit(0);
    }

    if ($region)
    {
	$region_id = $regions{$region};
#	print "$region_id => $region\n"; exit(0);
    }

    if ($DEBUG eq 1)
    {
        print "[DEBUG] $code $country_id $region_id $ind_id => $topic_id\n"; exit(0);
    };
}

if ($uri && $showlink)
{
    my @commands = split(/\&/, $uri);

    foreach $command (@commands)
    {
	my ($key, $value) = split(/\=/, $command);
	$params{$key}{$value} = $value;

	if ($key)
	{
  	   print "$key => $value\n" if ($DEBUG);
	   $selectedindicators{$value} = $value if ($key=~/indicator/i);
	};
    }
}

$selectedindicators{$indicator} = $indicator if ($indicator);

foreach $indicator (sort keys %selectedindicators)
{
    my $DEBUG = 0;
    # find dataset
    #$dataset_name = "$topic: $indicator";
    #$dbh->quote($dataset_name);
    #print "$uri <br/>$sql<br />\n";
    my $tmpuri = $uri;
    $tmpuri=~s/indicator\=(.+?)\&//gix;
    $tmpuri=~s/indicator\=(.+?)$//gix;
    $sql = generate_sqlquery("$tmpuri&indicator=$indicator");
    $SQL{$indicator} = $sql if ($sql);
    print "$indicator => $sql\n" if ($DEBUG); 

    if ($indicator)
    {
        print "[DEBUG2] $ind_id\n" if ($DEBUG);
	$dataset_name = $indicator;
        my ($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);

        unless ($thisdataset)
        {
	    print "Error: dataset $indicator not found: $indicator $ind_id $thisdataset\n"; 
        }
        else
        {
	    print "Dataset# $indicator $thisdataset $revision\n" if ($DEBUG);
	    $filterdatasets{$indicator} = $thisdataset;
	    #print "<br />" if ($html && $DEBUG);
        }

        $dataset_id = $thisdataset;
    }
};

$filterdatasets{$indicator} = $dataset_id unless ($showlink);

my $folder = "$path/zip";
$folder = "$path/datasets" if ($showlink);
$rm = `/bin/rm -rf $folder/*` if (-e $folder);
mkdir $folder unless (-d $folder);

foreach $indicator (sort keys %filterdatasets)
{
     my $dataset_id = $filterdatasets{$indicator} || $datasets{$indicator};
     print "$indicator $datasets{$indicator}<br>\n" if ($DEBUG);

     if ($dataset_id)
     {
	#print "<b>$indicator</b><br/>";
        $fulldataset = combine_datasets($dbh, $showindicators{$indicator}, $dataset_id, $SQL{$indicator});
	#$fulldataset=~s/\n/<br>\\n//g;
	unless ($excel)
	{
	    my @items = split(/\n/, $fulldataset);
	    foreach $string (@items)
	    {
		print "$string <br>\n";
	    }
	}
	else
	{
	    #$fulldataset=~s/\n/\|\|/gsxi;
	    #print "$Bin/csv2xlsx.pl --dataset '$fulldataset' > $Bin/dataset.test.csv <br>\n";
            my $tmpind = $indicator;
            $tmpind=~s/\W+//g;
            $excelfile = $tmpind;
	    $excel = $excelfile;

	    open(out, ">$Bin/tmp/$excelfile.csv");
	    print out "$fulldataset";
	    close(out);
	    #$makeexcel = `$Bin/csv2xlsx.pl --dataset '$fulldataset' --indicator '$indicator' --excelfile '$excel'`;

	    $makeexcel = "\n$Bin/csv2xlsx.pl --csvfile '$Bin/tmp/$excelfile.csv' --excelfile '$Bin/tmp/$excel.xlsx' --indicator '$indicator' --showlink yes";
            $makeexcel.=" --filter yes " if ($filtercountry);
	    #print "$makeexcel\n"; # if ($DEBUG);
	    $lastExcel = `$makeexcel`;
	    $laseExcel=~s/\r|\n//g;
	    #print "$Bin/csv2xlsx.pl --csvfile '$Bin/tmp/tmp' --excelfile '$excel'\n";
	    print "\nINDICATOR $indicator $dataset_id => $run\n" if ($DEBUG);
	
	    if ($zip)
	    {
		$excel = $lastExcel;
		$paper = getdescriptionfile($dbh, $indicator);
		#print "Paper $paper $path/$excel<br>"; 

		if ($paper)
		{
		    $cp = `/bin/cp $paper $folder/` if (-e $paper);
		};

		#$excel=~s/\W+//g;
		#$excel=~s/xlsx/\.xlsx/g;
		#print "$path/$excel\n";
		$cp = `/bin/cp $excel $folder/`;
		print "COPY /bin/cp $excel $folder/\n" if ($DEBUG);
	    }
	    else
	    {
		print "$makeexcel <br>\n";
	    }
	};
     };
}

if ($zip)
{
   my $DEBUG=1;

   $zipfile=~s/\W+//g;
   my $ziparc = "$path/zip2";
   my $urlpath = "$root/tmp/zip2";
   mkdir ($ziparc) unless (-e "$ziparc");
   $ziparc.="/$zipfile.zip";
   $rm = `/bin/rm -rf $ziparc`;
   #my $zip = `cd $folder;/usr/bin/zip -9 -y -r -q $ziparc ./`;
   #print "cd $folder;/usr/bin/zip -9 -y -r -q $ziparc ./\n" if ($DEBUG);
   # /usr/bin/zip -9 -y -r -q /home/www/clio_infra/8081/clioinfra/htdocs/tmp/zip2/zipfile.zip /home/www/clio_infra/8081/clioinfra/htdocs/tmp/datasets
   my $runzip = "cd $folder;/usr/bin/zip -9 -y -r -q $ziparc *";
   #print "$runzip\n";
   $zip = `$runzip`;
   unless ($showlink)
   {
   print "Download dataset with working paper in ZIP file: <a href=\"$root/tmp/zip/$zipfile.zip\">$zipfile.zip</a>";
   }
   else
   {
	print "$urlpath/$zipfile.zip";
   }

}

sub combine_datasets
{
    my ($dbh, $ind_id, $dataset_id, $filter, $DEBUG) = @_;
    my ($values, $years, $max, $countriescount, $fulldataset);

    $sqlquery = "select ind_value_int, ind_value_float, year_id, country_id, region_id from datasets.indicator_values where 1=1";
    $sqlquery.=" and dataset_id=$dataset_id" if ($dataset_id);
    $sqlquery.=" and ind_id=$ind_id" unless ($dataset_id);
    $sqlquery.=" $filter" if ($filter);
    $sqlquery.=" order by year_id asc";
    print "$sqlquery\n" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    if ($html)
    {
	#print "[YEAR] Country Value <br />\n";
    }

    my %activeyears;
    while (my ($ind_value_int, $ind_value_float, $year_id, $country_id, $region_id) = $sth->fetchrow_array())
    {
	my ($year, $countrycode, $regionname) = ($yearsR{$year_id}, $country2idR{$country_id}, $regionsR{$country2region{$country2idR{$country_id}}});
	my ($countryname) = ($countrynames{$country_id});
	my $mainvalue = $ind_value_float || $ind_value_int;
	$fulldataset.="$indicator%%$countryname%%$countrycode%%$year%%$mainvalue\n";
	#print "[$year] $countryname $ind_value_float\n";
	if ($ind_value_float > $max)
	{
	    $max = $ind_value_float;
	}

	$values.="$ind_value_float,";
	$years.="\"$year\",";

	if ($countryname)
	{
	   $countriescount++ if (!$values{$countryname});
	   $values{$countryname}{$year}{values}="$ind_value_float";
	   $years{$countryname}{years}.="\"$year\",";
	   $activeyears{$year} = $year if ($ind_value_float && $year>1950); # && $year < 2013);
	}
	print "<br />" if ($html && $DEBUG);
    }

    if ($charttype!~/line/i)
    {
	$values=~s/\,\s*$//g;
	$years=~s/\,\s*$//g;
	$max=$max + $max * 0.1;
	if ($DEBUG_CHART)
	{
	print "[CHART values] $values\n";
	print "[CHART years] $years\n";
	print "[CHART max] $max\n";
	}
    }

#    %activeyears = ("2000", 2000);
    my $yearsline;
    foreach $year (sort keys %activeyears)
    {
	$yearsline.="\"$year\",";
    }
    $yearsline=~s/\,$//g;

    if ($countriescount > 1)
    {
	my ($years, $values, $value, $max);
	foreach $country (sort keys %values)
	{
	   my $values;
	   foreach $year (sort keys %activeyears)
	   {
	 	$value = $values{$country}{$year}{values};
	 	if ($value)
	 	{
		   $values.="$value,";
		   if ($max < $value)
		   {
			$max = $value;
	 	   }
	 	}
		else
		{
		   $values.="0,";
		}
	   }

	if ($values)
	{
	   #$values.=~s/\,\d+$//g;
	   if ($values && $DEBUG_CHART)
	   {
               print "[$country COUNTRY values] $values\n";
               print "[$country COUNTRY years] $yearsline \n";
	   }
	}
	};

	$max=$max + $max * 0.1;
	if ($DEBUG_CHART)
	{
	print "[CHART max] $max\n";
	print "[CHART years] $yearsline\n";
	};
    }

    print "$sqlquery\n" if ($DEBUG);
    return $fulldataset;
}

sub loadcodes
{
    my ($dbh, $DEBUG) = @_;
    my %codes;
    $DEBUG = 0;

    $sqlquery = "select country_name, country_code, country_id, region_id from datasets.countries";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($country, $code, $country_id, $region_id) = $sth->fetchrow_array())
    {
        $codes{$country} = $code if ($code);
	$country2id{$code} = $country_id;
	$countrynames{$country_id} = $country;
	$country2region{$code} = $region_id;
	$country{$country} = $country_id;

        print "$code;;$country;;$country_id\n" if ($DEBUG);
        if ($code && !$known{$code}) # && (!$filter || $country=~/$filter/i))
        {
            push(@order, $code);
        }
        $known{$code}++;
    };

    exit(0) if ($DEBUG);
    return %codes;
}

sub find_dataset
{
    my ($dbh, $ind_id, $topic_id, $dataset_name, $author, $filter, $DEBUG) = @_;
    my ($thisdataset_id, $thisrevision);

    $dataset_name=~s/^\:\s*//gsxi;
    $sqlquery = "select dataset_id, revision from datasets.datasets where 1=1";
    $sqlquery.=" and dataset_name='$dataset_name'" if ($dataset_name && !$topic_id);
    $sqlquery.=" and author='$author'" if ($author!~/default/i);
    $sqlquery.=" and $filter" if ($filter);
#    $sqlquery.=" and indicator_id=$ind_id" if ($ind_id);
    $sqlquery.=" and topic_id=$topic_id" if ($topic_id);
    $sqlquery.=" order by dataset_id desc limit 1";

    #$DEBUG = 1;
    print "$sqlquery\n" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_id, $revision) = $sth->fetchrow_array())
    {
	$thisdataset_id = $dataset_id;
	$thisrevision = $revision;
    };

    return ($thisdataset_id, $thisrevision);
};

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
	$value=~s/^\s+|\s+$//g;
        $config{$name} = $value;
    }
    close(conf);

    return %config;
}

sub generate_sqlquery
{
   my ($uri, $DEBUG) = @_;
   my ($sqlquery, $indquery, $yearquery, $countryquery, $topicquery, $regionquery, %uriparams, $periodquery, $filterquery);

   $uri=~s/^.+?cgi\?//gi;
   if ($uri=~/\w+/)
   {
      my @filters = split(/\&/, $uri);
      foreach $param (@filters)
      {
          my ($name, $value) = split(/\=/, $param);
	  $uriparams{$name} = $value;
      };

      foreach $param (@filters)
      { 
	  my ($name, $value) = split(/\=/, $param);
	  #print "$name => $value <br />\n";
	  $name=~s/\%20/ /gsxi;
	  $value=~s/\%20/ /gsix;
	  $value=~s/\+/ /gsxi;
          $filter{$name} = $value;
          $filterstring.="$name => $value<br /> ";

          if ($name=~/indicator/)
          {
              	$filterquery.="$1=$value&";
		$filterdatasets{$value} = $value;

	 	if ($indicators{$value})
		{
	      	    #$indquery.="ind_id='$indicators{$value}' OR ";
		    $showindicators{$value} = $indicators{$value};
	 	}
          }
	  if ($name=~/country/)
	  {
		if ($country{$value})
		{
		    $countryquery.="country_id='$country{$value}' OR ";
		    $filtercountry++;
		}
	  }
	  if ($name=~/years/)
	  {
		#print "NAME $name $value $years{$value}  <br />\n";
		if ($years{$value})
		{
		    $yearquery.="year_id='$years{$value}' OR ";
		}
	  }
	  if ($name=~/region/)
	  {
		if ($regions{$value})
		{
		    $regionquery.="region_id='$regions{$value}' OR ";
		}
	  }
          else
          {
              $filterquery.="$name=$value&";
#	      $sqlquery.="$name='$value' and ";
          }
        
          if ($name=~/year\_from/ && $uriparams{'year_to'})
          {
                $periodquery.="year_id >= '$uriparams{'year_from'}' AND year_id <='$uriparams{'year_to'}' ";
          }

	  print "$name => $value <br>\n" if ($DEBUG);
      }
   };

    $sqlquery=~s/and\s*$//g;
    $indquery=~s/(OR|AND)\s*$//g;
    $countryquery=~s/(OR|AND)\s*$//g;
    $yearquery=~s/(OR|AND)\s*$//g;
    $regionquery=~s/(OR|AND)\s*$//g;

    $sqlquery=" AND ($indquery)" if ($indquery);
    $sqlquery.=" AND ($countryquery)" if ($countryquery);
    $sqlquery.=" AND ($yearquery)" if ($yearquery);
    $sqlquery.=" AND ($regionquery) " if ($regionquery);
    $sqlquery.=" AND ($periodquery) " if ($periodquery);

    #print "SQL $sqlquery <br />";
    return $sqlquery;
}
