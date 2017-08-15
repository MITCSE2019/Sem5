#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
	int sockfd,n=1;
	char buf[200];
	struct sockaddr_in address;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(11122);
	connect(sockfd,(struct sockaddr *)& address,sizeof(address));
	fflush(stdout);
	int choice;
	char ch='a';
	char file[256]="a";
	FILE * fp;

	 while(1)
	{	strcpy(file,"a");
	 	recv(sockfd,buf,200,0);
	 	printf("%s", buf );
	  	printf("\nEnter choice: ");
	  	scanf("%d",&choice);
	  	send(sockfd,&choice,sizeof(int),0);
	 	switch(choice){
	 		case 1:	printf("Enter File Name: ");
					scanf("%s",file);
					printf("Downloading %s into \"newfile_c\"\n",file );
					send(sockfd,file,256,0);
					fp=fopen("newfile_c","w");
					int size,i=0,c=0;
					recv(sockfd,&size,sizeof(int),0);
					while(i<size)
					{
						recv(sockfd,&c,sizeof(int),0);
						//printf("%c",c);
						putc(c,fp);
						i++;
					}
					fclose(fp);
					break;
			case 2:	printf("Enter File Name: ");
					scanf("%s",file);
					printf("Uploading %s into \"newfile_s\"\n",file );
					fp = fopen(file,"r");
					if(fp)
					{
						fseek(fp, 0L, SEEK_END);
						int size = ftell(fp);
						send(sockfd,&size,sizeof(int),0);
						rewind(fp);
						while ((c = fgetc(fp)) != EOF)
						        send(sockfd,&c,sizeof(int),0);
						fclose(fp);
					}
					else
					printf("File is not present\n");
					break;	
	 		case 3: 
	 				while(strcmp(file,""))
	 				{n=recv(sockfd,file,256,0);
	 				printf("%s\n",file);}
	 				break;
	 		default: exit(0);
	 	}
	 }
	return 0;
}