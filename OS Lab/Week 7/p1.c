#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pfd[2];
    pid_t cpid;
    char buf;
    if(pipe(pfd)==-1)
    {
	    perror("pipe");
	    exit("EXIT_FAILURE");
    }
    cpid=fork();
    if(cpid==0)
    {
	    close(pfd[1]);
	    while(read(pfd[0],&buf,1)>0)
	    write(STDOUT_FILENO,&buf,1);
	    write(STDOUT_FILENO,"\n",1);
	    close(pfd[0]);
	    exit(EXIT_SUCCESS);
    }
    else
    {
	    close(pfd[0]);
	    printf("writer please enter the value\n");
	    char buf[200];
	    scanf("%s",buf);
	    write(pfd[1],buf,strlen(buf));
	    close(pfd[1]);
	    wait(NULL);
	    exit(EXIT_SUCCESS);
    }
}
