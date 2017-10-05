#include <stdio.h>
#include <stdlib.h>

int min ( int a, int b )
{
	return a >= b ? b : a;
}
void main ()
{
	int i, j, k, n, opc = 0;
	int a[20][20], b[20][20];
	printf( "\nEnter number of vertices" );
	scanf( "%d",&n );
	printf("\nEnter Weight Matrix( 999 for INFINITY )" );
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			scanf( "%d", &a[i][j] );
			b[i][j] = a[i][j];
		}
	}
	for ( k = 0; k < n; k++ )
	{
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
					opc++;
					b[i][j] =  min( b[i][j], ( b[i][k] + b[k][j] ) );
				
			}
		}
	}
	printf("\n The resultant matrix is :\n" );
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			printf( "%d\t", b[i][j] );
		}
		printf( "\n" );
	}
	printf( "\n Operation Count : %d", opc );
}