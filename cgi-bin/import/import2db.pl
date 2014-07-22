#!/usr/bin/perl

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../lib";

$head = 1;
use Getopt::Long;
$DIR = $Bin || "/home/www/clio_infra/clioinfra";

my $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'output=s' => \$output,
    'link=s' => \$link,
    'source=s' => \$source,
    'debug=i' => \$DEBUG
);

$filter = "United";

if ($DEBUG eq 3)
{
   print "DEBUG $csvfile\n";
}

$topic=~s/^\s*\-\s*//g;
$topic = "Category AB" unless ($topic);
$indicator = "Sub-Category Example A-111" unless ($indicator);
$link = "<a href=\"$link\">$source</a>" if ($link && $source);
$step = 2000;

#showhead();

open(csvfile, $csvfile);
@content = <csvfile>;
close(csvfile);

%codes = loadcodes();
%regions = loadregions();
$field = 1;

for ($i=0; $i<=$#content; $i++)
{
   my $str = $content[$i];
   my $strorig = $str;

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
	$backup{$str} = $strorig;
	print "$i $str\n" if ($DEBUG eq 1);
   }
}

foreach $i (sort {$year{$b} <=> $year{$a}} keys %year)
{
    unless ($yearstring)
    {
	$yearstring = $i;
	print "[DEBUG YEAR] $yearstring\n" if ($DEBUG);
    }
}

