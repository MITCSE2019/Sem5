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
		case -1:perror("Fork failed\n");
				exit(1);
		case 0: printf("Parent pid (Child):\t%d\n",getppid());
				printf("Pid (Child):\t\t%d\n",getpid());
				printf("Child pid (Child):\t%d\n",pid);
				exit(0);
		default:printf("Parent pid (Parent):\t%d\n",getppid()); //prints pid of shell
				printf("Pid (Parent):\t\t%d\n",getpid());
				printf("Child pid (Parent):\t%d\n",pid); 
				exit(0);
	}
}