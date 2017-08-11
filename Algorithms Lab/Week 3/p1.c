#include <stdio.h>
#include <stdlib.h>

int bubble_sort ( int a[50], int n )
{
	int i,j,opc = 0;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = 0; j < n-i-1; j++ )
		{
			opc++;
			if( a[j] > a[j+1] )
			{
				a[j]+= a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j]-= a[j+1];
			}
		}
	}
	return opc;
}


void main()
{
	int a[50],n,i,opc = 0;
	printf("\nEnter limit\n");
	scanf("%d",&n);
	printf("\nEnter numbers : \n");
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d",&a[i] );
	}
	opc = bubble_sort( a, n );
	printf("\nThe sorted array is : " );
	for ( i = 0; i < n; i++ )
	{
		printf( "\t%d\t",a[i] );
	}
	printf("\nThe opeation count is : %d",opc );
}