#!/usr/bin/perl

use CGI;
print "Content-type: text/html\n\n";

use vars qw/$libpath/;
use FindBin qw($Bin);
BEGIN { $libpath="$Bin" };
use lib "$libpath";
use lib "$libpath/../lib";

#$DIR = "/home/www/clio_infra/8080/clioinfra/cgi-bin";
$DIR = $Bin;

my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);

if ($year)
{
   $year+=1900;
   $mon++;
   $date = sprintf("%04d-%02d-%02dT%02d:%02d:%02dZ", $year, $mon, $mday, 23, 59, $sec);
   $editdate = sprintf("%04d%02d%02dT%02d%02d%02d", $year, $mon, $mday, $hour, $min, $sec);

   $publiceditdate = sprintf("%04d-%02d-%02d", $year, $mon, $mday);
};

# read form data into hash
$query = new CGI;
%data = $query->Vars();
my $DEBUG = 1;

foreach $param (sort keys %data)
{
   if ($param=~/file(\d+)/i)
   {
	$id = $1;
	$uploadfiles[$id] = $data{$param};
	$idlast = $id if ($idlast < $id);
        print "[DEBUG] $id $param $data{$param}<br>" if ($DEBUG eq 1);
   }
}

#$user = "admin";
$user = $data{user};
$uploaddir = "$DIR/../htdocs/uploads";
$userupload = "/uploads/$user" if ($user);
mkdir $uploaddir unless -e ($uploaddir);
$uploaddir.="/$user" if ($user);

$tmpdir = $data{tmpdir};
$tmpdir = sprintf("%04d%02d%02dT%02d%02d%02d", $year, $mon, $mday, $hour, $min, $sec) unless ($tmpdir);
if ($tmpdir)
{
   $uploaddir.="/$tmpdir";
   $userupload.="/$tmpdir";
};
mkdir $uploaddir unless -e ($uploaddir);

open(template, "$DIR/wiki/template.tpl");
@content = <template>;
close(template);

my $filename = $data{file};
$upload_filehandle = $query->upload(file);
$idlast++;
if ($upload_filehandle)
{
   $uploadfiles[$idlast] = $upload_filehandle;
   $data{"fileactive$idlast"} = 1;
   print "$idlast $uploadfiles[$idlast] <Br>" if ($DEBUG eq 1); 
}

print "$filename<br />";
if ($filename)
{
    $output_file = "$uploaddir/$filename";

    open UPLOADFILE, ">$output_file";
    while ( <$upload_filehandle> )
    {
	print UPLOADFILE;
    }
    close UPLOADFILE;
};

if ($data{title})
{
    $version = "1.0" unless ($version);
    $data{changelog} = "<a href=\"\">changelog_$version.txt</a>";
    $data{download} = "<a href=\"\">download_$version.txt</a>";
    $item = "$version;;$data{description};;$data{edit_date};;$data{author};;$data{status};;$data{changelog};;$data{download}";
    push(@datasets, $item);
}

#enctype="multipart/form-data"
$upload_title = "Upload new revision";
$upload_title = $data{title} if ($data{title});

$revision = showrevision() if ($data{title});

$content.= "
<form method=\"post\" enctype=\"multipart/form-data\" action=\"/upload/\"> 
<input type=hidden name=tmpdir value=\"$tmpdir\">
<table with=100% border=0><tr>
<td>
<h2>$upload_title / Edit</h2>
$revision
	<table border=1><tr><td>
	File:
	<input type=\"file\" name=\"file\" value=\"$filename\" />
	<input type=\"submit\" name=\"submit\" value=\"Submit\" />
	<br />
	</td></tr>
	<tr><td align=left>
		<small><font color=red>Note: File for upload must be of the .XLS(X), .DOC or .TXT</font></small>
	</td></tr></table>
";

