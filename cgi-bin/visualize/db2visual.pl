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
use Statistics::R;
my $R = Statistics::R->new();

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
    'dataset=s' => \$dataset_name
);

$filter = "United";
$author = "default" unless ($author);

if ($dbh)
{
    ($codeshash, $country2idhash, $country2regionhash) = loadcodes($dbh);

    %codes = %{$codeshash} if ($codeshash);
    %country2id = %{$country2idhash} if ($country2idhash);
    $country2region = %{$country2regionhash} if ($country2regionhash);

    %regions = loadregions($dbh);
    %topics = loadtopics($dbh, $topic);
    %years = loadyears($dbh);
    %id2year = reverse %years;
    %indicators = loadindicators($dbh, $indicator);

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    $topic_id = 1 unless ($topic_id);

    if ($dataset_name)
    {
	($dataset_id, $revision) = loaddatasetinfo($dbh, $dataset_name);
    }

    if ($DEBUG)
    {
    #    print "$ind_id => $topic_id\n"; exit(0);
    };
}

@template = load_csv_template("$Bin/../templates/clio2statplanet.tmpl");
my $scale;
if ($dataset_id)
{
    ($type, $min, $max, $up, $arrayhash, %datasetvalues) = loading_dataset_values($dbh, $dataset_id, 0, %id2year);
    print "[DEBUG] Calculating scale...\n" if ($DEBUG);
    my @scales = load_scales($dbh, $dataset_id);
    print "[DEBUG] @scales $#scales\n" if ($DEBUG);

    my @result;
    if ($#scales < 0 && $arrayhash)
    {
        @result = calculate_scales($R, $arrayhash);
       #@result = (1.00009360395501, 2.91648, 5.243803, 7.897912, 13.1143799427401);
        if ($DEBUG)
        {
           print "$datset_id Scale: @result\n";
        };

	my $scalestr = "@result";
	update_scales($dbh, $dataset_id, $scalestr) if ($scalestr);
    }
    else
    {
	@result = @scales;
    }
    #exit(0);

    $step = int($max / 5);
    print "$min => $max [$up] $step\n" if ($DEBUG); 
    # 0=[0xBD0026][10000] 1=[0xF03B20][8000] 2=[0xFD8D3C][6000] 3=[0xFEB24C][4000] 4=[0xFED976][2000] 5=[0xFFFFB2]
    %colors = ("0", "0xBD0026", 1, "0xF03B20", 2, "0xFD8D3C", 3, "0xFEB24C", 4, "0xFED976", 5, "0xFFFFB2");
    my $k = 0;
    for ($i=5; $i>=1; $i--)
    {
	my ($step2, $step1) = ($step * ($i+1), $step * ($i));
	print "$step1 <=> $step2\n" if ($DEBUG);
	$step1round = diground($step1);
	$step1round = $step1 if ($step1 < 10);

	my $step1median;
	$step1round = '0';
	$step1median = $result[$i-1] if ($result[$i-1]);
	$step1round = $step1median;
	$step1round = diground($step1median) if ($step1median > 10);
	$step1round = '0' unless ($step1round);
	$scale.=$k."=[$colors{$k}][$step1round] ";
	$k++;
    }
};

foreach $item (@template)
{
    $item=~s/\r|\n//gsxi;
    if ($item=~s/Variable\s+Name/$dataset_name Scale:$scale/g)
    {
	print "$item\n";
    };
    my @columns = split(/\|/, $item);
    my $column_name = $columns[0];
    my ($country_id, $thiscountry);

    if ($column_name=~/\d+/)
    {
	($country_id, $thiscountry) = ($columns[0], $columns[1]);
    }
    elsif ($column_name=~/Code/i)
    {
	shift @columns;
	shift @columns;
	@allyears = @columns;
	print "$item\n";
    }
    
    # $dataset{$country_id}{$year_id}{valint}
    my $countryline;
    if ($thiscountry)
    {
	%dataset = %{$datasetvalues{$country_id}};

	foreach $year (@allyears)
	{
	    my $value = $dataset{$year}{valint};
	    my $valuefloat = $dataset{$year}{valfloat};
	    $value.="($year)" if ($value && $DEBUGVAL); 

	    $value = $valuefloat if ($type eq 'float');
	    $countryline.="$value|";
	}

	print "$country_id|$thiscountry|$countryline\n";
    }
}
exit(0);

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
	$val=~s/\.\d+//g;
	$outstring.="$val" if ($val);
	$outstring.=",";

	if ($val)
	{
	   $val = 32000 if ($val > 32000);

	   ($ind_value_int, $ind_value_float) = ($val, $val);
	   $ind_value_int = int($val);
	   $ind_value_float = $val if ($val=~/[.,]/);

	   $insert = "insert into indicator_values (ind_id, year_id, country_id, region_id, dataset_id, ind_value_int, ind_value_float) values ($ind_id, $year_id, $country_id, $region_id, $dataset_id, '$ind_value_int', '$ind_value_float')";
	   $dbh->do($insert);
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

print "$inserted row(s)\n";
sub diground
{
    my ($digit, $DEBUG) = @_;
    my ($round, $c, $i);

    while ($digit > 1)
    {
      $digit = $digit / 10;
      $round = sprintf("%.2f", $digit);
      $c++;
      print "$c $digit $round\n" if ($DEBUG);
    }

    if ($round)
    {
        for ($i=1; $i<=$c; $i++)
        {
            $round = $round * 10;
        }
        print "$round\n" if ($DEBUG);
    }

    return $round;
};

sub calculate_scales
{
   my ($R, $arrayhash) = @_;
   my ($min, $qt1, $median, $qt2, $max, @array, @log);
   my $LOG;
   my $DEBUG = 0;

   @array = @$arrayhash if ($arrayhash);
   $LOG = 1 if (int($max) > 10000);
   $LOG = 0;

   # Step 1 Sort
   @sort = sort {$a <=> $b} @array;
   my ($min, $max) = ($sort[0], $sort[$#sort]);
   if ($DEBUG)
   {
      print "$min <=> $max\n"; #exit(0);
   };

   if ($LOG)
   {
       @sort = sort {$a <=> $b} @array;
   foreach $value (@sort)
   {
	if ($value)
	{
        $ln = log($value);
        push(@log, $ln);
        my $back = exp($ln);
	};
#        print "$value => $ln $back\n";
   }

       @sort = @log;
   }

   $R->set( 'x0', \@sort );

   $function = "median";
   #$function = "mean";
   $middle = $R->run( qq`$function(x0)` );
   $middle=~s/\s*\[\S+\]\s*//g;
#   print "$median\n";

   my ($set1hash, $set2hash) = create_array($middle, @sort);
   @set1 = @$set1hash;
   @set2 = @$set2hash;

   if ($#set1)
   {
       print "Set1 @set1\n" if ($DEBUG);
       $R->set( 'x1', \@set1 );
       $qt1 = $R->run( qq`$function(x1)` );
       $qt1=~s/\s*\[\S+\]\s*//g;
   };

   if ($#set2)
   {
       print "Set2 @set2\n" if ($DEBUG);
       $R->set( 'x2', \@set2 );
       $qt2 = $R->run( qq`$function(x2)` );
       $qt2=~s/\s*\[\S+\]\s*//g;
   };
   #print "@set2\n";

   $minid = ($min + $min / 2) || '0.1';
   $maxid = (($max + $qt2) / 2);

   if ($LOG)
   {
        @result = (exp($min), exp($qt1), exp($middle), exp($qt2), exp($max));
   }
   else
   {
	@result = ($min, $qt1, $middle, $qt2, $max); #, $max);
	if ($DEBUG)
	{
	   print "@result\n"; exit(0);
	}
   }

   foreach $val (@result)
   {
   #     $val = int($val);
   }
   return @result;
   #return ($min, $qt1, $median, $qt2, $max);
};


sub create_array
{
   my ($median, @array) = @_;
   my (@set1, @set2);

   for ($i=0; $i<=$#array; $i++)
   {
        my $value = $array[$i];
        print "[DEBUG] $value *$median*\n" if ($DEBUG);
        if ($value <= $median)
        {
            push(@set1, $value);
        }
        else
        {
            push(@set2, $value);
        }
   }

   return (\@set1, \@set2);
}