for ($i=0; $i<=$#dataset; $i++)
{
   my $str = $dataset[$i];
   my $nonempty;
   $str=~s/^\|\"/\"\|\"/g;
   $str=~s/\"$//g;
#   print "[DEBUG] $str\n" if ($DEBUG);

   my @items = split(/\|/, $str);
   foreach $item (@items)
   {
	$item=~s/^\s*\"\s*|\"\s*$//g;
	$blank++ if ($item!~/\d+/);
	$nonempty++ if ($item=~/\d+/);
   }

   if ($i eq $yearstring)
   {
	print "STEP1 [$i] $str\n" if ($DEBUG);
	@years = split(/\|/, $str);
	$report++;
#	print "[DEBUG YEARS] @years\n" if ($DEBUG);
   }
   else
   {
	# "Latvia "||||||||||||||||||||||"1936.498"|"2115.183"|"2361.159"|"2524.543"|"2663.59"|"2376.178"|
	my $country = $items[0];
	$country=~s/^\s+|\s+$//g;
	unless ($ids{$country})
	{
	    if ($backup{$str}=~/^(\d+)/)
	    {
		$ids{$country} = $1;
	    }
	}

	my $code = $codes{$country};
#	print "CODE [$country] $code => $codes{$country}\n";
	$country{$code} = $country;
	my ($thisyear, $thisfield);

	my $true = 1;
	#$true = 0 if ($filter && $country!~/$filter/i);
        my $thisregion = $regions{$current_region_id}{region};
        $country2region{$code} = $current_region_id;

	if ($country!~/\d+/ && $str=~/\d+/ && $true)
	{
#	print "*$country [$code]*\n XXX $str\n";
	#print "$country;;$code;;\n" if ($filter);

	print "[DEBUG] $str\n" if ($DEBUG eq 4);
	for ($j=1; $j<=$#items; $j++)
	{
	    my $thisyear = $years[$j];
	    my $thisval = $items[$j];
	    my $thisregion = $regions{$current_region_id}{region};
	    $country2region{$code} = $current_region_id;

	    print "[$country/$thisregion] STEP2 [D] $j $thisyear $thisval\n" if ($DEBUG eq 3);
	    if ($report == 1 && $thisval)
	    {
	 	#print "$thisyear => $thisval\n" if ($filter);
	        $yearrating{$thisyear} = $thisyear;
	        $val{$code}{$thisyear} = int($thisval);
		$val{$code}{$thisyear} = $thisval;
	    };
	}

	};

	if ($country=~/\w+/ && !$nonempty && $str!~/until/i)
	{
	    if ($backup{$str}=~/^(\d+)\|(.+?)\|/ && !$code)
	    {
		my ($regcode, $region) = ($1, $2);

		if ($regions{$regcode})
		{
		    $current_region_id = $regcode;
	            print "$regcode;;$region;;;;[REGION]\n" if ($DEBUG eq 5);
		};
	    };
	}
   }

}

foreach $code (@order)
{
   print "$code," if ($DEBUG);
}

foreach $region_id (sort keys %regions)
{
    my ($region, $regionroot) = ($regions{$region_id}{region}, $regions{$region_id}{regroot});

    print "$region_id;;$region;;$regionroot\n" if ($DEBUG eq 6);
    $regionroot = '0' unless ($regionroot);
#    $sqlquery = "INSERT into regions (region_id, region_name, region_description, region_root) values ($region_id, '$region', '$region', $regionroot);";
    print "$sqlquery\n";
}

foreach $country (sort keys %codes)
{
    my ($code, $id) = ($codes{$country}, $ids{$country});
    my ($region_id) = ($country2region{$code});

    $region_id='0' unless ($region_id);
    $country=~s/\"//g;
    if ($id)
    {
        $sqlquery = "insert into countries (country_id, country_name, country_description, country_code, active, region_id) values ($id, '$country', '$country', '$code', 1, '$region_id');";
	#$dbh->do($sqlquery);
        print "$sqlquery\n";
        print "CNTR;;$id;;$region_id;;$code;;$country\n";
    };
}

exit(0);
open(output, ">$output") if ($output);
foreach $year (sort {$yearrating{$b} <=> $yearrating{$a}} keys %yearrating)
{
    my $outstring = "";
    $outstring = ",,$year,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
    print "$outstring\n";
    $outstring = ",,,-,,,,,,,,,";
    foreach $code (@order)
    {
	my $val = $val{$code}{$year};
	$val=~s/\.\d+//g;
	$outstring.="$val" if ($val);
	$outstring.=",";
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

sub loadregions
{
    my %regions;

    open(regions, "$DIR/regions.txt");
    while (<regions>)
    {
	# 155;;Western Europe;;150
        my $str = $_;
        $str=~s/\n//g;
        my ($regcode, $region, $regroot) = split(/\;\;/, $str);
	$regions{$regcode}{region} = $region;
	$regions{$regcode}{regroot} = $regroot;	
    }
    close(regions);

    return %regions;
}

sub loadcodes
{
    my %codes;
    my $DEBUG = 0;

    open(codes, "$DIR/countries.txt");
    #Albania;;ALB
    while (<codes>)
    {
	my $str = $_;
	$str=~s/\n//g;
	my ($country, $code) = split(/\;\;/, $str);
	$codes{$country} = $code if ($code);
	print "$code;;$country\n" if ($DEBUG);
	if ($code && !$known{$code}) # && (!$filter || $country=~/$filter/i))
	{
	    push(@order, $code);
	}
	$known{$code}++;
    }
    close(codes);
    exit(0) if ($DEBUG);

    return %codes;
}

sub showhead
{
print <<"EOF";
GLOBAL,CATEGORY,YEAR,INDICATOR,SOURCE,DESCRIPTION,UNIT,MAP,GRAPH,FILE,OPTIONS,TYPE,AFG,ALB,DZA,AND,AGO,AIA,ATG,ARG,ARM,ABW,AUS,AUT,AZE,BHS,BHR,BGD,BRB,BLR,BEL,BLZ,BEN,BMU,BTN,BOL,BIH,BWA,BRA,VGB,BRN,BGR,BFA,BDI,KHM,CMR,CAN,CPV,CYM,CAF,TCD,CHL,CHN,COL,COM,COG,COK,CRI,CIV,HRV,CUB,CYP,CZE,PRK,COD,DNK,DJI,DMA,DOM,ECU,EGY,SLV,GNQ,ERI,EST,ETH,FJI,FIN,FRA,GAB,GMB,GEO,DEU,GHA,GIB,GRC,GRD,GTM,GIN,GNB,GUY,HTI,VAT,HND,HKG,HUN,ISL,IND,IDN,IRN,IRQ,IRL,ISR,ITA,JAM,JPN,JOR,KAZ,KEN,KIR,KWT,KGZ,LAO,LVA,LBN,LSO,LBR,LBY,LIE,LTU,LUX,MAC,MDG,MWI,MYS,MDV,MLI,MLT,MHL,MRT,MUS,MEX,FSM,MCO,MNG,MNE,MSR,MAR,MOZ,MMR,NAM,NRU,NPL,NLD,ANT,NZL,NIC,NER,NGA,NIU,NOR,OMN,PAK,PLW,PSE,PAN,PNG,PRY,PER,PHL,POL,PRT,QAT,KOR,MDA,ROU,RUS,RWA,KNA,LCA,VCT,WSM,SMR,STP,SAU,SEN,SRB,SYC,SLE,SGP,SVK,SVN,SLB,SOM,ZAF,ESP,LKA,SDN,SUR,SWZ,SWE,CHE,SYR,TJK,THA,MKD,TLS,TGO,TKL,TON,TTO,TUN,TUR,TKM,TCA,TUV,UGA,UKR,ARE,GBR,TZA,USA,URY,UZB,VUT,VEN,VNM,YEM,ZMB,ZWE,GUF,ESH,TWN,GRL,EAZ,SJM,PRI,IMN,JEY,GGY,VIR\r
EOF
print <<"EOF";
,$topic,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\r
EOF

print <<"EOF";
,>$topic,2010,,$link,,,,,,y=[$step],,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\r
EOF

#print "\r\n";

print <<"EOF";
,,,$indicator,,$topic description,,0=[0xBD0026][10000] 1=[0xF03B20][8000] 2=[0xFD8D3C][6000] 3=[0xFEB24C][4000] 4=[0xFED976][2000] 5=[0xFFFFB2],,,,,\r
EOF
   return;
}
