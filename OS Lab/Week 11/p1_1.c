#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3

void main()
{
	int a[20], b[SIZE], check[SIZE], i, j, f, k, index, n, min = 999, d;
	printf( "Enter length of page requests\n" );
	scanf( "%d", &n );
	printf( "Enter the requests\n" );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	memset( b, -1, sizeof( b ) );
	memset( check, 0, sizeof( check ) );
	for ( i  = 0; i < n; i++ )
	{
		f = 0;
		d = 0;
		for ( k = 0; k < SIZE; k++ )
		{
			if ( b[k] == -1 )
			{
				b[k] = a[i];
				printf( "\nPage %d is placed in frame %d \n", a[i], k );
				check[k] = i;
				f = 1;
				break;
			}	
		}
		if ( f == 0 )
		{
			for ( k = 0; k < SIZE; k++ )
			{
				if ( b[k] == a[i] )
				{
					d = 1;
					break;
				}
			}	
		}
		
		if ( f == 0 && d == 0 )
		{
			min = 999;
			for ( k = 0; k < SIZE; k++ )
			{
				if ( min > check[k] )
				{
					min = check[k];
					index = k;
				}
			}
			b[index] = a[i];
			check[index] = i;
			printf( "\nPage %d is placed in frame %d\n", a[i], index );
		}
		
	}
}