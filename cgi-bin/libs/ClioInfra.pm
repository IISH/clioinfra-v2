package ClioInfra;

use vars qw(@ISA @EXPORT @EXPORT_OK %EXPORT_TAGS $VERSION);

use Exporter;

$VERSION = 1.00;
@ISA = qw(Exporter);

@EXPORT = qw(

	loaddatasetinfo
	loadcodes
	loadregions
	loadtopics
	loadindicators
	loadyears
	find_dataset
	loadconfig
	loading_dataset_values
	loaddatasets
	loadtemplate
	loadtopicsindicators
  	searchdataset
	getdescriptionfile
	validate_dataset
	find_provider
	load_scales
	update_scales
	);

sub load_scales
{
    my ($dbh, $dataset_id, $scalename, $DEBUG) = @_;
    my ($scale, $mainscale);

    $sqlquery = "select dataset_id, scales from datasets.datasets where 1=1";
    $sqlquery.=" and dataset_id='$dataset_id'";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($datasetID, $scale) = $sth->fetchrow_array())
    {
	$mainscale = $scale;
    };

    my @scales = split(/\s+/, $mainscale);
    return @scales;
}

sub update_scales
{
     my ($dbh, $dataset_id, $scale, $DEBUG) = @_;

     if ($scale=~/\d+/ && $dataset_id)
     {
        $dbh->do("update datasets.datasets set scales='$scale' where dataset_id=$dataset_id");
     }

     return;
}

sub find_provider
{
    my ($dbh, $provider, $DEBUG) = @_;
    my ($provider_id, $mainprovider_id);

    $sqlquery = "select provider_name, provider_id from datasets.providers where 1=1";
    $sqlquery.=" and provider_name='$provider'" if ($provider);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($provider, $provider_id) = $sth->fetchrow_array())
    {
	$mainprovider_id = $provider_id;
    }

    unless ($mainprovider_id)
    {
	$dbh->do("insert into datasets.providers (provider_name, provider_description) values ('$provider', ' ')");
	$mainprovider_id = find_provider($dbh, $provider);
    }

    return $mainprovider_id;
}

sub getdescriptionfile
{
    my ($dbh, $dataset, $DEBUG) = @_;
    my ($descriptionfile);

    $sqlquery = "select dataset_name, dataset_description from datasets.datasets where 1=1";
    $sqlquery.=" and dataset_name='$dataset'";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_name, $dataset_description) = $sth->fetchrow_array())
    {
	$descriptionfile = $dataset_description;
    };

    return $descriptionfile;
}

sub validate_dataset
{
    my ($dbh, $country_id, $indicator_id, $topic_id, $DEBUG) = @_;
    my $count;

    $sqlquery = "select country_id from datasets.indicator_values where 1=1";
    $sqlquery.=" and country_id='$country_id'" if ($country_id);
    $sqlquery.=" and dataset_id='$indicator_id'" if ($indicator_id);
    $sqlquery.=" limit 20";
    print "$sqlquery<br>" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_name, $dataset_description) = $sth->fetchrow_array())
    {
        $descriptionfile = $dataset_description;
	$count++;
    };

    return $count;
}

sub loading_dataset_values
{
    my ($dbh, $dataset_id, $DEBUG, %years) = @_;
    my (%dataset, $type, $max, $min, %values, @array, $arrcount, %known);

    $type = "int";

    # id 	ind_id 	year_id 	country_id 	region_id 	dataset_id 	ind_value_int 	ind_value_float
    #$dataset_id = 16;
    $sqlquery = "select year_id, country_id, ind_value_int, ind_value_float from datasets.indicator_values where dataset_id='$dataset_id' order by ind_value_int desc";
    print "$sqlquery\n" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    my $counter;
    while (my ($year_id, $country_id, $ind_value_int, $ind_value_float) = $sth->fetchrow_array())
    {
	$min = $ind_value_float unless ($counter);
	$counter++;
	my $year = $years{$year_id};
	print "$country_id => $year $ind_value_int => $ind_value_float\n" if ($DEBUG);
	$dataset{$country_id}{$year}{valint} = $ind_value_int;
	push(@array, $ind_value_float) if ($arrcount < 5000 && !$known{$ind_value_float} && $ind_value_float > 0.1 && $ind_value_float < 32000);
	$dataset{$country_id}{$year}{valfloat} = $ind_value_float;
	$dataset{$country_id}{$year}{year} = $year_id;
	$values{"$country_id$year"} = $ind_value_float if ($ind_value_float);

	$max = $ind_value_float if ($ind_value_float > $max && $ind_value_float < 32000);
	$min = $ind_value_float if ($ind_value_float < $min);
	$type = "float" if ($ind_value_float=~/\.\d+/ || $ind_value_float=~/\,\d+/);
	$arrcount++;
#	$known{$ind_value_int}++;
    }

    # Checking for wrong max
    my $avg = int(($max - $min) / 2);
    my %extremum = reverse %values;
    foreach $key (keys %values)
    {
	$up++ if ($values{$key} >= $avg);
    }

    return ($type, $min, $max, $up, \@array, %dataset);
}

