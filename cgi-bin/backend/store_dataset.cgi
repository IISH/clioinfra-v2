#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/libs";

use DB_File;
use DBI;
$| = 1;

my %dbconfig = loadconfig("$Bin/db.config");
my $rootdir = $dbconfig{rootdir};
my $datadir = "$rootdir/".$dbconfig{filestore}; 
my $tmpdir = "$rootdir/$dbconfig{tmpdir}"; 

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

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
    'author=s' => \$author,
    'dataset=s' => \$dataset,
    'file=s' => \$locfile
);

my $fullpath = "$datadir/$locfile";

if ($fullpath)
{
   my $file = $locfile;
   $file=~s/\.html//g;
   $path = $fullpath;

   if ($fullpath=~/^(.+?)\-\-(.+)$/)
   {
        $name = $1;
        $indicator = $2;
        $topic = $1;
        $indicator=~s/^\d+\s+//g;
   }
   print "$path\n$file\n$name $indicator $topic\n$tmpdir\n$datadir\n$fullpath\n" if ($DEBUG);

   $path=~s/\-\-/\//g;
   if (-e $fullpath)
   {
        print "DataFile: $path<br />\n" if ($DEBUG);
        my $tmpfile = $file;
        $tmpfile=~s/\W+//g;
	$csv2db = "$tmpdir/$tmpfile.csv.tmp";

        if ($fullpath=~/\.xlsx$/)
        {
            $convrun = "$rootdir/cgi-bin/bin/xlsx2csv.py -d '|' \"$path\" > $tmpdir/$tmpfile.csv.tmp";
            print "[DEBUG] $convrun***\n" if ($DEBUG);
            $convert1 = `$convrun`;
        }
        elsif ($fullpath=~/\.xls$/)
        {
            $convertxls=`/usr/local/bin/xls2csv -d utf-8 \"$path\" -c '|'> $tmpdir/$tmpfile.csv.tmp`;
        }
        $dataset = 'Dataset' unless ($dataset);
        $convert2csv = "$rootdir/htdocs/map/analyzer.pl -csvfile '$tmpdir/$tmpfile.csv.tmp' -indicator '$indicator' -dataset '$dataset' -topic '$topic' -source 'Clio Infra' -link '$root/$topic/$indicator' -debug '$DEBUG' > $tmpdir/$tmpfile.csv";
	$exe = `$convert2csv`;

        print "OUTPUT: /usr/local/apache2/alpha/htdocs/map/tmp/$tmpfile.csv <br \>\n" if ($DEBUG);
        $makedos = `/usr/bin/todos $rootdir/htdocs/map/tmp/$tmpfile.csv`;
        $dataset = "./tmp/$tmpfile.csv";
        print "$convert2csv\n" if ($DEBUG);

	if (-e $csv2db)
	{
	    $db = "$rootdir/cgi-bin/reader/csv2import.pl -csvfile $csv2db -indicator '$indicator' -dataset '$csv2db' -topic '$topic'";
	    $makeexport = `$db`;
	    print "[DEBUG] $db \n" if ($DEBUG);
	}
   };

}

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

