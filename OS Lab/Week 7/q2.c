#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
//char buf[]="HELLO\0";
int buf[4];
int main(){
	int fd;
	char *myfifo="new";
	int res=mkfifo(myfifo,0666);
	if(res==0)
		printf("file created");
	else
		printf("failed");
	fd=open(myfifo,O_RDWR);
	printf("%d ",fd);
	printf(" Enter 4 numbers");
	for(int i=0;i<4;i++){
		scanf("%d",&buf[i]);
	}
	//buf[5]='\0';
	res=write(fd,buf,sizeof(int)*4);
	printf("%d ",res);
	close(fd);
	unlink(myfifo);
	return 0;
}
