#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>
#define PORTNO 12241

void main()
{
	
	int sockfd,newsockfd,portno,clilen,n=1;
	char * servertime;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,1);
	clilen = sizeof(clilen);
	 while(1)
	{
	 newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);		
	 if(fork()==0){
	 	int p=getpid();
	 	printf("Pid is %d", p);
		time_t t;
		time(&t);
		servertime = asctime (localtime(&t));
		printf("\n");
		n = send(newsockfd,servertime,100,0);
		send(newsockfd,&p,sizeof(p),0);
		
	}
	}
	
}