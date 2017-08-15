#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int status;
	pid_t pid;
	pid=fork();
	switch(pid)
	{
		case -1:perror("Fork failed");
				exit(1);
		case 0: printf("Child sleeping for 10s\n");
				sleep(10);
				printf("Child Terminated\n");
				exit(0);
		default:printf("Parent process\n");
				printf("Waiting ...\n");
				wait(&status);
				printf("Child returned: %d\n",status);
				printf("Parent Terminating\n");
				exit(0);
	}
}