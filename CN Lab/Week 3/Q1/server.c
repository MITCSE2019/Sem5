#include <stdio.h>
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
	
	send(newsockfd,list,200,0);
	DIR * p;
	struct dirent *d;
	p=opendir(".");
	int choice;
	recv(newsockfd,&choice,sizeof(int),0);
	while(1)
	{
		switch(choice)
		{
			case 3:
					while(d=readdir(p))
						{printf("%s\n",d->d_name);
						 send(newsockfd,d->d_name,256,0);}
					break;
			default: return;
		}
	}

	return;
}
