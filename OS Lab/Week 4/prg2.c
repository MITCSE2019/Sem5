#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	pid_t pid;
	pid=fork();
	switch(pid)
	{
		case -1:perror("Fork Failed");
				exit(1);
		case 0: printf("Child replaced with prg1\n");
				execl("prg1","prg1",NULL);
				exit(0);
		default:printf("Parent of prg2\n");
				wait(NULL);
				exit(0);
	}
}