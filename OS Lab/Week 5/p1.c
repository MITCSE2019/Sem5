#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* fib_child( int* param )
{
	int *f = (int*)malloc(100 * sizeof(int));
	f[0] = 0;
	f[1] = 1;
	//int a = (int)param;
	int a=*param;
	int i;
	//print("%d\t %d\t", f[0],f[1] );
	for ( i = 2; i <= a; i++ )
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f;
}

void main ()
{
	int n,i,*f;
	printf("\nEnter limit\n");
	pthread_t thread;
	scanf ("%d", &n );
	pthread_create ( &thread, 0, &fib_child, &n );
	pthread_join(thread,&f);
	printf("\n The result is : ");
	for ( i = 0; i < n; i++ )
	{
		printf("%d\t",f[i]);
	}
	
}
	
