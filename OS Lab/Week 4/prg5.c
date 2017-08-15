#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
	int fd=creat("newfile",444);
	char buf[50];
	printf("Enter message\n");
	gets(buf);
	write(fd,buf,strlen(buf));
}