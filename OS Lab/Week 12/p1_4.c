#include <stdio.h>
#include <stdlib.h>
#define start 53

void sort ( int a[], int n )
{
	int i, j, t;
	for ( i = 0; i < n - 1; i++ )
    {
        for ( j = 0; j < n - i - 1; j++ )
        {
            if ( a[j] > a[j+1] )
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}
void main()
{
    int a[20], b[20], c[20], l = 0, i, n, mov = 0, k = 0, cur = start;
    printf( "Enter request size\n" );
    scanf( "%d", &n );
    printf( "Enter requests" );
    
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &a[i] );
        if ( a[i] < start )
        {
            b[k++] = a[i];
        }
        else
        {
            c[l++] = a[i];
        }
    }
    
    b[k++] = 0;
    c[l++] = 199;
    sort ( b, k );
    sort ( c, l );
    printf( "Head starts at %d ", start );
    printf( " \nHead moves to %d", c[0] );
    for ( i = 1; i < l; i++ )
    {
        mov+= abs( c[i] - c[i - 1] );
        printf( " \nHead moves to %d", c[i] );
    }
    mov+= abs( c[0] - start );
    printf( " \nHead moves to %d", b[0] );
    for ( i = 1; i < k; i++ )
    {
        mov+= abs( b[i] - b[i - 1] );
        printf( " \nHead moves to %d", b[i] );
    }
    printf( "\nThe total head movement is : %d tracks\n", mov );
}
