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

$scriptdir = "/home/clio-infra/cgi-bin";
$countrylink = "datasets/countries";

my %dbconfig = loadconfig("$Bin/../clioinfra.config");
$site = $dbconfig{root};
my ($dbname, $dbhost, $dblogin, $dbpassword) = ($dbconfig{dbname}, $dbconfig{dbhost}, $dbconfig{dblogin}, $dbconfig{dbpassword});
my $dbh = DBI->connect("dbi:Pg:dbname=$dbname;host=$dbhost",$dblogin,$dbpassword,{AutoCommit=>1,RaiseError=>1,PrintError=>0});

use Getopt::Long;

my $result = GetOptions(
    \%options,
    'debug=i' => \$DEBUG,
    'topicuri=s' => \$topicuri,
    'indicatoruri=s' => \$indicatoruri,
    'country=s' => \$countryuri,
    'uri=s' => \$uri
);

$topicuri = "topic_" unless ($topicuri);
$indicatoruri = "indicatoruri_" unless ($indicatoruri);

if ($topicuri=~/topic\_(\d+)/)
{
   $topic_ID = $1;
}

if ($indicatoruri=~/indicatoruri\_(\d+)/)
{
    $indicator_id = $1;
    $showindicators= "";
}

if ($countryuri=~/(\d+)/)
{
   $countryid = $1;
   $maincountry = "";
}

if ($dbh)
{
    ($codeshash, $country2idhash, $code2regionhash, $country2regionhash) = loadcodes($dbh);

    while (my ($key, $value) = each %{$country2idhash}) {
      $nameshash{$value} = $key;
    }
    $country = $nameshash{$countryid};
    $maincountry = $country;

    %countries = %{$codeshash} if ($codeshash);
    %country2id = %{$country2idhash} if ($country2idhash);
    %country2region = %{$country2regionhash} if ($country2regionhash);
    %datasets = loaddatasets($dbh);
    %datasetmap = loaddatasets($dbh, 'showmap');

    ($mainregionhash, $regionhash, $roothash) = loadregions($dbh);
    %mainregions = %{$mainregionhash} if ($mainregionhash);
    %regions = %{$regionhash} if ($regionhash);
    %root4regions = %{$roothash} if ($roothash);
    %topics = loadtopics($dbh, $topic);
    %rtopics = reverse %topics;
    %years = loadyears($dbh);
    %id2year = reverse %years;
    %indicators = loadindicators($dbh, $indicator);

    $ind_id = $indicators{$indicator} if ($indicator);
    $ind_id = 1 unless ($ind_id);
    $topic_id = $topics{$topic} if ($topic);
    $topic_id = 1 unless ($topic_id);
}

foreach $topic (sort keys %topics)
{
   $maintopic = $topic if ($topics{$topic} eq $topic_ID);
}

if ($maintopic)
{
   my ($counter, $MAX) = (0, 3);
   foreach $indicator (sort keys %datasets)
   {
	   my ($mainindicator, $indicator_id) = ($indicator, $datasets{$indicator});
     $dID = $datasetmap{$indicator}{topic_id};
	   $validated = validate_dataset($dbh, '', $datasets{$indicator});
     if ($validated && $indicator=~/\w+/ && $dID == $topics{$maintopic})
	   {
	     $showindicators{$indicator} = $indicator_id if ($counter < $MAX);
	     $mainindicators{$indicator} = $indicator_id;
	     $counter++;
	   };
   }
}

if ($maincountry)
{
   my ($counter, $MAX) = (0, 3);
   my $cid = $country2id{$maincountry};
   foreach $indicator (sort keys %datasets)
   {
	   $validated = validate_dataset($dbh, $country2id{$maincountry}, $datasets{$indicator});
	   if ($validated)
	   {
	     $showindicators{$indicator} = $datasets{$indicator} if ($counter < $MAX);
 	     $counter++;
	   };
   }
}

%rind = %datasets;
foreach $indicator (sort keys %rind)
{
  if ($indicator_id eq $rind{$indicator})
  {
    $mainindicator = $indicator;
    $showindicators{$mainindicator} = $indicator_id;
  };
}

