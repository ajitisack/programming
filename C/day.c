#include <stdio.h>
#include <stdlib.h>
#include "ajit.h"

int main(int argc, char *argv[])
{
	int c, y, m, d;
	
	int number;
	int LEAP_YEAR;
	int century_number;
	int year_number; 
	int month_number[13] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

	char *day[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	c=strTonum(substr(argv[1],1,2));
	y=strTonum(substr(argv[1],3,2));
	m=strTonum(substr(argv[1],5,2));
	d=strTonum(substr(argv[1],7,2));

	     if ( y % 400 == 0 ) LEAP_YEAR = 1;
	else if ( y % 100 == 0 ) LEAP_YEAR = 0;
	else if ( y % 4   == 0 ) LEAP_YEAR = 1;
	else                     LEAP_YEAR = 0;

	if ( LEAP_YEAR == 1 )
	{
		month_number[1]--;
		month_number[2]--;
	}

	while(c > 14)
	{	
		if ( c == 15 ) { century_number = 1; break; }
		if ( c == 16 ) { century_number = 0; break; }
		if ( c == 17 ) { century_number = 5; break; } 
		if ( c == 18 ) { century_number = 3; break; }
		c = c - 4;
	}	

	year_number = ( (y / 4) + y ) % 7;

	number = century_number + year_number + month_number[m];	

	number = ( ( number % 7 ) + d ) % 7;

	printf("%s\n", day[number]);

	return 0;
}
