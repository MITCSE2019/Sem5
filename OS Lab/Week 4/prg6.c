#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int fd=open("newfile",444);
	int len=lseek(fd,0,SEEK_END);
	lseek(fd,-len,SEEK_CUR);
	char * buf = (char *)malloc(len);
	int fd2=creat("copyfile",444);
	read(fd,buf,len);
	write(fd2,buf,len);
}