my $page;

    $javascript = "
  	<script type=\"text/javascript\">
	    var hidden = new Array;
	    var blockcount = 1;

        function SelectIndicators(block)
        {
            var uri = '';
            for (i=block.options.length - 1; i>=0; i--)
            {
                if (block.options[i].selected == true)
                {
                   uri = uri + '&indicator=' + block.options[i].value;
		               var html = document.getElementById('indicatorfull'+block.options[i].value).innerHTML;
		               if (typeof(html)) { }
		               else
		               {
              			 document.getElementById('indicatorfull'+block.options[i].value).innerHTML = hidden[i];
	             	   }
                }
		            else
		            {
                        hidden[i] = document.getElementById('indicatorfull'+block.options[i].value).innerHTML;
                        document.getElementById('indicatorfull'+block.options[i].value).innerHTML = \"\";
		            }
            }
            return uri;
	      }

        function SelectDates()
        {
            var uri = '';
            var fromdate = document.getElementById('from_date').value;
            var todate = document.getElementById('to_date').value;
            if (fromdate)
            {
               uri = uri + '%26year_from%3D' + fromdate;
            }
            if (todate)
            {
               uri = uri + '%26year_to%3D' + todate;
            }
            return uri;
        }

	      function SelectCountries(countries)
	      {
	          var uri = '';
          	    for (i=countries.options.length - 1; i>=0; i--)
          	    {
              	if (countries.options[i].selected == true)
              	{
                  	  uri = uri + '%26country%3D' + countries.options[i].value;
              	}
          	    }

	          return uri;
	      }

        function ChangeDownload(page)
        {
		      var downloadlink = document.getElementById('downloadlink').href; 
  	     	var addyearuri = SelectDates();
		      var addcountryuri = '';
		      var addindicators = '';
    ";

    unless ($maincountry)
    {
        $javascript.="	addcountryuri = SelectCountries(document.getElementById('countries'));\n"; 
    };

    if ($maintopic || $maincountry)
    {
       $javascript.="	SelectIndicators(document.getElementById('indicators')); \n";
    };

    $javascript.="
		    var downloadurl = document.getElementById('originalurl').value;
		    document.getElementById('downloadlink').href = downloadurl + addcountryuri + addyearuri;
		    if (page < 1)
		    {
		        document.getElementById('downloadlink').href = document.getElementById('downloadlink').href + addindicators;
		    }
            }
           </script>
        ";

    $page.="$javascript\n";

    $pagename = $maincountry || $mainindicator || "&nbsp;$maintopic" || 'General info: '.$mainindicator;
    $pagedescription = ' ' || 'Just some general info about the topic and a small text and/or statistics about the topic';
    $page.= "<div class=\"datasets searchpage\">";
    $page.="<form action=/datasets/searchresults method=\"get\">";

    $page.= "<h3 class=\"indicator-intro\">$pagename</h3>";

    $page.="<table width=\"100%\" border=0 valign=top class=\"indicator-block\">";
    $page.="<tr>";
    $page.="<td width=25% valign=top>\n";
    $page.="<table border=0><tr><td align=center></td></tr><tr><td>$pagedescription</td></tr></table>";
    $page.="</td>\n";
    $page.="<td width=75%  valign=top>
	<table width=100% valign=top border=0>
	<tr>
	  ";

# Year selector
    $page.="
    	<td width=33% valign=top>
        <table width=100% border=0>
          <tr>
		        <td width=1%></td><td class=\"blockname\" colspan=2>years</td>
	        </tr>
	        <tr>
		        <td></td><td width=20%>from</td><td>to</td>
	        </tr>
          <tr>
	          <td></td>
            <td><input type=\"text\" name=\"fromdate\" id\=\"from_date\" value=\"1500\" size=4></td>
		        <td><input type=\"text\" name=\"todate\" id=\"to_date\" value=\"2013\" size=4><br /></td>
          </tr>
        </table>
	    </td>
	  ";

# Indicator selector
if ($maintopic || $maincountry)
{
	my $blockname = 'topics';
  %show = %topics;
	if (keys %mainindicators)
	{
      %show = %mainindicators;
	    $blockname = "indicators";
	}

      %show = %topics;
      %show = %mainindicators if (keys %mainindicators);

	if ($maincountry)
	{
	    %show = %datasets;
	    $blockname = "indicators";
	}

	$page.="
	<td width=33% valign=top>
          <table width=100%>
            <tr>
		<td class=\"blockname\">$blockname</td>
            <tr>
              <td>
	";

	$page.="<select name=\"$blockname\" size=8 style=\"width:90%\" multiple id=\"$blockname\">";
	foreach $topic (sort keys %show)
	{
	    $page.="<option value=\"$topic\">$topic</option>\n";
	}
	$page.="</select>";

	$page.="
              </td>
            </tr>
          </table>
         </td>
	";
};

