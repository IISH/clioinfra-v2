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
#$DIR = "/home/www/clio_infra/clioinfra";
#$tmpdir = "$Bin/../../htdocs/tmp";

$htmltemplate = "$Bin/../templates/statplanet.tpl";
@html = loadhtml($htmltemplate);

my @time = (localtime)[0..5];
my $create_date = sprintf("%04d-%02d-%02d %02d:%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $edit_date = $create_date;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$tmpdir = $dbconfig{path};
$DIR = $dbconfig{chartdir};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

$head = 1;
use Getopt::Long;

my $result = GetOptions(
    \%options,
    'datasetfile=s' => \$datasetfile,
    'datasetname=s' => \$datasetname, 
    'path=s' => \$path,
    'debug=i' => \$DEBUG
);

if ($datasetname)
{
    print "[DEBUG] Generating dataset $datasetname...\n" if ($DEBUG);
    $runcommand = "$Bin/db2visual.pl --dataset '$datasetname'";
    $generate = `$runcommand`;
    print "[DEBUG] Complete\n$runcommand\n" if ($DEBUG);
    $datasetfile = "$path/$datasetfile" if ($path);

    if ($datasetfile)
    {
	my $tmpdatasetfile = $datasetfile;
   	$tmpdatasetfile.=".tmp" if ($tmpdatasetfile!~/\.tmp/);
	unless ($tmpdatasetfile=~/tmp/sxi)
        {
	    #$tmpdatasetfile = "$Bin/../../htdocs/tmp/$datasetfile.txt";
	    #print "SINDER $datasetfile\n";	
        }

	open(file, ">$tmpdatasetfile");
        print file "$generate\n";
	close(file);

	($thisdataset, $thisdataset_id, $thistopic) = searchdataset($dbh, $datasetname);
	$topic = $thistopic || "No Topic" unless ($topic);
	#$datasetfile.=".txt";

	$convert = "$DIR/map/analyzer.pl -csvfile '$tmpdatasetfile' -indicator '$datasetname' -topic '$topic' -source 'Clio Infra' -link '$root/$topic/$indicator' > $datasetfile";
	print "[DEBUG] $convert\n" if ($DEBUG);
	$run = `$convert`;
        $makedos = `/usr/bin/todos $datasetfile`;
	print "$datasetfile\n"; # if ($DEBUG);
    };
}

sub loadhtml
{
   my ($file, $DEBUG) = @_;
   my @content;

   open(file, $file);
   @content = <file>;
   close(file);

   return "@content";
}

