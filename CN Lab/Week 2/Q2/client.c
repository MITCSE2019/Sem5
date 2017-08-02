#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int len,result,sockfd,n=0,m=0;
struct sockaddr_in address;
char  srvmsg[500];
char clntmsg[500];
sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(11111);
len = sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1){
perror("\nCLIENT ERROR");
exit(1);
}


printf("%s\n","Chat Start" );


do
{printf("Client: ");
	gets(clntmsg);
send(sockfd,clntmsg,100,0);
if(strcmp(clntmsg,"QUIT")==0)
		break;
n=recv(sockfd,srvmsg,100,0);
printf("Server: %s\n",srvmsg );
if(strcmp(srvmsg,"QUIT")==0)
		break;

}while(1);
return 0;
}