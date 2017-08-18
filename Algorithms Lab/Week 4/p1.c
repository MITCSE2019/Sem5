#include <stdio.h>
#include <stdlib.h>
 
int callit( int arr[][100],int n,int r,int str[] )
{
    int mini = 10000,i;
    if( r >= n )
    {
        return 0;   
    }
    for( i = 0;i <= n-1;i+= 1 )
    {
        if( str[i] == 0 )
        {
            str[i] = 1;
            mini = ( mini > callit( arr,n,r,str ) )?mini:callit( arr,n,r,str );
            str[i] = 0;
        }  
    }
}

void main()
{
    printf("Enter the size\n");
    int n, i, j;
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter the values\n");
    for( i = 0;i <= n-1;i+= 1 )
    {
        for( j = 0;j <= n-1;j+= 1 )
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int sum = callit( arr,n,0,n-1 );
    int str[n];
    for( i = 0;i <= n-1;i+= 1 )
    {
        str[i]=0;
    }
    printf( "%d",sum );
}