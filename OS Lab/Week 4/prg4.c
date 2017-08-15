#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	pid_t pid=fork();
	switch(pid)
	{
		case -1:perror("Fork Failed");
				exit(1);
		case 0: printf("Child sleeping for 5s\n");
				sleep(5);
				printf("Child terminated\n");
				exit(0);
		default:printf("Parent sleeps for 10s\n");
				sleep(10);
				printf("Parent terminated\n");
				exit(0);
	}
}