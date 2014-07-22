#!/usr/bin/perl

$file = $ARGV[0];
open(file, $file);
@html = <file>;
close(file);

foreach $str (@html)
{
   # "Climate Change","Forestry","Growing stock per hectare (m3/ha)","Outcome"
   $str=~s/\r|\n//g;
   $str=~s/^\"//g;
   my ($topic, $topic2, $indicator, $other) = split(/\"\,\"/, $str);
   $true = 1;
   #Broad Sector ;;Indicator
   #NOTE: indicators in bold are STANDARD indicators; all others are SUGGESTED indicators",,,;;
   $true = 0 if ($str=~/^(Broad\s+S|NOTE)/);

   if ($true)
   {
      print "$indicator;;$topic\n";
   };
}
exit(0);

$html = "@html";

#<tr>
#<td class="code">au</td>
#<td>Austria</td>
#</tr>

$html=~s/\r|\n//g;
while ($html=~s/<tr>\s*<td\s+class\=\"code\">(.+?)<\/td>\s*<td>(.+?)<\/td>\s*<\/tr>//)
{
   my ($country, $code) = ($2, $1);
   $code=~s/<.+?>/ /g;
   $code=~s/\s+//g;
   print "$country;;$code\n";
}
