#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../lib";

$datadir = $ARGV[0];
$tmpdir = "$Bin/tmp";
mkdir $tmpdir unless (-e $tmpdir);

$DIR = "$Bin/../..";
opendir(D, $datadir) || die "Can't opedir: $!\n";
@topics = readdir(D);
closedir(D);

foreach $topic (@topics)
{
    # /home/www/clio_infra/8080/clioinfra/cgi-bin/reader/csv2import.pl -csvfile /home/www/clio_infra/8080/clioinfra/htdocs/tmp/20121214144105Inflationxlsx.csv.tmp -indicator 'Inflation' -dataset 'Inflation' -topic 'Topic'
    $dir = $topic;
    unless ($topic=~/^\./)
    {
	my $topic_id;
	if ($topic=~/^(\d+)/)
	{
	    $topic_id = $1;
	    $topic=~s/^\d+\s+\-\s+//g;
	}

	$datasetsdir = "$datadir/$dir";

	print "$topic_id $topic $datasetsdir\n" if ($DEBUG);
	#print "insert into topics (topic_id, topic_name, description) values ('$topic_id', '$topic', ' ');\n";

	opendir(D, $datasetsdir) || die "Can't opedir: $!\n";
	@datasets = readdir(D);
	closedir(D);

	foreach $dataset (@datasets)
	{
	   my $path = "$datasetsdir/$dataset";
	   $tmpfile=$dataset;
	   $tmpfile=~s/\W+//g;

	   my $doimport;
	   #$doimport = "true" if ($dataset=~/GDP\s+per/sxi);

	   print "$dataset [$doimport]\n";
	   if ($dataset=~/(\.xls)$/)
	   {
		print "		$dataset => $tmpfile $path\n" if ($DEBUG);
		$convertxls="/usr/local/bin/xls2csv -d utf-8 \"$path\" -c '|'> $tmpdir/$tmpfile.csv.tmp";
	        $exe = `$convertxls`;
		print "$convertxls\n";
		$doimport = 'true';
	   }
           if ($dataset=~/(\.xlsx)$/)
           {
                print "		$dataset => $tmpfile\n" if ($DEBUG);
		$convert1 = `$DIR/cgi-bin/bin/xlsx2csv.py -d '|' \"$path\" > $tmpdir/$tmpfile.csv.tmp`;
		$doimport = 'true';
           }

	   if ($doimport)
	   {
	       my $datasetname = $dataset;
	       $datasetname=~s/\.\S+$//g;
	       $import2db = "/home/www/clio_infra/8080/clioinfra/cgi-bin/reader/csv2import.pl -csvfile $tmpdir/$tmpfile.csv.tmp -indicator '$datasetname' -dataset '$datasetname' -topic '$topic'";
	       print "[IMPORT] $import2db\n";
	       $importrun = `$import2db > /dev/null`;
	   };
	}

    };
};


