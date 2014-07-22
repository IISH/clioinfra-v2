#!/usr/bin/perl 

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";
#use lib "$libpath/libs";
use ClioConfig;

#use Spreadsheet::WriteExcel;
use Excel::Writer::XLSX;
my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$tmpdir = $dbconfig{path};

use Getopt::Long;
my $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'dataset=s' => \$dataset,
    'excelfile=s' => \$file,
    'indicator=s' => \$indicator
);

my @content = split(/\|\|/sxi, $dataset);
foreach $str (@content)
{
        # CM.MKT.TRAD.GD.ZS;;Australia;;36;;1990;;12.7717735003776
	$str=~s/\r|\n//g;
	my ($indcode, $country, $code, $year, $value) = split(/\%\%/, $str);
	print "$country\n" if ($DEBUG);
	$countries{$country} = $code;
	$values{$country}{$year} = $value;
}
open(codefile, "$Bin/code.order.txt");
@codes = <codefile>;
close(codefile);

foreach $codestr (@codes)
{
    $codestr=~s/\r|\n//g;
    if ($codestr=~/(\d+)\s+(.+)\s*$/)
    {
	($code, $country) = ($1, $2);
	push(@countries, "$code;;$country");
    }
    else
    {
	push(@countries, "");
    }
}

#$indicator = shift @content;
#$indicator=~s/^\#//g;
#$indicator=~s/^.+?\;\;(.+)$/$1/g;

$file=~s/\.txt//g;
if ($file=~/^.+\/(\S+)$/)
{
    $file = $1;
}
$file = "default" unless ($file);
my $excelfile = "$tmpdir/$file.xlsx" || "$Bin/../../htdocs/tmp/$file.xlsx";
print "$excelfile\n";

# Create a new workbook called simple.xls and add a worksheet.
my $workbook  = Excel::Write::XLSX->new($excelfile);
my $worksheet = $workbook->add_worksheet();
my $bold       = $workbook->add_format(bold => 1);

# The general syntax is write($row, $column, $token).
# Note that row and column are zero indexed.

# Write some text.
$worksheet->set_column('A:A', 30);
$worksheet->set_column('B:B', 35);
$indicator=~s/^\"|\"$//g;
$worksheet->write(0, 0,  $indicator);
$i+=3;

$worksheet->write(2, 0, "Code", $bold);
$worksheet->write(2, 1, "Continent, Region, Country", $bold);

# Countries list
$makebold = 1;
foreach $countrystr (@countries)
{
    my ($code, $country) = split(/\;\;/, $countrystr);

    $i++;
    $cellA = "A$i";
    $cellB = "B$i";
    $worksheet->write($cellA, "$code");
    if ($makebold)
    {
	$worksheet->write($cellB, "$country", $bold);
    }
    else
    {
        $worksheet->write($cellB, "$country");
    };
    $cells{$i} = $country;

    if (!$country)
    {
	$makebold = 1;
    }
    else
    {
	$makebold = 0;
    }
    
    print "$i $country\n" if ($DEBUG);
}

$j=1;
$start = 1980;
for ($year=$start; $year<=2012; $year++)
{
    $j++;
    $worksheet->write(2, $j,  $year, $bold);
    $row = 2;
    foreach $countrystr (@countries)
    {
        my ($code, $country) = split(/\;\;/, $countrystr);
	my $value = $values{$country}{$year};
	$row++;
	if ($value)
	{
	    #print "$country $row $j => $value\n";
	    $worksheet->write($row, $j,  $value);
	}
    }
}

sub loadconfig1g
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
