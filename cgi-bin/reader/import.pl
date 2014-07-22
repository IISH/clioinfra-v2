#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../lib";

my $excelfile = $ARGV[0];
my $DIR = "/home/www/clio_infra/tmp";

# /home/www/clio_infra/8080/clioinfra/htdocs/data/12\ -\ National\ Accounts/GDP\ per\ capita.xlsx
my @items = split(/\//, $excelfile);
foreach $item (@items)
{
   $item=~s/^\s+|\s+$//g;
}
my ($datasetNameID, $datasetTopicID) = ($#items, $#items-1);
my ($datasetName, $datasetTopic) = ($items[$datasetNameID], $items[$datasetTopicID]);
$datasetTopic=~s/^\d+\s+\-\s+//g;
$datasetName=~s/\.\w+$//g;

print "$datasetTopic\n$datasetName\n";

if ($datasetName)
{
    my $tmpfile = "$excelfile.tmp";

    if ($excelfile)
    {
        my $tmpfile = $excelfile;
        $tmpfile=~s/\W+//g;
        $tmpdir = "$DIR";

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

	$importbin = "$Bin/csv2import.pl -csvfile $tmpdir/$tmpfile.csv.tmp -indicator '$datasetTopic' -dataset '$datasetName' -topic '$datasetTopic'";
	$importer = `$importbin`;
        print "$importbin\n$importer\n";
    };
}
