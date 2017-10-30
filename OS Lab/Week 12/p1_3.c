#include <stdio.h>
#include <stdlib.h>
#define start 53

void main()
{
    int a[20], b[20], c[20], l = 0, t, i, j, n, mov = 0, k = 0, cur = start;
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
    for ( i = 0; i < k - 1; i++ )
    {
        for ( j = 0; j < k - i - 1; j++ )
        {
            if ( b[j] < b[j+1] )
            {
                t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }
    for ( i = 0; i < l - 1; i++ )
    {
        for ( j = 0; j < l - i - 1; j++ )
        {
            if ( c[j] > c[j+1] )
            {
                t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
        }
    }
    printf( "Head starts at %d ", start );
    printf( " \nHead moves to %d", b[0] );
    for ( i = 1; i < k; i++ )
    {
        mov+= abs( b[i] - b[i - 1] );
        printf( " \nHead moves to %d", b[i] );
    }
    mov+= abs( b[0] - start );
    printf( " \nHead moves to %d", c[0] );
    for ( i = 1; i < l; i++ )
    {
        mov+= abs( c[i] - c[i - 1] );
        printf( " \nHead moves to %d", c[i] );
    }
    mov+= abs( b[k - 1] - c[0] );

    printf( "\nThe total head movement is : %d tracks\n", mov );
}
