#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];

     fork();
     pid = getpid();
	 fork();
	 pid = getpid();
     for (i = 1; i <= MAX_COUNT; i++) 
          printf("This line is from pid %d value = %d\n", pid, i);
}
