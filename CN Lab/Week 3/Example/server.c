#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNO 12270

int main()
{
	int sockfd, newsockfd, portno, clilen, n=1;
	char buf[256];
	struct sockaddr_in seraddr, cliaddr;
	int i,value;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,1);
	clilen=sizeof(clilen);
	while(1)
	{
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		if(fork()==0){
			n=read(newsockfd,buf,sizeof(buf));
			printf("\nMessage from Client %s \n",buf);
			n=write(newsockfd,buf,sizeof(buf));
		}		
	} 
	return 0;
}
