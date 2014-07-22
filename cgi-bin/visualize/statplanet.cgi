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

$site = "http://beta.clio-infra.eu:8081";
$DIR = "/home/www/clio_infra/clioinfra";

$htmltemplate = "$Bin/../templates/statplanet.tpl";
@html = loadhtml($htmltemplate);

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$path = $dbconfig{path} || $Bin.'/../../htdocs/tmp';
$path=~s/\s+$//g;
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

$head = 1;
use Getopt::Long;

# http://beta.clio-infra.eu:8081/visualize?datasetfile=12NationalAccountsGDPpercapitaxlsx.csv
my $result = GetOptions(
    \%options,
    'datasetfile=s' => \$datasetfile,
    'datasetname=s' => \$datasetname,
    'alldatasets=s' => \$alldatasets,
    'rebuild=s' => \$rebuild,
    'debug=i' => \$DEBUG,
    'groupby=s' => \$groupby
);
$groupby = 1;
#$rebuild = 1;

$alldatasets = "yes" if (!$datasetfile && !$datasetname);
if ($datasetfile || $datasetname)
{
    $datasetfile = "/tmp/alldatasets.csv" if (!$datasetfile && !$datasetname);
    $datasetfile = makedatasetfile($datasetfile, $datasetname, $DEBUG) if ($datasetfile!~/\/tmp/);
}
elsif ($alldatasets)
{
    print "[DEBUG1] Load datasets...\n" if ($DEBUG);
    %datasets = loaddatasets($dbh);
    %topics = loadtopics($dbh, $topic);
    %rtopics = reverse %topics;
    %datasetmap = loaddatasets($dbh, 'showmap');
    $alldatasetsfile = $path."/alldata.csv";

    foreach $dataset (sort keys %datasets)
    {
	$icount++;
	my $enabled = 0;
	$enabled = 1 if ($dataset=~/Height|Cattle\s+per/i);
#	if ($icount < 3)

	if ($enabled)
	{
	my $topic = $rtopics{$datasetmap{$dataset}{topic_id}};
	$datasetfile = $dataset;
	$datasetfile=~s/\W+//g;
	print "[DEBUG1] $topic $dataset => $datasetfile <br> $path/$datasetfile.tmp\n" if ($DEBUG);

	print "$path/$datasetfile\n" if ($DEBUG);
	my $exists;
	#$rebuild = 1;
	unless ($rebuild)
	{
	   $exists = 1 if (-e "$path/$datasetfile");
	};

	unless ($exists) #unless (-e "$path/$datasetfile")
	{
	   $datasetfile = makedatasetfile($datasetfile, $dataset, $DEBUG);
	   $datasetfile=~s/\/tmp\///g;
	   print "New $path/$datasetfile\n" if ($DEBUG);
	   push(@files, "$path/$datasetfile");
	}
	else
	{
	   push(@files, "$path/$datasetfile");
	   print "Found $path/$datasetfile\n" if ($DEBUG);
	}
	$info{$datasetfile} = $dataset;
	$topicinfo{$topic}{$datasetfile}++;
	}
    }
    print "[DEBUG1] Complete\n" if ($DEBUG);

    foreach $topic (sort keys %topicinfo)
    {
	my %files = %{$topicinfo{$topic}};
	foreach $file (sort keys %files)
	{
	    print "D $path/$file<br>" if ($DEBUG);
	    push(@sorted, "$path/$file");
	}
    }

    $rm = `/bin/rm -rf $alldatasetsfile`;
    open(all, ">$alldatasetsfile");
    foreach $file (@sorted)
    {
	open(dataset, "$file");
	@data = <dataset>;
	close(dataset);

	#$cat = `/bin/cat $Bin/../../htdocs/$file >> $alldatasetsfile`;
	my ($strid, $activedataset);
	my $line = $data[0];
        if ($line=~/GLOBAL/sxi)
        {
           $activedataset++;
	   $datasetid++;
        }

	if ($#data < 10)
	{
	   $activedataset--;
	}

	if ($activedataset)
	{
	    my $active = 0;
	    my $strid++;
	    for ($i=0; $i<=$#data; $i++) #each $str (@data)
	    {
		my ($str, $strprev, $strnext) = ($data[$i], $data[$i-1], $data[$i+1]);
		my $maintopic = $topics{$info{$file}};
		my $thistopic;
		my $activeline = 1;
		if ($str=~/^\,(\w.+?)\,/)
		{
		   $thistopic = $1;	
		   if ($known{$thistopic})
		   {
#			$str=~s/^\,$thistopic\,\d+\,/\,\,\,/g;
	 	   }
		}

		$str=~s/\,Category\s+AB/$maintopic\,\,/sxi unless ($known{$maintopic});
		my @items = split(/\,/, $str);
		my ($global, $topic, $year, $indicator) = @items;
		$indicator=~s/\-/$lastindicator/gsxi if ($lastindicator); 

		$lasttopic = $topic if ($topic=~/\S+/ && !$indicator && $topic!~/CATEGORY/sxi); # && !$thistopic);
		if ($lasttopic)
		{
		    $lastyear = $year if ($year && $year=~/^\d+/);
		    $allyears{$lasttopic}{$lastyear}.="$str" if ($year);
		    $lastindicator = $indicator if ($indicator=~/\S+/ && $indicator ne '-' && $indicator!~/INDICATOR/i);
		    $alltopics{$lasttopic}{$lastindicator}{$lastyear} = $str if ($lastindicator=~/\S+/ && !$topic);
		    $topicstr{$lasttopic} = $str if ($lasttopic && !$topicstr{$lasttopic});
		};

		$known{$maintopic}++;

	#	print "$str";
        #        print "		TOPIC $topic *** $lasttopic-$lastyear DEBUG $global, $cat, YEAR:$year, IND: $lastindicator\n"; # if ($DEBUG);

#		$str=~s/Category\s+AB/$maintopic/sxi;
	 	if ($str=~/GLOBAL/sxi && $datasetid eq 1)
		{
		    $GLOBAL = $str;
		    $active++;
		}
		if ($str=~/GLOBAL/sxi && $datasetid>1)
                {
                    $activeline = 0;
                }
		if ($str!~/GLOBAL/sxi)
		{
		    $active = 1;
		}

		if ($str=~/Clio\s+/sxi)
		{
		   #$str=~s/^\,(.+?)\,/$1\,\,/g;
		}

		$activeline = 0 if ($thistopic && $known{$thistopic});
	        if ($activeline)
	        {
		    print all "$str" unless ($groupby);
	        }
	
	        $strid++;
		$strprev = $str;
		$known{$thistopic}++ if ($thistopic);
	    }
	};
    }

    if ($groupby)
    {
        print all "$GLOBAL";
        foreach $topic (sort keys %topics)
        {
	    $topicstr = $topicstr{$topic};
	    print "[DEBUG] $topic => TOPIC $topicstr" if ($DEBUG);
	    print all "$topicstr" if ($topicstr);
	    my %years = %{$allyears{$topic}};
	
	    foreach $year (reverse sort %years)
	    {
	   	#print "	YEAR: $year\n";
		my @items = split(/\,/, $topicstr);
		my $yearstring;
		for ($i=0; $i<=$#items; $i++)
		{
		    if ($i != 2)
		    {
		        $yearstring.=",";
		    }
		    else
		    {
			$yearstring.="$year,";
	  	    }
		}
#		print all "$yearstring\r\n" if ($alltopics{$topic});
		my %cat = %{$alltopics{$topic}};

		foreach $indicator (sort keys %cat)
		{
	    	    $str = $alltopics{$topic}{$indicator}{$year}; # $cat{$subcat};
		    my $outstring = $str;
		    $outstring=~s/$indicator//gsxi;
#		    $outstring=~s/$year\,/\-\,/g;
	    	    print "	$topic / $indicator / $year\n$str" if ($DEBUG);	

		    if ($outstring)
		    {
		       print all "$outstring" if ($str && $str!~/GLOBAL/i);
		    }
		    elsif ($str = $alltopics{$topic}{$indicator})
		    {
#			print all "$yearstring\r\n";
		    };
		}
	    }
        }
    };
    close(all);
    $datasetfile = "/tmp/alldata.csv";
}

unless ($datasetfile)
{
   $datasetfile = "/tmp/alldata.csv";
   $datasetfile = "/tmp/data_custom.csv";
   $datasetfile = "/tmp/stat_test.csv";
   #$datasetfile = "/tmp/test_data.csv";
}

foreach $string (@html)
{
    $string=~s/\%\%datasetfile\%\%/$datasetfile/gsxi;
    print "$string\n";
}

#$datasetfile = "GDPpercapita.csv";
sub makedatasetfile
{
    my ($datasetfile, $datasetname, $DEBUG) = @_;

    if ($datasetname && !$datasetfile)
    {
       $datasetfile = $datasetname;
       $datasetfile=~s/\W+//g;
       $datasetfile.=".csv";
    }

    if ($datasetname)
    {
	print "[DEBUG] $datasetname\n" if ($DEBUG);
	($thisdataset, $thisdataset_id, $thistopic) = searchdataset($dbh, $datasetname);
	print "[DEBUG] Search -> $datasetname\n" if ($DEBUG);
        $topic = $thistopic || "No Topic" unless ($topic);
	$topics{$datasetname} = $topic;
        $generator = "$Bin/generatedataset.pl --datasetname '$datasetname' --datasetfile '$datasetfile' --path '$path'";
	$generator.=" --groupby yes";
	print "[DEBUG] $generator\n" if ($DEBUG);
        $run = `$generator`;
        print "$generator\n" if ($DEBUG);
    };

    #print "$run$datasetfile\n";
    $datasetfile = "/tmp/$datasetfile" unless ($datasetfile=~/tmp/);
    return $datasetfile;
};

sub loadhtml
{
   my ($file, $DEBUG) = @_;
   my @content;

   open(file, $file);
   @content = <file>;
   close(file);

   return "@content";
}

