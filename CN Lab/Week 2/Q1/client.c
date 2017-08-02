#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int len,result,sockfd,n=1;
struct sockaddr_in address;
char  time[500];
sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(12245);
len = sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1){
perror("\nCLIENT ERROR");
exit(1);
}

n=recv(sockfd,time,100,0);
printf("Server time is : %s",time);
return 0;
}