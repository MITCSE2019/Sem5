#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m,n;

int requestCheck(int request[n][m],int alloc[n][m],int work[m],int i)
{	
	int allow=1,count=0;
	for(int j=0;j<m;j++)
		if(!request[i][j])
			count++;
	if(count==m)
		return allow=1;
	printf("HERE\n");
	for(int j=0;j<m;j++)
		if(request[i][j]>work[j])
			allow=0;
	return allow;
}

void add(int work[m],int alloc[n][m],int i)
{
	for(int j=0;j<m;j++)
		work[j]+=alloc[i][j];
}

int checkFinish(int finish[n])
{
	int flag=1;
	for(int i=0;i<n;i++)
		if(!finish[i])
		{
			flag=0;
			break;
		}
	return flag;
}

void display(int work[m])
{
	for(int i=0;i<m;i++)
		printf("%d ",work[i]);
	printf("\n");
}

void detect(int avail[m],int alloc[n][m],int request[n][m],int work[m],int finish[n],int cycle[n])
{
	int safe=0;
	int i=0,j=0;
	int change=0;

	while(!safe)
		{
			if(!finish[i] && requestCheck(request,alloc,work,i))
			{
				add(work,alloc,i);
				finish[i]=1;
				change=0;
				cycle[j++]=i;
			}
			else if(checkFinish(finish))
			{
				safe=1;
				break;
			}
			else
				change++;
			if(change==n-1)
				break;
			display(work);
			i=(i+1)%n;
		}
	
	if(safe)
		printf("System in safe state\n");
	else
		printf("System in deadlock\n");
	for(int i=0;i<n;i++)
		printf("%d ",cycle[i]);
}

void main()
{	
	printf("Enter no of process and resouce\n");
	scanf("%d %d",&n,&m);
	int avail[m];
	int alloc[n][m];
	int request[n][m];
	int work[m];
	int finish[n];
	printf("Enter Alloc\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&alloc[i][j]);
	printf("Enter Request\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&request[i][j]);
	printf("Enter Available\n");
	for(int i=0;i<m;i++)
		scanf("%d",&avail[i]);
	memset(finish,0,sizeof(finish));
	memcpy(work,avail,sizeof(avail));
	int cycle[n];
	
	detect(avail,alloc,request,work,finish,cycle);

}

// 5 3
// 0 1 0
// 2 0 0
// 3 0 3
// 2 1 1
// 0 0 2
// 0 0 0
// 2 0 2
// 0 0 0
// 1 0 0
// 0 0 2
// 0 0 0
