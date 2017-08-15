#include <stdio.h>
#include <stdlib.h>

int *a;
int n;

int sum(int x)
{
	int i=0,s=0;
	while(n!=i)
	{	
		int f=1<<i;
		if((f&x)==f)
			s+=a[i];
		i++;
	}
	return s;
}

void print(int x)
{
	int i=0;
	while(n!=i)
	{
		int f=1<<i;
		if((f&x)==f)
			printf("%d ",a[i]);
		i++;
	}
	printf("%8s\t","");
}

void main()
{
	printf("Enter size: ");
	scanf("%d",&n);
	a=(int *) calloc(n,sizeof(int));
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int p=1<<n;
	for(int i=0;i<p;i++)
		for(int j=0;j<p;j++)
		{
			if(i==j)
				continue;
			if (!(i&j) && (i|j)==p-1)
				{
					int s1=sum(i);
					int s2=sum(j);
					if(s1==s2)
						{
						 print(i);
						 print(j);
						 printf("Sum: %d\n",s1);
						}
				} 
		}
}