$UPLOAD = TRUE if ($#uploadfiles);
if ($UPLOAD)
{
$content.="<table border=0><tr><td>Dataset files:</td></tr>";

   for ($i=0; $i<=$#uploadfiles; $i++)
   {
 	$file = $uploadfiles[$i];

	unless ($known{$file})
	{
	   $linkfile = "$uploaddir/$file";
	   my $true = 1;

	   $true = 0 if (-z $linkfile);
	   $true = 0 unless (-e $linkfile);
	   $true = 0 unless ($file);
	   unless ($data{"fileactive"."$i"})
	   {
		$true = 0;
		unlink $linkfile;
	   }

	   if ($true)
           {
$content.="
	<tr><td><input type=checkbox name=fileactive$i checked><a href=\"$userupload/$file\">$file</a></td></tr>
	<input type=hidden name=\"file$i\" value=\"$file\">
";
           }
	}

	$known{$file}++;
   };
$content.="</table>";
};

$content.="
	</td>
	</tr></table>
<table border=1 width=100%><tr><td>
Title:&nbsp;<input size=\"80\" maxlength=\"42\" name=\"title\" value=\"$data{title}\" type=\"text\"> <br>
</td></tr>
<tr><td>
	<table><tr>
		<td width=50%>
		Author:<font color=red><sup>*</sup></font>&nbsp;<input size=\"60\" maxlength=\"150\" name=\"author\" value=\"$data{author}\" type=\"text\"> <br></td>
		<td width=50%>Creation Date:<input size=\"40\" maxlength=\"12\" name=\"create_date\" value=\"$data{create_date}\" type=\"text\"></td>
	</tr>
	<tr>
		<td>Topic<font color=red><sup>*</sup></font>:<input size=\"60\" maxlength=\"150\" name=\"topic\" value=\"$data{topic}\" type=\"text\"></td>
		<td>Last Modified: <input size=\"40\" maxlength=\"12\" name=\"edit_date\" value=\"$data{edit_date}\" type=\"text\"></td>
	</tr>
        <tr>
                <td>Indicator<font color=red><sup>*</sup></font>:<input size=\"40\" maxlength=\"150\" name=\"indicator\" value=\"$data{indicator}\" type=\"text\"></td>
                <td>Status:<font color=red><sup>*</sup></font> <select name=\"status\">
		<option value=\"1\">Public</option>
		<option value=\"0\">Private</option>
		</td>
        </tr>
        <tr>
                <td>Tags:<input size=\"40\" maxlength=\"150\" name=\"tags\" value=\"$data{tags}\" type=\"text\"></td>
                <td>Current version: <select name=\"version\">
                <option value=\"1\">Active</option>
                <option value=\"0\">Archive</option>
                </td>
        </tr>

	</table>
</td></tr>
<tr><td valign=top>
	Description<font color=red><sup>*</sup></font>: <textarea rows=\"3\" cols=\"140\" name=\"description\">$data{description}</textarea>
</td></tr>
        <tr>
	<td>
	<table width=100% align=center><tr>
        <td align=center width=90%>
                <small><font color=red>Note: Fields marked with * are required to save dataset</font></small>
        </td><td align=center widht=10%><input type=\"submit\" name=\"submit\" value=\"Save\" />
        </td></tr>
	</table>
	</td></tr>
</table>

</form>
";

foreach $str (@content)
{
   $str=~s/\%\%content\%\%/$content/g;
   push(@result, $str);
}

if (keys %data)
{
   open(output, ">$uploaddir/dataset.info");
   foreach $item (sort keys %data)
   {
	print output "$item;;$data{$item}\n";
   }
   close(output);
}

print "@result\n";

sub showrevision
{
   $revision = "
<p></p>
<table><tr bgcolor=#efefef>
<td width=10%>Version</td><td align=center>Abstract</td><td>Author</td><td>Status</td><td>Change log</td><td>Download</td><td>Delete</td>
</tr>
";

    $item = "0.2;;Note 1;;March 1 2012;;Reinoud Bosh;;public;;<a href=\"/changelog.txt\">changelog.txt</a>;;<a href=\"/version\">version 0.1</a>";
#    push(@datasets, $item);
    $item = "0.1;;Note 2;;December 2 2011;;Reinoud Bosh;;public;;<a href=\"/changelog.txt\">log</a>;;<a href=\"/version\">version 0.2</a>";
#    push(@datasets, $item);
    foreach $item (@datasets)
    {
        my ($version, $notes, $update_date, $author, $status, $changelog, $download) = split(/\;\;/, $item);
	$status.=", $update_date";
        $revision.="<tr><td width=10%>$version</td><td>$notes</td><td>$author</td><td>$status</td><td>$changelog</td><td>$download</td><td>X</td></tr>";
    }

    $revision.="</table>\n";

    return $revision;
}
