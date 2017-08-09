#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
	int sockfd,n=1;
	char buf[200];
	struct sockaddr_in cliaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	cliaddr.sin_port=htons(11122);
	connect(sockfd,(struct sockaddr *)& cliaddr,sizeof(cliaddr));
	recv(sockfd,buf,200,0);
	printf("%s", buf );
	int choice;
	printf("\nEnter choice: ");
	scanf("%d",&choice);
	send(sockfd,&choice,sizeof(int),0);
	char file[256];
	while(1)
	{	
		fflush(stdout);
		switch(choice){
			case 3: if(n=recv(sockfd,file,256,0));
					printf("%s\n",file);
					break;
		}
	}
	return 0;
}