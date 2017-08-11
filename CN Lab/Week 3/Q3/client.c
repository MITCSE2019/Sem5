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

sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(11138);
len = sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1){
perror("\nCLIENT ERROR");
exit(1);
}


char sentence[100];
printf("Sentence : ");
gets(sentence);
send(sockfd,sentence,100,0);
char word[100];
printf("Word : ");
gets(word);
send(sockfd,word,100,0);
char replacer[100];
printf("Replacing Word : ");
gets(replacer);
send(sockfd,replacer,100,0);
char newsentence[100];
recv(sockfd,newsentence,100,0);
printf("New Sentence : %s\n",newsentence);
int pid;
recv(sockfd,&pid,sizeof(int),0);
printf("Pid is %d\n", pid);
return 0;
}