#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int sd, ans, i, j;
	char buf[25], str1[25], str2[25];
	struct sockaddr_in sadd, cadd;
	sd=socket(AF_INET, SOCK_DGRAM, 0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(9704);
	int result=bind(sd, (struct sockaddr*)&sadd, sizeof(sadd));
	int len=sizeof(cadd);
	int m= recvfrom(sd, str1, sizeof(buf), 0, (struct sockaddr*)&cadd, &len);
	int a= recvfrom(sd, str2, sizeof(buf), 0, (struct sockaddr*)&cadd, &len);
	int b= recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr*)&cadd, &len);
	printf("The client sent:\n");
	i=atoi(str1);
	j=atoi(str2);
	printf("%d %d %s", i, j, buf);
		
	if(buf[0]=='+')
		ans=i+j;
	else if(buf[0]=='-')
		ans=i-j;
	else if(buf[0]=='/')
		ans=i/j;
	else if(buf[0]=='*')
		ans=i*j;
	sprintf(buf, "%d", ans);
	
	
	int n = sendto(sd, buf, sizeof(buf), 0, (struct sockaddr*)&cadd, len);
	return 0;
}
