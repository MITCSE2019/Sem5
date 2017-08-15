#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int sum(int arr[],int n)
{
	int sum =0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return sum;
}

void display(int arr[] ,int c)
{
	int j;
	for(j=0;j<c;j++)
		if(arr[j])
			printf("%d,",arr[j]);	
	printf("\n");
}

int main(int argc, char const *argv[])
{
    //int set[]={1,2,3,4,5,9};
	int set[] = {1,2,5,4};
	int size = sizeof(set)/sizeof(int);
	int power_set_size = pow(2,size);
	int i,j;
	int s = sum(set,size);
	if(s%2!=0)
		printf("Partition not possible\n");
	else
	{
		int part_sum = s/2;
		int pow_set[power_set_size][size]={0};

		for(i=0;i<power_set_size;i++)
		{
			for(j=0;j<size;j++)
			{
				if(i & (1<<j))
					pow_set[i][j] = set[j];
			}
			int d = power_set_size-i-1;
			if(sum(pow_set[d],size)==part_sum)
			{
				printf("%d->",i);
				display(pow_set[power_set_size-i-1],size);
				display(pow_set[i],size);
			}
		}	
		printf("power set:\n");
	for(i=1;i<power_set_size;i++)
		{
			printf("%d->",i);
			for(j=0;j<size;j++)
				if(pow_set[i][j]!=0)
					printf("%d,",pow_set[i][j]);
			printf("\n");
		}

	}
	return 0;
}