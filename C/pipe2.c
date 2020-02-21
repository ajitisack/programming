#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int c;
	char ch;
    int pfd[2];
    pid_t pid;
	FILE *file;

    if (pipe(pfd) == -1)	/* Error creating pipe */ 
	{
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();			/* Create child process */

    if (pid == -1)			/* Error creating child process */ 
	{
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)							/* Child reads from pipe */ 
	{
        close(pfd[1]); 
        while ( read(pfd[0], &ch, 1) > 0 )
            write(STDOUT_FILENO, &ch, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(pfd[0]);
        exit(EXIT_SUCCESS);
    } 
	else									/* Parent writes argv[1] to pipe */ 
	{
        close(pfd[0]);
		file = fopen(*++argv, "r");	
		if ( file == NULL ) file = stdin;
		while ( (c=getc(file)) != EOF )
		{
			ch = c;
			write(pfd[1], &ch, 1);	
		}
        close(pfd[1]);          
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}
