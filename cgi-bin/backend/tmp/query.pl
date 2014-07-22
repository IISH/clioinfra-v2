#!/usr/bin/perl

$query = $ARGV[0];
$dir = "/home/www/clio_infra/8080/clioinfra/htdocs/data/";
opendir(dir, $dir);
@items = readdir(dir);
closedir(dir);

open(file, "./tmp/desc");
@content = <file>;
close(file);

foreach $str (@content)
{
   $str=~s/\r|\n//g;
   my ($topic, $abstract) = split(/\;\;/, $str);
   $info{$topic} = $abstract;
}

foreach $str (@items)
{
   $str=~s/\r|\n//g;

   if ($str=~/^(\d+)\s+\-\s+(.+)$/)
   {
	my ($topicid, $topic) = ($1, $2);
	my $abstract = $info{$topic} || ' ';
	$abstract=~s/\'/\"/g;
	if ($abstract=~/^(.250\.)\s+/)
	{
	    $abstract = $1;
	}

	opendir(dir, "$dir/$str");
	@dir = readdir(dir);
	closedir(dir);

	foreach $path (@dir)
	{
	   my $show = 1;

	   $show = 0 if ($query);
	   $show=1 if ($path=~/$query/);
	   
	   if ($path=~/^\w/ && $show)
	   {
	      print "$topicid;;$dir$str/$path\n";
	   };
	}
#	print "$1 $2\n";
   }
}
