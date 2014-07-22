#!/usr/bin/perl

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
	print "insert into datasets.topics (topic_id, topic_name, description, short_description) values ('$topicid', '$topic', '$abstract', ' ');\n";
#	print "$1 $2\n";
   }
}
