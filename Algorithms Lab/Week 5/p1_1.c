#include <stdio.h>

int visited[100];
int push[20];
int pop[20];
int push_i,pop_i;

void dfs(int a[][100],int i,int v)
{
	visited[i]=1;
	int j=0;
	for(j=0;j<v;j++)
	{
		if(j==i)
			continue;

		
		if(!visited[j] && a[i][j]!=0)
		{
			visited[j]=1;
			push[push_i]=j;
			push_i++;
			dfs(a,j,v);
			pop[pop_i]=j;
			pop_i++;
		}
		
	}
}

int main()
{
	int a[100][100];
	int v,i,j;
	push_i=0;
	pop_i=0;

	printf("Enter no of vertices : ");
	scanf("%d",&v);

	printf("Enter Adjacency Graph : ");
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for (int i = 0; i < v; i++)
	{
		visited[i]=0;
	}

	for (int i = 0; i < v; i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			push[push_i]=i;
			push_i++;
			dfs(a,i,v);
			pop[pop_i]=i;
			pop_i++;
		}
	}
	

	printf("Topological Sort : ");
	for (int i = pop_i - 1; i >= 0; i--)
	{
		
		printf("%d  ",pop[i] + 1);
	}
	printf("\n");



}