sub searchdataset
{
    my ($dbh, $datasetname, $DEBUG) = @_;
    my (%datasets, $dataset_id, $topic, %map);

    $sqlquery = "select d.dataset_name, d.dataset_id, t.topic_name, d.topic_id, d.indicator_id from datasets.datasets as d, datasets.topics as t where d.topic_id=t.topic_id ";
    $sqlquery.=" and dataset_name='$datasetname' " if ($datasetname);
    $sqlquery.=" order by dataset_id desc limit 1";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_name, $dataset_id, $topic, $topic_id, $indicator_id) = $sth->fetchrow_array())
    {
	($thisdataset, $thisdataset_id, $thistopic) = ($dataset_name, $dataset_id, $topic);
    };
   
    return ($thisdataset, $thisdataset_id, $thistopic);
}

sub loaddatasets
{
    my ($dbh, $showmap, $datasetname, $DEBUG) = @_;
    my (%datasets, %map);

    $sqlquery = "select dataset_name, dataset_id, topic_id, indicator_id from datasets.datasets";
    $sqlquery.=" order by dataset_id asc";
    print "$sqlquery<br>" if ($DEBUG);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_name, $dataset_id, $topic_id, $indicator_id) = $sth->fetchrow_array())
    {
	if ($dataset_name!~/test/sxi)
	{
            $datasets{$dataset_name} = $dataset_id if ($dataset_id);
	    $map{$dataset_name}{indicator_id} = $indicator_id;
	    $map{$dataset_name}{topic_id} = $topic_id;
	};
    };

    exit(0) if ($DEBUG);
    return %map if ($showmap);

    return %datasets;
}

sub loadtemplate
{
    my ($dbh, $blockname, $DEBUG) = @_;
    my $template;

    $sqlquery = "select * from block_custom where info='$blockname'";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($bid, $body, $info, $format) = $sth->fetchrow_array())
    {
	$template = $body;
    };

    exit(0) if ($DEBUG);

    return $template;
}

sub loadcodes
{
    my ($dbh, $DEBUG) = @_;
    my (%codes, %country2id, %country2region, %code2region);
    $DEBUG = 0;

    $sqlquery = "select country_name, country_code, country_id, region_id from datasets.countries";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($country, $code, $country_id, $region_id) = $sth->fetchrow_array())
    {
        $codes{$country} = $code if ($code);
	$code2id{$code} = $country_id;
	$code2region{$country} = $region_id;
	print "[DEBUG] $country => $region_id\n" if ($DEBUG);
        $country2id{$country} = $country_id;
        $country2region{$country} = $region_id;

        print "$code;;$country\n" if ($DEBUG);
        if ($code && !$known{$code}) # && (!$filter || $country=~/$filter/i))
        {
            push(@order, $code);
        }
        $known{$code}++;
    };

    exit(0) if ($DEBUG);
    return (\%codes, \%country2id, \%country2region, \%code2region);
}

sub loaddatasetinfo
{
    my ($dbh, $dataset, $DEBUG) = @_;
    my ($dataset_id, $dataset_revision);

    $sqlquery = "select dataset_id, dataset_name, revision from datasets.datasets where 1=1 ";
    $sqlquery.=" and dataset_name='$dataset'";
    $sqlquery.=" order by dataset_id desc limit 1";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($id, $name, $revision) = $sth->fetchrow_array())
    {
	$dataset_id = $id unless ($dataset_id);
	$dataset_revision = $revision;
    }

    return ($dataset_id, $dataset_revision);
}

