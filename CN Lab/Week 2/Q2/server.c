#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNO 11111

void main()
{
	


	int sockfd,newsockfd,portno,clilen,n=1;
	
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	
	char  srvmsg[500];
	char clntmsg[500];
	listen(sockfd,1);
	clilen = sizeof(clilen);
	newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
	
	printf("%s\n","Chat Start" );


	do
	{n=recv(newsockfd,clntmsg,100,0);
	printf("Client: %s",clntmsg );
	if(strcmp(clntmsg,"QUIT")==0)
		break;
	printf("\nServer: ");
	gets(srvmsg);
	send(newsockfd,srvmsg,100,0);
	if(strcmp(srvmsg,"QUIT")==0)
		break;
	}while(1);
	
	
}