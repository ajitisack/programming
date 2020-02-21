#!/usr/bin/perl

### Subroutine for isInt ###
sub isInt {
	my ($data, $nullable) = @_;
	if ( $data =~ m/^ *[0-9+-][0-9]* *$/ ) {
		return 0;
	}
	return 1;
}

print "$ARGV[0] - ".isInt($ARGV[0])."\n";

