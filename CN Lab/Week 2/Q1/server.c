#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 12245

void main()
{
	
	// printf ( "Current local time and date: %s", asctime (localtime(&t)) );

	int sockfd,newsockfd,portno,clilen,n=1;
	char * servertime;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	
	//For Concurrent Server
	// while(1)
	// {
	time_t t;
	time(&t);
	listen(sockfd,1);
	clilen = sizeof(clilen);
	newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
	servertime = asctime (localtime(&t));
	n = send(newsockfd,servertime,100,0);
	//}
	
}