sub loadregions
{
    my ($dbh, $DEBUG) = @_;
    my (%region_roots, %mainregions, %region2root);

    $sqlquery = "select region_name, region_id, region_root from datasets.regions";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($region, $region_id, $region_root) = $sth->fetchrow_array())
    {
        $regions{$region} = $region_id if ($region_id);
	unless ($region_root)
	{
	    $mainregions{$region} = $region_id;
	}
	else
	{
	    $region_roots{$region} = $region_root;
	    $region2root{$region_id} = $region_root;
	}
        print "$region;;$region_id;$region_root\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    return (\%mainregions, \%regions, \%region_roots, \%region2root);
}

sub loadtopics
{
    my ($dbh, $thistopic, $INS, $DEBUG) = @_;

    $sqlquery = "select topic_name, topic_id from datasets.topics";
    #print "$sqlquery\n";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($topic, $topic_id) = $sth->fetchrow_array())
    {
        $topics{$topic} = $topic_id if ($topic_id && $topic!~/test/i && $topic!~/^\(/);
        print "$topic;;$topic_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    if ($INS && !$topics{$thistopic} && $thistopic=~/\w+/)
    {
	$dbh->do("insert into datasets.topics (topic_name, description) values ('$thistopic', '')");
	print "$thistopic\n";
	%topics = loadtopics($dbh, $thistopic);
    }

    return %topics;

}

sub loadtopicsindicators
{
    my ($dbh, $thisindicator, $DEBUG) = @_;
    my %indicators;

    $sqlquery = "select indicator_name, indicator_id from datasets.indicators";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($indicator_name, $indicator_id) = $sth->fetchrow_array())
    {
        $indicators{$indicator_name} = $indicator_id if ($indicator_id && $indicator_name && $indicator_name!~/test/sxi);
        print "$indicator_name;;$indicator_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    unless ($indicators{$thisindicator})
    {
        $dbh->do("insert into datasets.indicators (indicator_name, indicator_description) values ('$thisindicator', '')");
        %topics = loadtopics($dbh, $thisindicator);
    }

    return %indicators;
}

sub loadindicators
{
    my ($dbh, $thisindicator, $INS, $DEBUG) = @_;
    my %indicators;

    $sqlquery = "select indicator_name, indicator_id from datasets.indicators";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($indicator_name, $indicator_id) = $sth->fetchrow_array())
    {
        $indicators{$indicator_name} = $indicator_id if ($indicator_id && $indicator_name);
        print "$indicator_name;;$indicator_id\n" if ($DEBUG);
    };

    exit(0) if ($DEBUG);

    if ($INS && $indicators{$thisindicator})
    {
        $dbh->do("insert into datasets.indicators (indicator_name, indicator_description) values ('$thisindicator', '')");
        %topics = loadtopics($dbh, $thisindicator);
    }

    return %indicators;
}


sub loadyears
{
    my ($dbh, @years, $DEBUG) = @_;
    my (%years, $changes);

    $sqlquery = "select year_value, year_id from datasets.years";
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($year, $year_id) = $sth->fetchrow_array())
    {
        $years{$year} = $year_id if ($year_id);
        print "$year;;$year_id\n" if ($DEBUG);
    };

    foreach $year (@years)
    {
	if ($year=~/^\d+/)
	{
	    unless ($years{$year})
	    {
	        $dbh->do("insert into datasets.years (year_value) values ($year)");
	        $changes++;
	    }
	};
    }

    %years = loadyears($dbh, @years) if ($changes);
    exit(0) if ($DEBUG);

    return %years;

}

sub find_dataset
{
    my ($dbh, $ind_id, $topic_id, $dataset_name, $author, $DEBUG) = @_;
    my ($thisdataset_id, $thisrevision);

    $sqlquery = "select dataset_id, revision from datasets.datasets where 1=1";
    $sqlquery.=" and dataset_name='$dataset_name'" if ($dataset_name);
    $sqlquery.=" and author='$author'" if ($author);
    $sqlquery.=" and indicator_id=$ind_id" if ($ind_id);
    $sqlquery.=" and topic_id=$topic_id" if ($topic_id);
    $sqlquery.=" order by dataset_id desc limit 1";

#    print "$sqlquery\n";exit(0);
    my $sth = $dbh->prepare("$sqlquery");
    $sth->execute();

    while (my ($dataset_id, $revision) = $sth->fetchrow_array())
    {
	$thisdataset_id = $dataset_id;
	$thisrevision = $revision;
    };

    return ($thisdataset_id, $thisrevision);
};

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
