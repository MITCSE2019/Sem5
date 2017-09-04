#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int opcount=0;

void display(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void merge(int B[],int p, int C[],int q, int A[])
{
	int i=0,j=0,k=0;
	while(i<p && j<q)
	{	
		opcount++;
		if(B[i]<=C[j])
			A[k]=B[i++];
		else
			A[k]=C[j++];
		k++;
	}
	if(i==p)
		memcpy(A+k,C+j,sizeof(int)*(q-j));
	else
		memcpy(A+k,B+i,sizeof(int)*(p-i));
}

void mergeSort(int A[],int n)
{
		if(n>1)
		{	
			int c=ceil(n/2.0),f=floor(n/2.0);
			int B[f],C[c];
			memcpy(B,A,sizeof(int)*f);
			memcpy(C,A+f,sizeof(int)*(n-f));
			mergeSort(B,f);
			mergeSort(C,c);
			merge(B,f,C,c,A);
		}
}

void main()
{
	int n=5,i=0,j=0,k=0;

	for(int k=0;k<5;k++)
	{	
		i=0;
		opcount=0;
		int * a = (int *) malloc(n*sizeof(int));
		while(i<n)
			a[i]=n-i++;
		i=0;
		printf("\nUnsorted Array\t");
		while(i<n)
			printf("%d ",a[i++]);
		mergeSort(a,n);
		printf("\nOpcount:\t%d",opcount);
		printf("\nSorted Array\t");
		i=0;
		while(i<n)
			printf("%d ",a[i++]);
		printf("\n\n");
		free(a);
		n+=5;
	}
}