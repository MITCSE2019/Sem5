#include <stdio.h>
#include <string.h>

void main(int argc, char * argv[])
{
	FILE *fp;
	char fline[100];
	char *newline;
	int i,count=0,occ=0;

	fp= fopen(argv[2],"r");

	//reads till the EOF 
	while(fgets(fline, 100, fp)!= NULL){
		count++;
		if(newline = strchr(fline,'\n'))
			*newline ='\0';
		if (strstr(fline,argv[1])!= NULL){
			printf("%d%s\n",count, fline);
			occ++;
		}
	}

	printf("\nOccurence %d\n",occ);
}