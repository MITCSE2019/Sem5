#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#define PORTNO 9736

void main(){
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address,client_address;
	int result;
	fd_set readfds,testfds;
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=htonl(INADDR_ANY);
	server_address.sin_port=htons(PORTNO);
	server_len = sizeof(server_address);
	bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
	listen(server_sockfd,5);
	FD_ZERO(&readfds);
	FD_SET(server_sockfd,&readfds);
	while(1){
		char ch;
		int fd;
		int nread;
		testfds = readfds;
		printf("server waiting\n");
		result = select(FD_SETSIZE,&testfds,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
		if(result<1){
			perror("server 5");
			exit(1);
		}
		int c=0;
		char buf[200],d[200];
		for(fd=0;fd<FD_SETSIZE;fd++){
			if(FD_ISSET(fd,&testfds)){
				if(fd==server_sockfd){
					client_len = sizeof(client_address);
					client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
					struct tm *info;
					time_t rawtime;
					time( &rawtime );
					info = localtime( &rawtime );
					strcpy(buf,asctime(info));
					
					FD_SET(client_sockfd,&readfds);					
					printf("adding client on fd %d\n",client_sockfd );
				}else{
					ioctl(fd,FIONREAD,&nread);
					if(nread==0){
						close(fd);
						FD_CLR(fd,&readfds);
						printf("removing client on fd %d\n",fd );
					}else{
						read(fd,d,sizeof(d));
						sleep(1);
						printf("serving client on fd %d\n",fd );						
						write(fd,buf,sizeof(buf));						
					}
				}
			}
		}
	}
}
