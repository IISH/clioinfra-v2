#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/libs";

use DB_File;
use DBI;
$| = 1;

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

#my %dbconfig = loadconfig("$Bin/db.config");
my %dbconfig = loadconfig("$Bin/../clioinfra.config");
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
$head = 1;
use Getopt::Long;
$DIR = "/home/www/clio_infra/clioinfra";

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
    'country=s' => \$country,
    'region=s' => \$region
);

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

    $ind_id = $indicators{$indicator} if ($indicator);
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

    if ($DEBUG)
    {
        print "[DEBUG] $code $country_id $region_id $ind_id => $topic_id\n"; exit(0);
    };
}

if ($dbh)
{
    # find dataset
    $dataset_name = "$topic: $indicator";
    $dbh->quote($dataset_name);
    my ($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);

    unless ($thisdataset)
    {
	print "Error: dataset not found: $thisdataset\n"; exit(0);
    }
    else
    {
	print "Found: $thisdataset\n"; # if ($DEBUG);
    }

    $dataset_id = $thisdataset;
};

%years = loadyears($dbh, @years);
%yearsR = reverse %years;

if ($dbh)
{
    combine_datasets($dbh, $dataset_id);
}

sub combine_datasets
{
    my ($dbh, $dataset_id, $DEBUG) = @_;

    $sqlquery = "select ind_value_int, ind_value_float, year_id, country_id, region_id from indicator_values where 1=1";
    $sqlquery.=" and dataset_id=$dataset_id" if ($dataset_id);
    $sqlquery.=" and country_id=$country_id" if ($country_id); 
    $sqlquery.=" and region_id=$region_id" if ($region_id);
    $sqlquery.=" and year_id=$year_id" if ($year_id); 
    $sqlquery.=" order by year_id asc";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($ind_value_int, $ind_value_float, $year_id, $country_id, $region_id) = $sth->fetchrow_array())
    {
	my ($year, $countrycode, $regionname) = ($yearsR{$year_id}, $country2idR{$country_id}, $regionsR{$country2region{$country2idR{$country_id}}});
	my ($countryname) = ($countrynames{$country_id});
	print "[$year] $region_id [$countryname]: $ind_value_float\n";
    }

    print "$sqlquery\n";
    exit(0);
}

sub loadcodes
{
    my ($dbh, $DEBUG) = @_;
    my %codes;
    $DEBUG = 0;

    $sqlquery = "select country_name, country_code, country_id, region_id from countries";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($country, $code, $country_id, $region_id) = $sth->fetchrow_array())
    {
        $codes{$country} = $code if ($code);
	$country2id{$code} = $country_id;
	$countrynames{$country_id} = $country;
	$country2region{$code} = $region_id;

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

sub loadregions
{
    my ($dbh, $DEBUG) = @_;

    $sqlquery = "select region_name, region_id from regions";
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

sub loadtopics
{
    my ($dbh, $thistopic, $DEBUG) = @_;

    $sqlquery = "select topic_name, topic_id from topics";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($topic, $topic_id) = $sth->fetchrow_array())
    {
        $topics{$topic} = $topic_id if ($topic_id);
        print "$topic;;$topic_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    unless ($topics{$thistopic})
    {
	$dbh->do("insert into topics (topic_name, description) values ('$thistopic', '')");
	print "$thistopic\n";
	%topics = loadtopics($dbh, $thistopic);
    }

    return %topics;

}

sub loadindicators
{
    my ($dbh, $thisindicator, $DEBUG) = @_;
    my %indicators;

    $sqlquery = "select indicator_name, indicator_id from indicators";
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
        $dbh->do("insert into indicators (indicator_name, indicator_description) values ('$thisindicator', '')");
        %topics = loadtopics($dbh, $thisindicator);
    }

    return %indicators;
}


sub loadyears
{
    my ($dbh, @years, $DEBUG) = @_;
    my (%years, $changes);

    $sqlquery = "select year_value, year_id from years";
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
	        $dbh->do("insert into years (year_value) values ($year)");
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
    my ($dbh, $ind_id, $topic_id, $dataset_name, $author, $DEBUG) = @_;
    my ($thisdataset_id, $thisrevision);

    $sqlquery = "select dataset_id, revision from datasets where 1=1";
    $sqlquery.=" and dataset_name='$dataset_name'" if ($dataset_name);
    $sqlquery.=" and author='$author'" if ($author);
    $sqlquery.=" and indicator_id=$ind_id" if ($ind_id);
    $sqlquery.=" and topic_id=$topic_id" if ($topic_id);
    $sqlquery.=" order by dataset_id desc limit 1";

    #print "$sqlquery\n";exit(0);
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
