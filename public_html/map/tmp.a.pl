#!/usr/bin/perl

#,"1500","1550","1600","1650","1700","1750","1800","1810","1820","1830","1840","1850","1860","1870","1880","1890","1900","1910","1920","1930","1940","1950","1960","1970","1980","1990","2000"
$head = 1;

if ($head)
{
print <<"EOF";
GLOBAL,CATEGORY,YEAR,INDICATOR,SOURCE,DESCRIPTION,UNIT,MAP,GRAPH,FILE,OPTIONS,TYPE,AFG,ALB,DZA,AND,AGO,AIA,ATG,ARG,ARM,ABW,AUS,AUT,AZE,BHS,BHR,BGD,BRB,BLR,BEL,BLZ,BEN,BMU,BTN,BOL,BIH,BWA,BRA,VGB,BRN,BGR,BFA,BDI,KHM,CMR,CAN,CPV,CYM,CAF,TCD,CHL,CHN,COL,COM,COG,COK,CRI,CIV,HRV,CUB,CYP,CZE,PRK,COD,DNK,DJI,DMA,DOM,ECU,EGY,SLV,GNQ,ERI,EST,ETH,FJI,FIN,FRA,GAB,GMB,GEO,DEU,GHA,GIB,GRC,GRD,GTM,GIN,GNB,GUY,HTI,VAT,HND,HKG,HUN,ISL,IND,IDN,IRN,IRQ,IRL,ISR,ITA,JAM,JPN,JOR,KAZ,KEN,KIR,KWT,KGZ,LAO,LVA,LBN,LSO,LBR,LBY,LIE,LTU,LUX,MAC,MDG,MWI,MYS,MDV,MLI,MLT,MHL,MRT,MUS,MEX,FSM,MCO,MNG,MNE,MSR,MAR,MOZ,MMR,NAM,NRU,NPL,NLD,ANT,NZL,NIC,NER,NGA,NIU,NOR,OMN,PAK,PLW,PSE,PAN,PNG,PRY,PER,PHL,POL,PRT,QAT,KOR,MDA,ROU,RUS,RWA,KNA,LCA,VCT,WSM,SMR,STP,SAU,SEN,SRB,SYC,SLE,SGP,SVK,SVN,SLB,SOM,ZAF,ESP,LKA,SDN,SUR,SWZ,SWE,CHE,SYR,TJK,THA,MKD,TLS,TGO,TKL,TON,TTO,TUN,TUR,TKM,TCA,TUV,UGA,UKR,ARE,GBR,TZA,USA,URY,UZB,VUT,VEN,VNM,YEM,ZMB,ZWE,GUF,ESH,TWN,GRL,EAZ,SJM,PRI,IMN,JEY,GGY,VIR
EOF
print <<"EOF";
,Category A,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
EOF

print <<"EOF";
,>Sub-Category Example A-1,2010,,<a href='http://www.sacmeq.org/statplanet'>Example source</a>,,,,,,y=[2000],,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
EOF

#print "\r\n";

print <<"EOF";
,,,Example indicator XMain-1 (i),,Example description indicator 1,,0=[0xBD0026][10000] 1=[0xF03B20][8000] 2=[0xFD8D3C][6000] 3=[0xFEB24C][4000] 4=[0xFED976][2000] 5=[0xFFFFB2],,,,,
EOF
};

while (<>)
{
   my $str = $_;
   push(@content, $str);
}

%codes = loadcodes();
$field = 1;

for ($i=0; $i<=$#content; $i++)
{
   my $str = $content[$i];
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
	print "$i $str\n" if ($DEBUG);
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

my $DEBUG = 0;
for ($i=0; $i<=$#dataset; $i++)
{
   my $str = $dataset[$i];
   $str=~s/^\|\"/\"\|\"/g;
   $str=~s/\"$//g;
#   print "[DEBUG] $str\n" if ($DEBUG);

   my @items = split(/\|/, $str);
   foreach $item (@items)
   {
	$item=~s/^\s*\"\s*|\"\s*$//g;
	$blank++ if ($item!~/\d+/);
   }

   if ($i eq $yearstring)
   {
	print "[$i] $str\n" if ($DEBUG);
	@years = split(/\|/, $str);
	$report++;
	print "[DEBUG YEARS] @years\n"; # if ($DEBUG);
   }
   else
   {
	# "Latvia "||||||||||||||||||||||"1936.498"|"2115.183"|"2361.159"|"2524.543"|"2663.59"|"2376.178"|
	my $country = $items[0];
	$country=~s/^\s+|\s+$//g;
	my $code = $codes{$country};
#	print "CODE [$country] $code => $codes{$country}\n";
	$country{$code} = $country;
	my ($thisyear, $thisfield);

	if ($country!~/\d+/ && $str=~/\d+/)
	{
#	print "*$country [$code]*\n XXX $str\n";

	for ($j=1; $j<=$#items; $j++)
	{
	    my $thisyear = $years[$j];
	    my $thisval = $items[$j];

	    print "[D] $j $thisyear $thisval\n" if ($DEBUG);
	    if ($report == 1 && $thisval)
	    {
	        $yearrating{$thisyear} = $thisyear;
	        $val{$code}{$thisyear} = int($thisval);
		$val{$code}{$thisyear} = $thisval;
	    };
	}

	};
   }

}

foreach $year (sort {$yearrating{$b} <=> $yearrating{$a}} keys %yearrating)
{
    my $outstring = "";
    $outstring = ",,$year,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
    print "$outstring\n";
    $outstring = ",,,-,,,,,,,,,";
    foreach $code (@order)
    {
	my $val = $val{$code}{$year};
	$outstring.="$val" if ($val);
	$outstring.=",";
        #print "$code\n";
    }
    print "$outstring\n" if ($outstring=~/\d+/);
};

sub loadcodes
{
    my %codes;
    open(codes, "/home/linuxadmin/clioinfra/bin/countries.txt");
    #Albania;;ALB
    while (<codes>)
    {
	my $str = $_;
	$str=~s/\n//g;
	my ($country, $code) = split(/\;\;/, $str);
	$codes{$country} = $code if ($code);
	print "$code\n" if ($DEBUG);
	if ($code)
	{
	    push(@order, $code);
	}
    }
    close(codes);

    return %codes;
}
