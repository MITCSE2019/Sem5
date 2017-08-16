#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
	int sd, i, j;
	char buf[25], buf1[25];
	struct sockaddr_in address;
	struct sockaddr_in sadd, cadd;
	sd=socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(9704);
	printf("Enter integer1, integer2, and operator (space separated):\n");
	scanf("%d %d %s", &i, &j, buf); 
	int len=sizeof(address);
	char str1[25], str2[25];
	sprintf(str1, "%d", i); 
	sprintf(str2, "%d", j); 
	int m= sendto(sd, str1, sizeof(str1), 0, (struct sockaddr*)&address, len);
	int a= sendto(sd, str2, sizeof(str2), 0, (struct sockaddr*)&address, len);
	int b= sendto(sd, buf, sizeof(buf), 0, (struct sockaddr*)&address, len);
	int n = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr*)&cadd, &len);
	printf("The operation yields:\n");
	puts(buf);
	return 0;
}
