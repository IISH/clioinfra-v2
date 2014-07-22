#!/usr/bin/perl

$file = $ARGV[0];
open(file, $file);
@html = <file>;
close(file);

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
