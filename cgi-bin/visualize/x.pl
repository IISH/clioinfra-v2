#!/usr/bin/perl

$main = $ARGV[0];
my $result = diground($main);
print "$main => $result\n";

sub diground 
{
    my ($digit, $DEBUG) = @_;

    while ($digit > 1)
    {
      $digit = $digit / 10;
      $round = sprintf("%.2f", $digit);
      $c++;
      print "$c $digit $round\n" if ($DEBUG);
    } 

    if ($round)
    {
        for ($i=1; $i<=$c; $i++)
        {
	    $round = $round * 10;
        }
        print "$round\n" if ($DEBUG);
    }

    return $round;
};

