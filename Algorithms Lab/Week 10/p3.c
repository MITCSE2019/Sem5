#include <stdio.h>
#include <stdlib.h>

int opc;
int max ( int a, int b )
{
	return a >= b ? a : b;
}


int knap_sack ( int cap, int w[], int val[], int n )
{
	opc++;
	if ( n == 0 || cap == 0 )
	{
		return 0;
	}
	else if ( w[n - 1] > cap )
		{
			return knap_sack ( cap, w, val, n - 1 );
		}
		else
		{
			return max( val[n - 1] + knap_sack ( cap - w[n - 1], w, val, n - 1 ), knap_sack ( cap, w, val, n - 1) ); 
		}
}

void main ()
{
	int n, w[20], val[20], cap, i;
	printf("\n Enter no of items " );
	scanf( "%d", &n );
	printf("\n Enter Knapsack capacity " );
	scanf( "%d", &cap );
	printf("\n Enter weight and value for each item " );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &w[i] );
		scanf( "%d", &val[i] );
	}
	printf("\nThe optimum solution is : %d ", knap_sack (cap, w, val, n ) );
	printf( "\nOperation Count : %d", opc );
}