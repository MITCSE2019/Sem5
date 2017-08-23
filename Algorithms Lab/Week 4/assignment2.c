#include <stdio.h>
#include <stdlib.h>
int arr1[125][125];
int max=100000;
 
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void permu(int arr[],int n,int left,int right)
{
int i,j;
if(left==right){
    int sum=0;
    for(j=0;j<n;j++){
   sum = sum + arr1[j][arr[j]];
}
if(max>sum){
    max = sum;
}
 
}  
for(i=left;i<=right;i++)
{
  swap(&arr[i],&arr[left]);
  permu(arr,n,left+1,right);
  swap(&arr[left],&arr[i]);  
}
}
int main()
{ int arr[1000];
    int n,i=0,left=0,j;
    printf("enter the size \n");
    scanf("%d",&n);
    int right = n-1;
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
            scanf("%d",&arr1[i][j]);
         }
    }
    for(i=0;i<n;i++)
    {
     arr[i] = i;
    }
    permu(arr,n,left,right);
  printf("%d",max);
}
