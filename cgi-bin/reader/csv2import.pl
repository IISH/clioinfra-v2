#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";

use DB_File;
use DBI;
use ClioInfra;
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
    'excelfile=s' => \$excelfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'output=s' => \$output,
    'link=s' => \$link,
    'source=s' => \$source,
    'debug=i' => \$DEBUG,
    'author=s' => \$author,
    'dataset=s' => \$dataset,
    'paper=s' => \$paper,
    'provider=s' => \$provider
);

$paper=~s/\-provider//g;
if ($excelfile)
{
     if ($excelfile=~/^(\S+)\/(\S+)$/)
     {
	$tmpdir = $1;
	$tmpfile = $2;
     }

     $csvfile = "$tmpdir/$tmpfile.csv.tmp";
     if ($excelfile=~/\.xlsx$/)
     {
         $convertxlsx = "$Bin/../../cgi-bin/bin/xlsx2csv.py -d '|' \"$excelfile\" > $tmpdir/$tmpfile.csv.tmp";
         $convert = `$convertxlsx`;
         print "$convertxlsx\n";
     }
     elsif ($excelfile=~/\.xls$/)
     {
         $convertxls="/usr/local/bin/xls2csv \"$excelfile\" -c '|'> $tmpdir/$tmpfile.csv.tmp";
         print "$convertxls\n";
         $convert = `$convertxls`;
     }
}

$filter = "United";
$author = "default" unless ($author);

if ($dbh)
{
    %codes = loadcodes($dbh);
    %regions = loadregions($dbh);
    %topics = loadtopics($dbh, $topic);
    %indicators = loadindicators($dbh, $indicator);
    $provider_id = find_provider($dbh, $provider);

    $ind_id = $indicators{$indicator} if ($indicator);
    #$ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    #$topic_id = 1 unless ($topic_id);

    if ($DEBUG)
    {
        print "$ind_id => $topic_id\n"; exit(0);
    };
}

if ($DEBUG)
{
   print "DEBUG $csvfile\n";
}

$topic=~s/^\s*\-\s*//g;
$topic = "Category AB" unless ($topic);
$indicator = "Sub-Category Example A-111" unless ($indicator);
$link = "<a href=\"$link\">$source</a>" if ($link && $source);
$step = 2000;

open(csvfile, $csvfile);
@content = <csvfile>;
close(csvfile);

$field = 1;

