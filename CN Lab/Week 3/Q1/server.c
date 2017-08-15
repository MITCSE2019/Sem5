#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#define PORTNO 11122

void main()
{
	int sockfd,newsockfd,clilen;
	char list[200]="1. Download\n2. Upload\n3. Display";
	struct sockaddr_in seraddr,cliaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=INADDR_ANY;
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,1);
	clilen=sizeof(clilen);
	newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
	int choice,c;
	char fname[256]="a";
	char buf[200];
	int end=-1;
	DIR * p;
	struct dirent *d;
	FILE * fp;
	while(1)
	{	
		send(newsockfd,list,200,0);
		recv(newsockfd,&choice,sizeof(int),0);
		switch(choice)
		{
			case 1:	recv(newsockfd,fname,256,0);
					fp = fopen(fname,"r");
					if(fp)
					{
						fseek(fp, 0L, SEEK_END);
						int size = ftell(fp);
						send(newsockfd,&size,sizeof(int),0);
						rewind(fp);
						while ((c = fgetc(fp)) != EOF)
						        send(newsockfd,&c,sizeof(int),0);
						fclose(fp);
					}
					else
					printf("File is not present\n");
					break;	 		
			case 2:	fp=fopen("newfile_s","w");
					int size,i=0,c=0;
					recv(newsockfd,&size,sizeof(int),0);
					while(i<size)
					{
						recv(newsockfd,&c,sizeof(int),0);
						//printf("%c",c);
						putc(c,fp);
						i++;
					}
					fclose(fp);
					break;
			case 3:	p=opendir(".");
					while(d=readdir(p))
						send(newsockfd,d->d_name,256,0);
					send(newsockfd,"",256,0);
					break;
			default: exit(0);
		}
	}

	


	return;
}
