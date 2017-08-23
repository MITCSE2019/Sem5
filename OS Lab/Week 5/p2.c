#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* summ_child( int* param )
{
	int a = (int)param;
	int i, sum = 0;
	for ( i = 0; a[i] != -1; i++ )
	{
		sum+= a[i];
	}
	return sum;
}

void main ()
{
	int f[100];
	int n,i;
	int *sum;
	printf("\nEnter limit\n");
	pthread_t thread;
	scanf ("%d", &n );
	printf("Enter numbers :\n" );
	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &f[i] );
	}
	f[i]=-1;
	pthread_create ( &thread, 0, &summ_child, f );
	pthread_join(thread,&sum );
	printf("The result is : %d", sum );
}	