# Load csv dataset
for ($i=0; $i<=$#content; $i++)
{
   my $str = $content[$i];
   $str=~s/\r//g;
   $str=~s/\"//g;
   my $blank;
   $str=~s/|\n//g;
   my $true = 1;
   $true = 0 if ($str!~/\w+/);
   if ($true)
   {
	# Find dates
	my @data = split(/\s*\|\s*/, $str);
	foreach $date (@data)
	{
	   $year{$i}++ if ($date=~/^\d+$/);
	}

	unless ($str=~s/^(\d+\||Code\|)//)
	{
	    $str=~s/^\|//g;
	}

	$dataset[$i] = $str;
	print "$i $str\n" if ($DEBUG);
   }
}

# Find string with year
foreach $i (sort {$year{$b} <=> $year{$a}} keys %year)
{
    unless ($yearstring)
    {
	$yearstring = $i;
	print "[DEBUG YEAR] $yearstring\n" if ($DEBUG);
    }
}

# Store meta information about dataset
if ($dbh)
{
    # find dataset
    $dataset_name = $dataset;
    $dataset_name = "$indicator" unless ($dataset_name);
    $dbh->quote($dataset_name);
    my ($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);
    $dataset_description = $paper if ($paper);
    $topic_id = $topics{$topic} unless ($topic_id);
    $provider_id = "0" unless ($provider_id);

    unless ($thisdataset)
    {
	$q_dataset_name = $dbh->quote($dataset_name);
        $dbh->do("insert into datasets.datasets (revision, dataset_name, dataset_description, create_date, edit_date, topic_id, indicator_id, author, provider_id) values ('0.1', $q_dataset_name, '$dataset_description', '$create_date', '$edit_date', '$topic_id', $ind_id, '$author', '$provider_id')");

	($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);
	#print "Found: $thisdataset\n"; exit(0);
    }
    else
    {
        $q_dataset_name = $dbh->quote($dataset_name);
	$revision=~s/\S+\.//g;
	$revision++;
        $dbh->do("insert into datasets.datasets (revision, dataset_name, dataset_description, create_date, edit_date, topic_id, indicator_id, author, provider_id) values ('0.$revision', $q_dataset_name, '$dataset_description', '$create_date', '$edit_date', '$topic_id', $ind_id, '$author', '$provider_id')");
	($thisdataset, $revision) = find_dataset($dbh, $ind_id, $topic_id, $dataset_name, $author);
	print "Found: $thisdataset\n" if ($DEBUG);
    }

    $dataset_id = $thisdataset;
};

my $DEBUG = 0;
for ($i=0; $i<=$#dataset; $i++)
{
   my $str = $dataset[$i];
   $str=~s/^\|\"/\"\|\"/g;
   $str=~s/\"$//g;
#   print "[DEBUG] $str\n" if ($DEBUG);

   my @items = split(/\|/, $str);
   foreach $item (@items)
   {
	$item=~s/^\s*\"\s*|\"\s*$//g;
	$blank++ if ($item!~/\d+/);
   }

   if ($i eq $yearstring)
   {
	print "[$i] $str\n" if ($DEBUG);
	@years = split(/\|/, $str);
	$report++;
#	print "[DEBUG YEARS] @years\n" if ($DEBUG);
   }
   else
   {
	# "Latvia "||||||||||||||||||||||"1936.498"|"2115.183"|"2361.159"|"2524.543"|"2663.59"|"2376.178"|
	my $country = $items[0];
	$country=~s/^\s+|\s+$//g;
	my $code = $codes{$country};
#	print "CODE [$country] $code => $codes{$country}\n";
	$country{$code} = $country;
	my ($thisyear, $thisfield);

	my $true = 1;
	#$true = 0 if ($filter && $country!~/$filter/i);

	if ($country!~/\d+/ && $str=~/\d+/ && $true)
	{
#	print "*$country [$code]*\n XXX $str\n";
	#print "$country;;$code;;\n" if ($filter);

	for ($j=1; $j<=$#items; $j++)
	{
	    my $thisyear = $years[$j];
	    my $thisval = $items[$j];

	    print "[D] $j $thisyear $thisval\n" if ($DEBUG);
	    if ($report == 1 && $thisval)
	    {
	 	#print "$thisyear => $thisval\n" if ($filter);
	        $yearrating{$thisyear} = $thisyear;
	        $val{$code}{$thisyear} = int($thisval);
		$val{$code}{$thisyear} = $thisval;
	    };
	}

	};
   }

}

%years = loadyears($dbh, @years);

foreach $code (@order)
{
   print "$code," if ($DEBUG);
}

my $inserted;
open(output, ">$output") if ($output);
foreach $year (sort {$yearrating{$b} <=> $yearrating{$a}} keys %yearrating)
{
    my ($year_id) = ($years{$year});
    print "$year => $year_id\n" if ($DEBUG);

    #print "$year_id($year)\n";exit(0);
    my $outstring = "";
    $outstring = ",,$year,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
    #print "$outstring\n";
    $outstring = ",,,-,,,,,,,,,";
    foreach $code (@order)
    {
	my ($country_id, $region_id) = ($country2id{$code}, $country2region{$code});
	#print "$country_id $region_id => $code\n";exit(0);

	my $val = $val{$code}{$year};
	$val=~s/^\s+|\s+$//g;
	$outstring.="$val" if ($val);
	$outstring.=",";

	if ($val=~/\d+/ && $year)
	{
	   $val = 32000 if ($val > 32000 || $val=~/hyperinflation/i);

	   ($ind_value_int, $ind_value_float) = ($val, $val);
	   $ind_value_int = int($val);
	   $val=~s/^\s+|\s+$//g;
	   $val=~s/\,/\./g;
	   $ind_value_float = $val if ($val!~/\./);

	   $insert = "insert into datasets.indicator_values (ind_id, year_id, country_id, region_id, dataset_id, ind_value_int, ind_value_float) values ($ind_id, $year_id, $country_id, $region_id, $dataset_id, '$ind_value_int', '$ind_value_float')";
	   print "$insert => $year($year_id) $code $region_id\n" if ($DEBUG);
	   $dbh->do($insert) || die "$insert\n";
	   $inserted++;
	   #print "$insert\n"; exit(0);
	};
        #print "$code\n";
    }

    if ($output)
    {
         print output "$outstring\r\n" if ($outstring=~/\d+/);
    }
    else
    {
	print "$outstring\r\n" if ($outstring=~/\d+/);
    }
};
close(output) if ($output);

print "$inserted row(s) injested\n"; # if ($DEBUG);

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

sub loadtopics
{
    my ($dbh, $thistopic, $DEBUG) = @_;

    $sqlquery = "select topic_name, topic_id from datasets.topics";
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
	$dbh->do("insert into datasets.topics (topic_name, description) values ('$thistopic', '')");
	print "$thistopic\n";
	%topics = loadtopics($dbh, $thistopic);
    }

    return %topics;

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
        %indicators = loadindicators($dbh, $thisindicator);
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
    my ($dbh, $ind_id, $topic_id, $dataset_name, $author, $DEBUG) = @_;
    my ($thisdataset_id, $thisrevision);

    $sqlquery = "select dataset_id, revision from datasets.datasets where 1=1";
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
