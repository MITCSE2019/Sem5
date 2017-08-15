#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *a, unsigned int n)
{
unsigned int i,j,min;
int temp;
int opcount=0; // introduce opcount
for(i= 0;i<n-1;i++)
{
min=i;
for(j=i + 1;j<n;j++)
{
++opcount;
// increment opcount for every comparison
if(a[j ]<a[min])
min=j;
}
//swap A[i] and A[min]
temp = a[i];
a[i] = a[min];
a[min]=temp;
}
printf("\nOperation Count %d\n",opcount);
}
int main() {
int *a;
int i,n = 5;
// generate worst case input of different input size
for (int j=0; j < 4; j++) // repeat experiment for 4 trials
{
a = (int *)malloc(sizeof(int)*n);
for (int k=0; k< n; k++)
a[k] = n-k; // descending order list
printf("Elements are ");
for(i=0;i<n;i++)printf("%d ",a[i]);
selectionSort(a,n);
printf("Elements after selection sort ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
free(a);
n = n + 5; // try with a new input size
}
return 0;
}