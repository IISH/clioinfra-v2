#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";

use Getopt::Long;
my @time = (localtime)[0..5];
my $create_date = sprintf("%04d%02d%02d%02d%02d", $time[5]+1900, $time[4]+1, $time[3], $time[2], $time[1]);
my $DEBUG = 0;

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$chartdir = $dbconfig{chartdir};
$htmltemplate = "$Bin/bar.sample.tmpl";
$type = "bar";
$url = $ENV{REQUEST_URI};
$url=~s/^\S+?showchart\///gsx;

unless ($url)
{
my $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'indicatorID=s' => \$indicatorID,
    'output=s' => \$output,
    'link=s' => \$link,
    'source=s' => \$source,
    'debug=i' => \$DEBUG,
    'author=s' => \$author,
    'country=s' => \$country,
    'region=s' => \$region,
    'uri=s' => \$url
);

    $url=~s/^.+?html\?//gsxi;
}
else
{
   print "Content-type: text/html\n\n";
};

#print "URL $url<br>";
if ($url=~s/visualize\=(\w+)//)
{
   $type = $1;
}
if ($url=~/debug\=(\w+)/)
{
   $DEBUG++;
}
$url=~s/\"$//g;
print "URL $url\n" if ($DEBUG);
$url=~s/\/datasets\/country\?//g;
#$url = "country=Ukraine&indicator=GDP per capita";
#print "DEBUG $url <br>\n";

$chart = `$Bin/../reader/combinedb.cgi \"$url\" $type`;
#$chart = `$Bin/../reader/download.cgi \"$url\" $type`;
#print "$chart\n";
my @charts = split(/\n/, $chart);
foreach $chart (@charts)
{
    if ($chart=~/\[CHART\s+(\S+?)\]\s*(.+)$/)
    {
	$charts{$1} = $2;
	print "CHART *$1* $2 <br />" if ($DEBUG);
    }
    if ($chart=~/\[\s*(.+?)\s*COUNTRY\s*(.+?)\]\s*(.+)$/)
    {
	my ($country, $type, $values) = ($1, $2, $3);
	$block++ unless ($blocks{$country});
	$blocks{$country}{$type} = $values;
    }
}

%colors = (1, "#A6C603", 2, "#ffae00", 3, "#52aa4b", 4, "#335ac9");
my $block;
foreach $country (sort keys %blocks)
{
   $cid++;
   my ($values, $years) = ($blocks{$country}{values}, $blocks{$country}{years});
   $values=~s/\,\s*$//g;
$block.="
			{
                        \"type\":\"line\",
                        \"values\":[$values],
                        \"colour\":\"$colors{$cid}\",
                        \"text\":\"$country\",
                        \"font-size\":12,
                        \"tip\":\"Unique: #val#\"
			},
";
 
}
$block=~s/\,\s*$//g;
#print "BLOCK$create_date $block <br/>\n";
print "$chart\n" if ($DEBUG);

if (keys %charts)
{
    @html = loadhtml($htmltemplate);
    @csv = loadhtml("$Bin/templates/$type.csv");
};
#@csv = loadhtml("$Bin/chart.csv");
@content = split(/\n/, "@csv");

print "File $Bin/$type.csv" if ($DEBUG);

$cvsfilename = "$create_date";
$cvsfilename.="$indicatorID" if ($indicatorID);
$tmpind = $indicator;
$tmpind=~s/\W+//g;
$cvsfilename.="$tmpind" if ($tmpind);
$csvfile = $chartdir || "/home/www/clio_infra/8081/clioinfra/htdocs/charts";
$csvfile.="/charts/$cvsfilename.txt";
open(file, ">$csvfile");

# Check years
my @allyears = split(/\,/, $charts{years});
$step = 20;
$step = 10 if ($#allyears <= 80);
$step = 5 if ($#allyears < 50);
if ($#allyears > 10)
{
    my $newline;
    foreach $year (@allyears)
    {
	$year=~s/\"//g;
	if ($year % $step == 0)
	{
	    $newline.="\"$year\",";
	}
	else
	{
	    $newline.="\"\",";
	}
    }
    $newline=~s/\,$//g;
    $charts{years} = $newline;
};

$charts{steps} = 5000 unless ($charts{steps});
foreach $item (@content)
{
   $item=~s/\%\%values\%\%/$charts{values}/gsix;
   $item=~s/\%\%years\%\%/$charts{years}/gsxi;
   $item=~s/\%\%max\%\%/$charts{max}/gsxi;
   $item=~s/\%\%steps\%\%/$charts{steps}/gsxi;
   $item=~s/\%\%title\%\%/$charts{title}/gsxi;
   $item=~s/\%\%block\%\%/$block/gsxi;
   print file "$item\n";
}
close(file);

$csvfile=~s/^\S+?\/htdocs//gsxi;
$tmpID = $indicatorID || 0;
$chartname = $indicator || "Chart";
$chartdir=~s/^(.+?\_html)\S+$/$1/g;
$csvfile=~s/$chartdir//g;
foreach $html (@html)
{
    $html=~s/\%\%csvfile\%\%/$csvfile/gsxi;
    $html=~s/\%\%ID\%\%/$tmpID/gsxi;
    $html=~s/\%\%Indicator\%\%/$chartname/gsix;
    print "$html";
}

unless (keys %charts)
{
    print "<center>No Data in this dataset</center><br>\n";
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
