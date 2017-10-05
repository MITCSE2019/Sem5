#include <stdio.h>
#include <stdlib.h>
#define SIZE 7 


struct link
{
	int val;
	struct link  * l;
};

void main ()
{
	int n, num, index, i, f = 0, search, key;
	struct link * a[ SIZE ];
	printf( "\nEnter limit\n" );
	scanf( "%d", &n );
	printf( "\nEnter values" );
	for ( i = 0; i < SIZE ; i ++ )
	{
		a[i] = NULL;
	}
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &num );
		index = num % SIZE;
		if ( a[index] == NULL )
		{
			struct link *temp = ( struct link * )malloc ( sizeof ( struct link ) );
			temp -> val = num;
			temp -> l = NULL;
			a[index] = temp;
		}
		else
		{
			struct link * temp = a[ index ];
			while ( temp -> l != NULL )
			{
				temp = temp -> l;
			}
			struct link * t = ( struct link * )malloc ( sizeof ( struct link ) );
			t -> val = num;
			t -> l = NULL;
			temp -> l = t;
		}
		
			
	}
	printf("\n The entered table is : \n ");
		for ( i = 0; i < SIZE - 1; i++ )
		{
			struct link * t = a[i];
			while ( t != NULL )
			{
				printf("Key : %d, Value : %d\t ",i % SIZE , t -> val );
				t = t -> l;
			}
			printf( "\n" );
		}
		printf( "\n Enter value to search " );
		scanf ( "%d", &search );
		key = search % SIZE;
		if ( a[key] == NULL )
		{
			printf( "\n No entry " );

		}
		else
		{
			struct link * temp = a[ key ];
			while ( temp != NULL )
			{
				if ( temp -> val == search )
				{
					f = 1;
					break;
				}
				temp = temp -> l;
			}
		}
		if ( f == 1 )
		{
			printf ( "\nValue found  at index %d", key + 1 );

		}
		else
		{
			printf ("No match found " );
		}

}