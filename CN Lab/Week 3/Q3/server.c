#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNO 11138

void main()
{
	int sockfd,newsockfd,portno,clilen,n=1;
	
	struct sockaddr_in seraddr,cliaddr;
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
			char sentence[100],word[100],replacer[100],newsentence[100];
			recv(newsockfd,sentence,100,0);
			recv(newsockfd,word,100,0);
			recv(newsockfd,replacer,100,0);		
			
			int len = strlen(replacer);
			int pos = strstr(sentence,word)-sentence;
			int i,j,k;
			int c=0;
			for(i=0;i<pos;i++)
				newsentence[c++]=sentence[i];
			for(j=0;j<len;j++)
				newsentence[c++]=replacer[j];
			i+=strlen(word);
			for(;i<strlen(sentence);i++)
				newsentence[c++]=sentence[i];
			newsentence[c]='\0';
			send(newsockfd,newsentence,100,0);
			int pid=getpid();
			printf("Pid is %d\n", pid);
			send(newsockfd,&pid,sizeof(int),0);
			return;
		}
		
	}

}