# Country selector
unless ($maincountry)
{
	$changeindicator = 2 if ($maintopic);
	my $blockname = "country";
	$blocks{$blockname} = "countries";
	%showblock = %countries;

	$page.="
	<td width=33% valign=top>
    <table width=100% border=0>
	    <tr>
    		<td class=\"blockname\">$blockname</td>
	    </tr>
      <tr>
        <td>
	";
	$page.="<select size=8 name=\"$blockname\" id=\"$blocks{$blockname}\" multiple style=\"width:90%\">";
	foreach $country (sort keys %showblock)
	{
	   $page.="<option value=\"$country\">$country</option>\n";
	}
	$page.="</select>
        </td>
      </tr>
    </table>
  </td>
";
}

$page.="
              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td width=100% align=right colspan=3>
        <a href=\"#\" onclick=\"ChangeDownload($changeindicator)\">Apply filter</a>&nbsp;
        </td>
      </tr>
    </table>
  </form>
</div>";

print "$page\n";


# Show indicator teasers
foreach $thisindicator (sort keys %showindicators)
{
    showindicator($dbh, $thisindicator, $showindicators{$thisindicator}, $maincountry);
};


sub showindicator
{
    my ($dbh, $indicator, $indicator_id, $maincountry) = @_;
    my $page;
 
    $country = "Netherlands" unless ($maincountry);

    $params   = "--uri=\"indicator.html?country=$country&indicator=$indicator\" --indicator=\"$indicator\" --indicatorID=\"$indicator_id\"";
    $runchart = `$scriptdir/charts/charts.cgi $params`;
    $runchart=~s/<h2>.+?<\/h2>//gsxi;
    my $pagedescription = ' ' || 'Just some general info about the indicator. A teaser of the indicator. And small text and/or statistics about the topic.';
    $downloadlink = "$site/datasets/download?command=";
    $downloadlink.="indicator%3D$indicator" if ($indicator);
    $downloadlink.="%26country=$maincountry" if ($maincountry);
    $openlink = $downloadlink;
    $downloadlink.="%26zip=$indicator.zip";
    $page.="<div id\=\"indicatorfull$indicator\">";
    $page.="<div class=\"indicator-buttons\">
              <span>
                <a href=\"$downloadlink\" name=\"download\" id=\"downloadlink\" style=\"font-size:12pt;\">&nbsp;download</a>&nbsp;
        		    <input type=\"hidden\" id=\"originalurl\" value=\"$downloadlink\">
              </span>
    ";
  
    if (!$maintopic)
    {
    	$page.="
        <span>
          <a href=\"/visualize?datasetname=$indicator\" style=\"font-size:12pt;\">&nbsp;visualize</a>
        </span>
      ";
    };

    $page.="</div>";

    $intro = "World average of $indicator";
    $intro = "$indicator in $country" if ($maincountry);
		$page.= "<div class=\"indicator-intro\">$intro</div>";
    $page.="<table width=\"100%\" valign=top class=\"indicator-block\">";
    $page.="
	    <tr>
		    <td width=1%></td>
		    <td width=23%>$pagedescription</td>
		    <td width=1%></td>
		    <td width=75%>$runchart</td>
	    </tr>
    </table>
    ";
    $page.="</div>";

    if ($maintopic)
    {
	    $page ="<table width=100% border=0>";
	    $page.="<tr><td width=90%><a href=\"/datasets/indicators?indicatoruri=indicatoruri_$datasets{$indicator}\" style=\"font-size:12pt;\">$indicator</a></td>";
	    $page.="<td width=10%><div class=\"indicator-buttons\"><span>
                    <a href=\"$downloadlink\" name=\"download\" id=\"downloadlink\" style=\"font-size:12pt;\">&nbsp;download</a>&nbsp;
                    <input type=\"hidden\" id=\"originalurl\" value=\"$downloadlink\">
                </span></td>";
	    $page.="</table>";
    }
 
    print "$page";
}


