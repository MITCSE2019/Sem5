#include <stdio.h>
#include <stdlib.h>

typedef struct alloc
{
	int a,b,c;
}alloc;
typedef struct max
{
	int a,b,c;
}max;
typedef struct avail
{
	int a,b,c;
}avail;
typedef struct need
{
	int a,b,c;
}needy;
void main( )
{
	int n,i,j;
	printf( "Enter number of processes\n" );
	scanf("%d",&n);
	alloc al[n];
	max m[n];
	avail av;
	needy need[n];
	printf("\n Enter allocation and max for each process\n" );
	for( i = 0; i < n;i++ )
	{
		scanf(" %d %d %d ",&al[i].a,&al[i].b,&al[i].c );
		scanf(" %d %d %d ",&m[i].a,&m[i].b,&m[i].c );	
		need[i].a = m[i].a - al[i].a;				
		need[i].b = m[i].b - al[i].b;
		need[i].c = m[i].c - al[i].c;

	}
	printf( "\nEnter availability array\n" );
	scanf("%d%d%d",&av.a,&av.b,&av.c);
	printf("\n\n");
	for( i = 0; i < n;i++ )
	{
		printf( "%d\t%d\t%d\n",need[i].a,need[i].b,need[i].c );
	}

	int count=0;
	int flag=0;
	int visited[n];
	memset( visited, 0, sizeof(visited) );
	for( i = 0; i < n; i = (i+1) % n )
	{
		j++;
		if( need[i].a <= av.a && need[i].b <= av.b && need[i].c <= av.c && visited[i] == 0 )
		{
			visited[i]=1;
			printf( "Process %d\t",i );
			count++;
			av.a+= al[i].a;
			av.b+= al[i].b;
			av.c+= al[i].c;
		}
		if( count == n )
		{
			flag = 1;
			break;
		}
		if( j == 3 * n )
		{
			flag = 0;
			break;
		}
	}
	if( flag == 0)
		printf( "\nDeadlock\n" );
}