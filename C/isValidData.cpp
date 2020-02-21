/*___________________________________________________________________________________*
*                                                                                    *
*  Author        :-  Ajit Isack                                                      *
*  Date Created  :-  20120815                                                        *
*  Organisation  :-  AmBank Group                                                    *
*  Description   :-  This C program checks the validity of data for date, decimal    *
*                    and integer                                                     *
*____________________________________________________________________________________*/

#include <stdlib.h>
#include <stdio.h>

int isValidData(char* type, char* data);

/*------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
       if (argc != 3)
       {
               printf("Usage   : %s <int|decimal|date> <data>\n", argv[0]);
               printf("Example : %s date 20120102\n", argv[0]);
               exit (1);
       }
       printf("%d\n", isValidData(argv[1], argv[2]));
       return (isValidData(argv[1], argv[2]));
}
------------------------------------------------------------------------------------*/

int isValidData(char* type, char* data)
{
       int i, j, flag;
       int LEAP_YEAR = 0;
       int yy, mm, dd;
       yy = mm = dd = 0;
       int numberOfDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

       if ( *data == 0 ) return 1;

       if ( *type == 'd' && *(type+1) == 'a' )
       {
               i = -1;
               while( data[++i] != 0 && data[i] >= '0' && data[i] <= '9' );
               if ( i != 8 ) return 1;

               i = 8; j = 1;
               while( --i >= 0 )
               {
                           if ( i == 5 || i == 3 ) j = 1;
                           if ( i <= 7 && i >= 6 ) dd = dd + ( (data[i] - 48 ) * j );
                           if ( i <= 5 && i >= 4 ) mm = mm + ( (data[i] - 48 ) * j );
                           if ( i <= 3 && i >= 0 ) yy = yy + ( (data[i] - 48 ) * j );
                           j = j * 10;
               }

               if ( yy < 1500 ) return 1;

               if ( mm > 12 || mm < 1 ) return 1;

               if ( dd > 31 || mm < 1 ) return 1;

               if ( dd > 30 && (mm == 4 || mm == 6 || mm == 9 || mm == 11) ) return 1;

               if ( mm == 2 )
               {
                                if ( yy % 400 == 0 ) LEAP_YEAR = 1;
                           else if ( yy % 100 == 0 ) LEAP_YEAR = 0;
                           else if ( yy % 4   == 0 ) LEAP_YEAR = 1;
                                                else LEAP_YEAR = 0;
                       if (  LEAP_YEAR && dd > 29 ) return 1;
                       if ( !LEAP_YEAR && dd > 28 ) return 1;
               }
               return 0;
       }
       if ( *type == 'i' )
       {
               i = 0;
               if ( data[i] != 0 && data[i] != '+' && data[i] != '-' && (data[i] < '0' || data[i] > '9') ) return 1;
               if ( ( data[i] == '+' ||  data[i] == '-' ) && data[i+1] == 0 ) return 1;
               while( data[++i] != 0 ) if ( data[i] < '0' || data[i] > '9' ) return 1;
               return 0;
       }
       if ( *type == 'd' && *(type+1) == 'e' )
       {
               flag=0;
               i = 0;
               if ( data[i] != 0 && data[i] != '+' && data[i] != '-' && (data[i] < '0' || data[i] > '9') && data[i] != '.' ) return 1;
               if ( data[i] == '.' ) flag = 1;
               while( data[++i] != 0 )
               {
                       if ( flag == 0 && data[i] == '.' )
                       {
                                flag = 1;
                                continue;
                       }
                       if ( flag == 1 && data[i] == '.' ) return 1;
                       if ( data[i] < '0' || data[i] > '9' ) return 1;
               }
               return 0;
       }
       return 1;
}


//____________________________________________________________________________________//
