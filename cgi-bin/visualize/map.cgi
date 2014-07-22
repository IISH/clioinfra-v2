#!/usr/bin/perl

use CGI;
my $q = new CGI;
print $q->header( "text/html" );
$indicator = $q->param('indicator');
$topic = $q->param('topic');

$excelfile = "/usr/local/apache2/alpha/htdocs/excel/$topic/";
$excelfile.="$indicator";
print "Content-type: text/html\n\n";
print "$indicator => $excelfile<br>";

$convert = `/usr/local/bin/xls2csv -d utf-8 $excelfile -c '|'`;# > $Bin/csv/$csvfile.csv`;
print "$convert\n";
