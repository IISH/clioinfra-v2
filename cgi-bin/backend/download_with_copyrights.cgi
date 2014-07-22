#!/usr/bin/perl

$file = $ARGV[0];

#<body onload=\"javascript: poponload();\">
$pagejava = "
<script type=\"text/javascript\">
function poponload()
{
    testwindow = window.open(\"$file\", \"mywindow\", \"location=1,status=1,scrollbars=1,width=100,height=100\");
    testwindow.moveTo(0, 0);
}
</script>
";

$page = "
<body onload=\"javascript: window.location.assign('$file');\">
<p>
Problems with the download? Please use this <a href=\"javascript:void(0);\" NAME=\"Download dataset\" title=\"Dataset\" onClick=window.open(\"$file\",\"Dataset\",\"width=0,height=0,0,status=0\")>direct link</a>
</a>
</p>
</body>
";

print "$page\n";
