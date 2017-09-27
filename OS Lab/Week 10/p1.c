#include <stdio.h>
#include <stdlib.h>

void first_fit ( int a[], int n, int p )
{
	int i, c = 0;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] >= p )
		{
			a[i]-= p;
			c = 1;
			break;
		}
	}
	if ( c == 0 )
	{
		printf("\n No memory for process of size %d\n ", p );
	}
}

void best_fit ( int a[], int n, int p )
{
	int i, c = 0, t = 0, sum = 999;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] >= p )
		{
			if ( sum > a[i] - p )
			{
				sum = a[i] - p;
				t = i;
				c = 1;
			}
		}
	}
	if ( c == 1 )
	{
		a[t]-= p;
	}
	else
	{
		printf( "\n No memory for process size %d\n ", p );
	}
}

void worst_fit ( int a[], int n, int p )
{
	int i, c = 0, t = 0, sum = 0;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] >= p )
		{
			if ( sum < a[i] - p )
			{
				sum = a[i] - p;
				t = i;
				c = 1;
			}
		}
	}
	if ( c == 1 )
	{
		a[t]-= p;
	}
	else
	{
		printf( "\n No memory for process size %d\n ", p );
	}
}

void main ()
{
	int i, n, l;
	printf( "\n Enter limit\n " );
	scanf( "%d", &n );
	printf( "\nEnter frame" );
	int a[n], b[n], c[n];
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &a[i] );
		b[i] = c[i] = a[i];
	}
	printf("\nEnter no of processes " );
	scanf( "%d", &l );
	int p[l];
	printf(" \nEnter processes " );
	for ( i = 0; i < l; i++ )
	{
		scanf("%d", &p[i] );
	}
	printf("First Fit\n");
	for (i = 0; i < l; i++ )
	{
		first_fit( a, n, p[i]);
	}
	for ( i = 0; i < n; i++ )
	{
		printf( "%d\t", a[i] );
	}
	printf( "\nBest Fit \n" );
	for (i = 0; i < l; i++ )
	{
		best_fit( b, n, p[i]);
	}
	for ( i = 0; i < n; i++ )
	{
		printf( "%d\t", b[i] );
	}
	printf( "\nWorst Fit\n" );
	for (i = 0; i < l; i++ )
	{
		worst_fit( c, n, p[i]);
	}
	for ( i = 0; i < n; i++ )
	{
		printf( "%d\t", c[i] );
	}

}
