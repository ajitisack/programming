#!/usr/bin/perl

sub isDecimal {
	my ($data, $nullable) = @_;
	if ( $data =~ m/^ *[0-9+-][0-9]*\.[0-9]+ *$/ ) {
		return 0;
	}
	return 1;
}

print "$ARGV[0] - ".isDecimal($ARGV[0])."\n";

