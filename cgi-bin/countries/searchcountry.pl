#!/usr/bin/perl

$query = $ARGV[0];
$DEBUG = 0;

open(file, "countries.list.csv");
@countries = <file>;
close(file);

# {query:'amsterdam',results:[{"title":"Kraakbuurten Amsterdam: Nieuwmarkt, Waterlooplein, Burgwallen.","link":"http://search.socialhistory.org/Record/1191206","description":"Kraakbuurten Amsterdam: Nieuwmarkt, Waterlooplein, Burgwallen.","id":"1191206","category":"IISG"},
#{"title":"Kraakbuurten Amsterdam: Nieuwmarkt, Waterlooplein, Burgwallen.","link":"http://search.socialhistory.org/Record/1191142","description":"Kraakbuurten Amsterdam: Nieuwmarkt, Waterlooplein, Burgwallen.","id":"1191142","category":"IISG"},

$content.="{query:'$query',results:[";
foreach $str (@countries)
{
   $str=~s/\r|\n//g;
   if ($str=~/$query/i)
   {
	print "$str\n" if ($DEBUG);
	$id++;
	my ($country, $code) = split(/\;\;/, $str);
 	my $squery = $country;
	$squery=~s/\s+/\+/g;
	#$url = "https://www.google.nl/search?q=$squery&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a";
	$url = "/cgi-bin/wikiparser.cgi?q=$squery";
	$content.="{\"title\":\"$country\",\"link\":\"$url\",\"description\":\"$country\",\"id\":\"$id\",\"category\":\"IISG\"},\n";
   }
}
$content=~s/\,\s*$//g;
$content.="]}";

print "$content\n";
