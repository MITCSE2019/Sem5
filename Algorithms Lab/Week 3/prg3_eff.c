#include <stdio.h>
#include <stdlib.h>

int *a;
int n;

float sum(int x)
{
	int i=0;
	float s=0.0;
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

int comp(int x)
{
	int y=x,i=0,f;
	while(n!=i)
	{
		f=1<<i;
		y^=f;
		i++;
	}
	return y;
}

void main()
{
	printf("Enter size: ");
	scanf("%d",&n);
	a=(int *) calloc(n,sizeof(int));
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	float s=0.0;
	for(int i=0;i<n;i++)
		s+=a[i];
	if(((s/2)-(int)(s/2))!=0.0)
		printf("Parition set not possible as sum is %f\n",s/2);
	int p=1<<n;
	for(int i=0;i<p/2;i++)
		if(sum(i)==s/2)
		{
			print(i);
			print(comp(i));
			printf("Sum %d\n",(int)s/2);
		}
		
}
