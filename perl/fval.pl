#!/usr/bin/perl

#************************#
#  Author - Ajit Isack   #
#  Date   - 2013 Nov 05  #
#************************#

#use strict;
use Tie::File;

my $i=0;
my $j=-1;
my $data;
my @col_name;
my @type;
my @start;
my @lenght;
my @nullable;
my $errStr="";

my %list = ( 
'int' => 1, 
'integer' => 1, 
'number' => 1, 
'decimal' => 2, 
'date' => 3, 
'char' => 4, 
'varchar' => 4, 
'alpha' => 4, 
'alphanum' => 5, 
);


### Tie metadata and data files to different arrays ###
tie @metadataFile, 'Tie::File', "metadata.txt";
tie @dataFile, 'Tie::File', "data.txt"; 


### Keep metadata in different arrays ###
for(@metadataFile) {
	$j++;
	( $col_name[$j], $type[$j], $start[$j], $length[$j], $nullable[$j] ) = split ':';		
}


### Subroutine for isInt ###
sub isInt {
	my ($data, $nullable) = @_;
	if ( $data =~ m/^[0-9+-][0-9]*$/ ) {
		return 0;
	}
	return 1;
}


### Loop through each record in data file ###
for(@dataFile) {
	for $i (0..$j) {
		$data=substr $_, $start[$i] - 1, $length[$i];
		if ( $list{lc($type[$i])} == 1 ) {	
			if ( isInt($data, lc($nullable[$i])) == 1 ) {
				$errStr=$errStr . "~Invalid $col_name[$i]($type[$i]) - [$data]";
			} 
		}
	}
	print "$_$errStr\n";
	$errStr="";
}

### Untie metadata and data array ###
untie @metadataFile;
untie @dataFile;
