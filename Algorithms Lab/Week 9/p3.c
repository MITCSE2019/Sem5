#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
 
 
struct link
{
    int val;
};
 
void main ()
{
    int n, num, index, i, f = 0, search, key, c, opc = 0;
    struct link  a[ SIZE ];
    printf( "\nEnter limit\n" );
    scanf( "%d", &n );
    printf( "\nEnter values" );
    for ( i = 0; i < SIZE ; i ++ )
    {
        a[i].val = 999;
    }
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );
        index = num % SIZE;
        if ( a[index].val == 999 )
        {
           a[index].val = num;
        }
        else
        {
            c = index;
            index = ( index + 1 ) % SIZE;
            while ( index != c )
            {
                if ( a[ index ].val == 999 )
                {
                    a[ index ].val = num;
                    break;
                }
                else
                {
                    index = ( index + 1 ) % SIZE;
                }
            }
        }        
    }
    printf("\n The entered table is : \n");
        for ( i = 0; i < SIZE; i++ )
        {
            if ( a[i].val != 999 )
                {
                    printf("Key : %d, Value : %d\t ",i % SIZE , a[i].val );
                   
                }
         
            printf( "\n" );
        }
        printf( "\n Enter value to search " );
        scanf ( "%d", &search );
        key = search % SIZE;
        if ( a[key].val  == 999 )
        {
            printf( "\n No entry " );
 
        }
        else
        {
            for ( i = 0; i < SIZE; i++ )
            {
                opc++;
                if ( a[i].val == search )
                {
                    f = 1;
                    key = i;
                    break;
                }
 
            }
        }
        if ( f == 1 )
        {
            printf ( "\nValue found  at index %d", key );
 
        }
        else
        {
            printf ("No match found " );
        }
        printf( "\n The operation count is : %d ",opc );
 
}