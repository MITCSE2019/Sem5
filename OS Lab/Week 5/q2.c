#include <pthread.h>
#include <stdio.h>
#include <string.h>
int sum;
void* child_thread(void *param)
{
    int *a=(int*)param;
    int i, len=a[0];   
    sum=0;
    //printf("%d\n", len);
    for(i=1; i<=a[0]; i++)
    {
        //printf("%d\n", a[i]);
        sum+=a[i]; 
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    pthread_t thread;
    int i, n, a;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n+1];
    arr[0]=n;
    printf("Enter elements: \n");
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        arr[i]=a;
    }
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    int return_value;
    pthread_create(&thread, &attributes, child_thread, (void*)arr);
    pthread_join(thread, NULL);
    printf("Sum is %d\n", sum);
}