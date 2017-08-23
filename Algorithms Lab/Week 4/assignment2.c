#include <stdlib.h>
#include <stdio.h>

int c=0;
int arr[100][100];
int min=10000;
char answer[100];
int size=0;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
     int sum=0;
     for(int i=0;i<size;i+=1)
     {
       int n1=a[i]-48;
       sum+=arr[i][n1];
     }
     if(sum<min)
     {
       min=sum;
       strcpy(answer,a);
     }
}
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}
int main()
{
    printf("Enter the size\n");
    scanf("%d",&size);
    for(int i=0;i<=size-1;i+=1)
    {
      for(int j=0;j<=size-1;j+=1)
      {
        scanf("%d",&arr[i][j]);
      }
    }
    char str[100];
    for(int i=0;i<size;i+=1)
    {
      str[i]=(i+48);
    }
    int n = strlen(str);
    permute(str, 0, n-1);
      printf("%d is the minimum cost\n",min);//minimum cost
    for(int i=0;i<size;i+=1)
    {
      printf("%d gets job  %c\n",i+1,answer[i] + 1);
    }
    return 0;
}
