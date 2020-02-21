#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int pfd[2];
    pid_t pid;
    char buf;

    if (argc != 2)
	{
    	fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    	exit(EXIT_FAILURE);
    }

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

    if (pid == 0) {    /* Child reads from pipe */
        close(pfd[1]);
        while (read(pfd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(pfd[0]);
        exit(EXIT_SUCCESS);
    } else {            /* Parent writes argv[1] to pipe */
        close(pfd[0]);
        write(pfd[1], argv[1], strlen(argv[1]));
        close(pfd[1]);
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}
