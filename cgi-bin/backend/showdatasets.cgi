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
    'dataset=s' => \$dataset
);

$filter = "United";
$author = "default" unless ($author);

if ($dbh)
{
    %codes = loadcodes($dbh);
    %regions = loadregions($dbh);
    %topics = loadtopics($dbh, $topic);
    %indicators = loadindicators($dbh, $indicator);

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    $topic_id = 1 unless ($topic_id);

    if ($DEBUG)
    {
        print "$ind_id => $topic_id\n"; exit(0);
    };
}

foreach $topic (sort keys %topics)
{
   print "$topic $topics{$topic}\n";
}
# Store meta information about dataset
if ($dbh && $go)
{
    # find dataset
    $dataset_name = $dataset;
    $dataset_name = "$topic: $indicator" unless ($dataset_name);
    $dbh->quote($dataset_name);
    my ($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);

    unless ($thisdataset)
    {
	$q_dataset_name = $dbh->quote($dataset_name);
        $dbh->do("insert into datasets (revision, dataset_name, dataset_description, create_date, edit_date, topic_id, indicator_id, author) values ('0.1', $q_dataset_name, '$dataset_description', '$create_date', '$edit_date', '$topic_id', $ind_id, '$author')");

	($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);
	#print "Found: $thisdataset\n"; exit(0);
    }
    else
    {
        $q_dataset_name = $dbh->quote($dataset_name);
	$revision=~s/\S+\.//g;
	$revision++;
        $dbh->do("insert into datasets (revision, dataset_name, dataset_description, create_date, edit_date, topic_id, indicator_id, author) values ('0.$revision', $q_dataset_name, '$dataset_description', '$create_date', '$edit_date', '$topic_id', $ind_id, '$author')");
	($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);
	print "Found: $thisdataset\n" if ($DEBUG);
    }

    $dataset_id = $thisdataset;
};

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
	$country2region{$code} = $region_id;

        print "$code;;$country\n" if ($DEBUG);
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
        $topics{$topic} = $topic_id if ($topic_id && $topic);
        print "$topic;;$topic_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    if ($thistopic && !$topics{$thistopic})
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
