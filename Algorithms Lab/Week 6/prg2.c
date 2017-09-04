#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int l, int r)
{
    int p=a[l];
    int i=l,j=r+1;
    while(!(i>=j))
    	{
    		while(!(a[++i]>=p))
    			opcount++;
    		opcount++;
    		while(!(a[--j]<=p))
    			opcount++;
    		opcount++;
    		swap(&a[i],&a[j]);
    	}
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}
 
void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int s=partition(a,l,r);
        quickSort(a,l,s-1);
        quickSort(a,s+1,r);
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
			a[i]=i++;
		i=0;
		printf("\nUnsorted Array\t");
		while(i<n)
			printf("%d ",a[i++]);
		quickSort(a,0,n-1);
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