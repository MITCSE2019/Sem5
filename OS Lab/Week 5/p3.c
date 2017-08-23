#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void* prime_child( int* param )
{
	
	int a, b, k = 0, f[100];
	a = param[0];
	b = param[1];
	int i, j,check = 0, c;
	for ( i = a; i <= b; i++ )
	{
		c = i;
		for ( j = 2; j <= i/2; j++ )
		{
			if ( c % j == 0 )
			{
				check = 1;
				break;
			}
		}
		if ( check == 0 )
		{
			f[k++] = i;
		}
		check = 0; 
	}
	printf("\n The result is :");
	for ( i = 0; i < k; i++ )
	{
		if ( f[i] != 1 )
		{
			printf("%d\t", f[i] );
		}
	}
	
}

void main ()
{
	int n,i, arr[20];
	printf("\nEnter limits\n");
	pthread_t thread;
	scanf ("%d %d", &arr[0], &arr[1] );
	pthread_create ( &thread, 0, &prime_child, arr );
	pthread_join(thread,0 );
	
}	
