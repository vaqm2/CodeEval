#!/usr/bin/env perl                                                                                                          

use strict;
use warnings;
use IO::File;

my $fh = IO::File->new("$ARGV[0]");
my @matrix;

while(my $line = $fh->getline)
{
    chomp($line);

    my ($rows, $cols, $elements) = split(/\;/,$line);
    my @elementArray = split(/\s+/,$elements);
    my $index = 0;

    for my $row(0..$rows-1)
    {
        for my $col(0..$cols-1)
        {
            $matrix[$row][$col] = $elementArray[$index];
            $index++;
        }
    }

    my $print = 0;
    my $totalElements = $rows*$cols;
    my $row = 0;
    my $col = 0;

    while(1)
    {
        for(my $index = $col; $index <= $cols-1; $index++) #Move Right                                                       
        {
            print $matrix[$row][$index]." ";
            $print++;
        }
        $row++;    
	print "\n" and last if($print == $totalElements);
        for(my $index = $row; $index <= $rows-1; $index++) #Move down                                                        
        {
            print $matrix[$index][$cols-1]." ";
	    $print++;
        }
        $cols--;
	print "\n" and last if($print == $totalElements);
        for(my $index = $cols-1; $index >= $col; $index--) #Move left                                                        
        {
            print $matrix[$rows-1][$index]." ";
            $print++;
        }
        $rows--;
	print "\n" and last if($print == $totalElements);
        for(my $index = $rows-1; $index >= $row; $index--) #Move up                                                          
        {
            print $matrix[$index][$col]." ";
            $print++;
        }
        $col++;
        print "\n" and last if($print == $totalElements);
    }
}

$fh->close;
