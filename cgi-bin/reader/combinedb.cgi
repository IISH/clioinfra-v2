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
my $uri = $ARGV[0] || $ENV{'REQUEST_URI'};
my $charttype = $ARGV[1];

print $q->header( "text/html" );
$topic = $q->param('topic');
$indicator = $q->param('indicator');
$author = $q->param('author');
$country = $q->param('country');
$region = $q->param('region');
$html++;

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

#my %dbconfig = loadconfig("$Bin/../clioinfra.config");
my %dbconfig = loadconfig("$Bin/../clioinfra.config");
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
$head = 1;
use Getopt::Long;
$DIR = "/home/www/clio_infra/clioinfra";

unless ($indicator)
{
my $result = GetOptions(
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
    'region=s' => \$region
);
};

$author = "default" unless ($author);

if ($dbh)
{
    %codes = loadcodes($dbh);
    $country_id = $codes{$country} if ($country);
    %regions = loadregions($dbh);
    %regionsR = reverse %regions;
    %topics = loadtopics($dbh, $topic);
    %topicsR = reverse %topics;
    %indicators = loadindicators($dbh, $indicator);
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

if ($dbh)
{
    # find dataset
    $dataset_name = "$topic: $indicator";
    $dbh->quote($dataset_name);
    #print "$uri <br/>$sql<br />\n";
    $sql = generate_sqlquery($uri);

    if ($uri || $ind_id)
    {
        print "[DEBUG2] $ind_id\n" if ($DEBUG);
        my ($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);

        unless ($thisdataset)
        {
	print "Error: dataset not found: $indicator $ind_id $thisdataset\n"; exit(0);
        }
        else
        {
	print "Dataset# $thisdataset\n"; # if ($DEBUG);
	print "<br />" if ($html);
        }

        $dataset_id = $thisdataset;
    }
};

foreach $indicator (sort keys %filterdatasets)
{
     my $dataset_id = $datasets{$indicator};
     print "$indicator $datasets{$indicator}<br>\n" if ($DEBUG);

     if ($dataset_id)
     {
	print "<b>$indicator</b><br/>";
        combine_datasets($dbh, $showindicators{$indicator}, $dataset_id, $sql);
     };
}

sub combine_datasets
{
    my ($dbh, $ind_id, $dataset_id, $filter, $DEBUG) = @_;
    my ($values, $years, $max, $countriescount);

    $sqlquery = "select ind_value_int, ind_value_float, year_id, country_id, region_id from datasets.indicator_values where 1=1";
    $sqlquery.=" and dataset_id=$dataset_id" if ($dataset_id);
    $sqlquery.=" and ind_id=$ind_id" unless ($dataset_id);
    $sqlquery.=" $filter" if ($filter);
    $sqlquery.=" order by year_id asc";
    print "$sqlquery\n";
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
	print "[$year] $countryname $ind_value_float\n";
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
	print "<br />" if ($html);
    }

    if ($charttype!~/line/i)
    {
	$values=~s/\,\s*$//g;
	$years=~s/\,\s*$//g;
	$max=$max + $max * 0.1;
	print "[CHART values] $values\n";
	print "[CHART years] $years\n";
	print "[CHART max] $max\n";
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
	   if ($values)
	   {
               print "[$country COUNTRY values] $values\n";
               print "[$country COUNTRY years] $yearsline \n";
	   }
	}
	};

	$max=$max + $max * 0.1;
	print "[CHART max] $max\n";
	print "[CHART years] $yearsline\n";
    }

    print "$sqlquery\n" if ($DEBUG);
    return;
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

sub loaddatasets
{
    my ($dbh, $DEBUG) = @_;
    my %datasets;

    $sqlquery = "select dataset_name, dataset_id from datasets.datasets order by dataset_id desc";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_name, $dataset_id) = $sth->fetchrow_array())
    {
        $datasets{$dataset_name} = $dataset_id if ($dataset_id && !$datasets{$dataset_name});
    };

    exit(0) if ($DEBUG);

    return %datasets;
}

sub loadregions
{
    my ($dbh, $DEBUG) = @_;

    $sqlquery = "select region_name, region_id from datasets.regions";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($region, $region_id) = $sth->fetchrow_array())
    {
        $regions{$region} = $region_id if ($region_id);
        print "$region;;$region_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    return %regions;
}

sub loadindicators
{
    my ($dbh, $thisindicator, $DEBUG) = @_;
    my %indicators;

    $sqlquery = "select indicator_name, indicator_id from datasets.indicators";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($indicator_name, $indicator_id) = $sth->fetchrow_array())
    {
        $indicators{$indicator_name} = $indicator_id if ($indicator_id);
        print "$indicator_name;;$indicator_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    unless ($indicators{$thisindicator})
    {
        $dbh->do("insert into datasets.indicators (indicator_name, indicator_description) values ('$thisindicator', '')");
        %topics = loadtopics($dbh, $thisindicator);
    }

    return %indicators;
}


sub loadyears
{
    my ($dbh, @years, $DEBUG) = @_;
    my (%years, $changes);

    $sqlquery = "select year_value, year_id from datasets.years";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($year, $year_id) = $sth->fetchrow_array())
    {
        $years{$year} = $year_id if ($year_id);
        print "$year;;$year_id\n" if ($DEBUG);
    };

    foreach $year (@years)
    {
	if ($year=~/^\d+/)
	{
	    unless ($years{$year})
	    {
	        $dbh->do("insert into datasets.years (year_value) values ($year)");
	        $changes++;
	    }
	};
    }

    %years = loadyears($dbh, @years) if ($changes);
    exit(0) if ($DEBUG);

    return %years;

}

sub find_dataset
{
    my ($dbh, $ind_id, $topic_id, $dataset_name, $author, $filter, $DEBUG) = @_;
    my ($thisdataset_id, $thisrevision);

    $dataset_name=~s/^\:\s*//gsxi;
    $sqlquery = "select dataset_id, revision from datasets.datasets where 1=1";
    $sqlquery.=" and dataset_name='$dataset_name'" if ($dataset_name);
    $sqlquery.=" and author='$author'" if ($author!~/default/i);
    $sqlquery.=" and $filter" if ($filter);
#    $sqlquery.=" and indicator_id=$ind_id" if ($ind_id);
    $sqlquery.=" and topic_id=$topic_id" if ($topic_id);
    $sqlquery.=" order by dataset_id desc limit 1";

    $DEBUG = 1;
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
        $config{$name} = $value;
    }
    close(conf);

    return %config;
}

sub generate_sqlquery
{
   my ($uri, $DEBUG) = @_;
   my ($sqlquery, $indquery, $yearquery, $countryquery, $topicquery, $regionquery);

   $uri=~s/^.+?cgi\?//gi;
   if ($uri=~/\w+/)
   {
      my @filters = split(/\&/, $uri);
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

    #print "SQL $sqlquery <br />";
    return $sqlquery;
}
