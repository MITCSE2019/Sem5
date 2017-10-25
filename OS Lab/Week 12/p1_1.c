#include <stdio.h>
#include <stdlib.h>
#define start 53

void main()
{
    int a[20], i, n, mov = 0;
    printf( "Enter request size\n" );
    scanf( "%d", &n );
    printf( "Enter requests" );
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &a[i] );
    }
    for ( i = 1; i < n; i++ )
    {
        mov += abs( a[i - 1] - a[i] );
    }
    mov+= abs( start - a[0] );
    printf( "The total head movement is : %d\n", mov );
}