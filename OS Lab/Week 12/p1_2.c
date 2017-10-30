#include <stdio.h>
#include <stdlib.h>
#define start 53

void main()
{
    int a[20], i, n, mov = 0, min = 1000, visited[20] = { 0 }, index, k = 0, cur = start;
    printf( "Enter request size\n" );
    scanf( "%d", &n );
    printf( "Enter requests" );
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &a[i] );
    }
    printf( "Head starts at %d ", start );
    while ( k < n )
    {
        for ( i = 0; i < n; i++ )
        {
            if ( abs( cur - a[i] ) < min && visited[i] == 0 )
            {
                min = abs( cur - a[i] );
                index = i;
            }
        }
        mov+= min;
        visited[index] = 1;
        k++;
        min = 1000;
        cur = a[index];
        printf( " \nHead moves to %d", cur );
    }
    printf( "\nThe total head movement is : %d tracks\n", mov );
}
