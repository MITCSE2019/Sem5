#include <stdio.h>
int src_rem(int arr[][100],int v)
{
	int no[v];
	int k=0;
	for(int i=0;i<v;i+=1)
		no[i]=0;
	
	for(int i=0;i<v;i+=1)
	{
		int count=0;
		for(int j=0;j<v;j+=1)
		{
			if(arr[j][i]==1)
				count+=1;
		}
		no[i]=count;
	}
	int c=1;
	while(c<=v)
	{
		for(int i=0;i<v;i+=1)
		{
			if(no[i]==-1)
				continue;
			if(no[i]==0)
			{
				printf("%d ",i+1);
				no[i]=-1;
				for(int m=0;m<v;m+=1)
				{
					if(arr[i][m]==1)
					{
						arr[i][m]=0;
						no[m]-=1;
					}
				}
			}
		}
		c+=1;
	}
	
}
int main()
{
	int a[100][100];
	int v,i,j;
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
	printf("The result is : ");
	src_rem(a,v);
}
