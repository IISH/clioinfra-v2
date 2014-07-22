#!/usr/bin/perl

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../libs";

use DB_File;
use DBI;
use ClioInfra;
use ClioTemplates;
$| = 1;

use Getopt::Long;

my $result = GetOptions(
    \%options,
    'csvfile=s' => \$csvfile,
    'all', 'help',
    'topic=s' => \$topic,
    'indicator=s' => \$indicator,
    'year=s' => \$year,
    'country=s' => \$country,
    'command=s' => \$command,
    'uri=s' => \$uri,
    'download=s' => \$download,
    'debug=s' => \$debug
);

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{webdbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh_web = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

my ($content, $datacontent);

my @items = split(/\&/sxi, $command);
#print "COMMAND $command\n";
print '<div class="filters">';
foreach $item (@items)
{
   if ($item=~/topic(\d+)\=(.+)$/)
   {
        $topic = $2;
	$topic=~s/\+/ /g;
#        $topics{$topic} = $1;
        print "Topic: $topic<br>\n" if ($debug);
   }
   if ($item=~/topic\=(\d+)$/)
   {
        $topicID = $1;
        $topic=~s/\+/ /g;
        $topicIDs{$topicID} = $topicID;
#	$topicsql.=" and d.topic_id=$topicID";
        print "Topic: $topicID<br>\n" if ($debug);
   }

   if ($item=~/indicator(\d+)\=(.+)$/)
   {
        $indicator = $2;
        $indicator=~s/\+/\s+/g;
        $indicators{$indicator} = $1;
        print "Indicator: $indicator<br>\n" if ($debug);
   }

   if ($item=~/indicator(\d+)\=(.+)$/)
   {
        $indicator_id = $1;
	$indicatorSQL.="$indicator_id," if ($indicator_id=~/\d+/);
   }

   if ($item=~/indicator(\d+)\=(.+)$/)
   {
        $indicator = $2;
        $indicator=~s/\+/\s+/g;
        $indicators{$indicator} = $1;
        print "Indicator: $indicator<br>\n" if ($debug);
   }
}

foreach $topicID (sort keys %topicIDs)
{
   $topicSQL.="$topicID, ";
}
$topicSQL=~s/\,\s*$//g;
if ($indicatorSQL)
{
    $indicatorSQL=~s/\,\s*$//g;
    $indicatorsql.=" and d.indicator_id in ($indicatorSQL) ";
}

if ($topicSQL)
{
   $topicsql.=" and d.topic_id in ($topicSQL)";
};

my ($notopics, $noindicators);
$notopics++ unless (keys %topics);
$noindicators++ unless (keys %indicators);

$javascript = "on";
if ($javascript)
{
print <<"EOF";
<script language="JavaScript">
function toggle(source) {
  checkboxes = document.getElementsByName('dataset');
  for each(var checkbox in checkboxes)
    checkbox.checked = source.checked;
}
</script>
EOF
}

if ($dbh)
{
    $sqlquery = "select distinct d.dataset_id, d.dataset_name, p.provider_name, t.topic_name, d.create_date, d.revision from datasets.datasets as d, datasets.providers as p, datasets.topics as t where d.provider_id=p.provider_id and t.topic_id=d.topic_id";
    $sqlquery.="$topicsql" if ($topicsql);
    $sqlquery.="$indicatorsql" if ($indicatorsql);
    $sqlquery.=" order by d.dataset_id desc";
    print "$sqlquery<br>" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    my $counter;
    while (my ($id, $name, $provider, $topic, $create_date, $revision) = $sth->fetchrow_array())
    {
	my $show = 1;

	if (!$notopics)
	{
	    $show = 0;
	    foreach $filtertopic (sort keys %topics)
	    {
		$show++ if ($topic=~/$filtertopic/i);
		print "[DEBUG] $show $filtertopic $topic<bR>" if ($DEBUG);
	    }
	};
        $show = 0 if ($name!~/^\w+/);
        $show = 0 if ($showed{$name});

	$name=~s/^Topic\:\s*//g;
	$create_date=~s/\:\d+\+\d+$//;
	if ($show > 0)
	{
	    print "$id|$name|$provider|$topic|$create_date|$revision\n" if ($DEBUG);
            my $color = "#FFFFFF";
            $row++;
	    $dir = "/home/www/clio_infra/8081/clioinfra/htdocs";
	    $zipfile = "$dir/tmp/dataset.zip";
	    #my $zip = `/usr/bin/zip -9 -y -r -q $zipfile $dir/data`;
	    my $file = "/tmp/dataset.zip";
	    #$download = "<a href=\"javascript:void(0);\" NAME=\"Download dataset\" title=\"Dataset\" onClick=window.open(\"$file\",\"Dataset\",\"width=0,height=0,0,status=0,\");>$name</a> ";
	    $download="$name";

            $datacontent.="<tr class=\"topic-row\">\n";
	    $datacontent.= "<td width=2%><input type=checkbox name=dataset value=\"$id\"></td><td class=\"topic-result\" width=40%>$download</td><td class=\"topic-result\">$topic</td><td class=\"topic-result\">$provider</td><td class=\"topic-result last\">$create_date Version $revision</td>";
	    $datacontent.="</tr>";
	};
	$showed{$name} = $id;
	$ids{$name}.="$id,";
    }

    if ($datacontent)
    {
	$content.="<div class=\"datasets searchpage\"><ul>";
	$content.="<form action=\"/datasets/download\" method=\"yes\">";
	$content.="<input type=hidden name=\"command\" value\=\"$command\">";
        $content.= "<table width=100%><tr class=\"topic-title\"><td colspan=2 width=40% class=\"topic-label\">indicator name</td><td class=\"topic-label\">topic name</td><td class=\"topic-label\">data provider</td><td class=\"topic-label last\">latest version</td></tr>\n";
  	$content.="<tr><td width=10 colspan=2><input class=\"firstline\" type=\"checkbox\" onClick=\"toggle(this)\" />&nbsp;&nbsp;select all</td></tr>";
#	$content.="<tr><td><table width=100% bgcolor=#FFFFF><tr><td>\n";
        $content.="$datacontent" if ($datacontent);
	$content.="<tr><td width=10 colspan=2><input type=\"checkbox\" onClick=\"toggle(this)\" />&nbsp;&nbsp;select all</td></tr>";
#	$content.="</tr></td></table></td></tr>";
        $content.="</table>\n";
  $redirect = substr($uri, 1);
	$content.="<input name=\"redirect\" value=\"$redirect\" type=\"hidden\">";
	$content.="<input value=\"ok\" type=\"submit\">";
	$content.="</ul></div><br>";
    }

}

print "$content\n";
#checktopic();

sub checktopic
{
   foreach $dataset (sort keys %showed)
   {
	my $datacheck = $dataset;
	$datacheck=~s/\(.+?\)//g;
        my $query = `/home/www/clio_infra/8081/clioinfra/cgi-bin/backend/tmp/query.pl '$datacheck'`;
        $dataset_id = $showed{$dataset};
        my ($topic_id, $q) = split(/\;\;/, $query);

        if ($topic_id)
        {
	$topic_id=~s/^0//g;
        print "$topic_id $dataset_id<br>";
	$ids="$ids{$dataset}";
	$ids=~s/\,$//g;
	$dbh->do("update datasets.datasets set topic_id=$topic_id where dataset_id in ($ids)");
	print "$dataset;;$dataset_id;;$ids<br>\n";
        }
   }
};
