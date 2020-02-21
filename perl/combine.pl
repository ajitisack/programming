use strict;
use warnings;

my $directory = "$ARGV[0]";
my $date;
my $i=0;
my $header="";


open(OUTFILE, ">>$directory.csv");
opendir (DIR, $directory) or die $!;

while (my $file = readdir(DIR)) 
{
	next if ($file =~ m/^\./);
	$date = $file;
	$date =~ s/^EQ(..)(..)(..)\.CSV$/20$3-$2-$1/;
	open(INFILE, "$directory/$file") or die "Error opening $file";
	if ($i == 0)
	{
		$header = readline(INFILE);
		print OUTFILE "BATCH_DATE,$header";
		$i++;
	}
	else
	{
		readline(INFILE);
	}
	while(<INFILE>)
	{	
		chomp;
	 	print OUTFILE "$date,$_\n"; 
	}
	close(INFILE);
	print "$file - $date\n";
}
closedir(DIR);
close(OUTFILE);

