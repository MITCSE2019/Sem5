#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int string_matching ( char t[50], char p[50] )
{
	int i,l_t,l_p,j,opc = 0;
	l_t = strlen(t);
	l_p = strlen(p);
	for ( i = 0; i < l_t - l_p; i++ )
	{
		opc++;
		j = 0;
		while ( j < l_p && p[j] == t[i+j] )
			{
				j++;
				opc++;
			}
		
		if ( j == l_p )
			{
				printf( "\nOperation count : %d",opc );
				return i;
			}
	}
	printf( "\nOperation count : %d",opc );
	return -1;
}

void main ()
{
	char p[50],t[50];
	int res;
	printf("\nEnter text\n");
	gets(t);
	printf("\nEnter pattern to search\n");
	gets(p);
	res = string_matching( t,p );
	if ( res != -1 )
	{
		printf("\nMatch found at pos %d in text\n",res+1 );
	}
	else
	{
		printf("\nNo match found\n");
	}
}