#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../lib";

use CGI;
my $q = new CGI;

$DEBUG = 0;
#print $q->header( "text/html" );
$indicator = $q->param('indicator');
$topic = $q->param('topic');
$file = $q->param('file');

$DIR = "$Bin/../.."; # "/home/www/clio_infra/clioinfra";
$templatedir = "$DIR/cgi-bin/templates";

print "Content-type: text/html\n\n";

$maintpl = "$templatedir/map.sample.tpl";
open(tpl, "$maintpl");
@maphtml = <tpl>;
close(tpl);

$mapcontent = "@maphtml";

#print "X $topic*/ $file => $indicator\n";
if ($topic && $indicator)
{
$dataset = "./tmp/$indicator.csv";
$convert = `/usr/local/bin/xls2csv -d utf-8 $DIR/htdocs/excel/$topic/$indicator -c '|'|$DIR/htdocs/map/analyzer.pl > $DIR/htdocs/map/tmp/$indicator.csv`;
print "$convert\n";
$makedos = `/usr/bin/todos $DIR/htdocs/map/tmp/$indicator.csv`;
$topic = "Education".$topic;
}
#my $root = "http://alpha.dev.clio-infra.eu/clioinfra/datasets";
#exit(0);

if ($file)
{
   $path = "$DIR/htdocs/data";
   $file=~s/\.html//g;
   $path = "$path/$file";

   if ($file=~/^(.+?)\-\-(.+)$/)
   {
	$name = $1;
	$indicator = $2;
	$topic = $1;
	$indicator=~s/^\d+\s+//g;
   }

   $path=~s/\-\-/\//g;
   if ($file=~/dataset/)
   {
	#print "$file $DIR/htdocs/map/tmp/$file.csv\n";
#        $makedos = `/usr/bin/todos $DIR/htdocs/map/tmp/$file.csv`;
        $dataset = "./tmp/$file.csv";
   }
   elsif (-e $path)
   {
        print "File: $path<br />\n" if ($DEBUG);
	my $tmpfile = $file;
	$tmpfile=~s/\W+//g;
	$tmpdir = "$DIR/htdocs/map/tmp";

	$dataset = 'Dataset' unless ($dataset);

	$dataset = $indicator;
	$dataset=~s/\.\S+$//g;
	$createcsv = `$Bin/db2visual.pl --dataset '$dataset' > $tmpdir/$tmpfile.csv.tmp`;
	print "db2visual $Bin/db2visual.pl --dataset '$dataset' > $tmpdir/$tmpfile.csv.tmp<br />" if ($DEBUG);
	$convert2 = `$DIR/htdocs/map/analyzer.pl -csvfile '$tmpdir/$tmpfile.csv.tmp' -indicator '$indicator' -dataset '$dataset' -topic '$topic' -source 'Clio Infra' -link '$root/$topic/$indicator' -debug '$DEBUG' > $tmpdir/$tmpfile.csv`;

        if ($DEBUG)
	{
	     print "$DIR/htdocs/map/analyzer.pl -csvfile '$tmpdir/$tmpfile.csv.tmp' -indicator '$indicator' -dataset '$dataset' -topic '$topic' -debug '$DEBUG' > $tmpdir/$tmpfile.csv\n";
	     print "<br />Convert $convert2\n";
	     exit(0);
	}
	print "OUTPUT: /usr/local/apache2/alpha/htdocs/map/tmp/$tmpfile.csv <br \>\n" if ($DEBUG);
	$makedos = `/usr/bin/todos $DIR/htdocs/map/tmp/$tmpfile.csv`;	
	$dataset = "./tmp/$tmpfile.csv";
	#print "$convert\n";
   };

}

$mapcontent=~s/\%\%name\%\%/$indicator/gsxi;
$mapcontent=~s/\%\%dataset\%\%/$dataset/gsxi;
$mapcontent=~s/\%\%topic\%\%/$topic/gsix;

print "$mapcontent\n" unless ($DEBUG);
#
