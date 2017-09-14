#include <stdio.h>
#include <stdlib.h>

int callback(int arr[],int i)
{
	int m=i;
	int n=(i-1)/2;
	while(arr[m]>arr[n])
	{
		int a=arr[m];
		arr[m]=arr[n];
		arr[n]=a;
		m=(m-1)/2;
		n=(m-1)/2;
		if(m<0 || n<0)
			break;
	}
}
int main()
{
	int c = 1, ins = 0;
	int arr[1000] = { 0 };
	while(1)
	{
		int ele;
		printf("Enter the data\n");
		scanf("%d",&ele);
		if(ins==0 && arr[ins]==-1)
		{
			arr[ins]=ele;
		}
		else
		{
			if(arr[2*ins+1]==-1)
			{
				arr[2*ins+1]=ele;
				callback(arr,2*ins+1);
			}
			else
			{
				arr[2*ins+2]=ele;
				callback(arr,2*ins+2);
				ins+=1;
			}
		}
		printf("Continue( 0 - No 1 - Yes)\n");
		scanf("%d",&ele);
		if(ele==0)
			break;
		else
			c++;
	}
	printf("The elements are\n");
	for(int i=0;i<c;i++)
		printf("%d ",arr[i]);
}