#include <stdio.h>
#include <pthread.h>
int arr[100];
int i, k=2;
void* child_thread(void *params)
{
    int up= atoi(params);
    int a, b, c;
    arr[0]=arr[1]=1;
    a=arr[0];
    b=arr[1];
    while(up-2!=0)
    {
        c=a+b;
        arr[k]=c;
        a=arr[k-1];
        b=arr[k];
        up--;
        k++;
    }
    pthread_exit(0);
}
 
int main(int argc, char *argv[])
{
    pthread_t thread;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_create(&thread, &attributes, child_thread, argv[1]);
    pthread_join(thread, NULL);
    printf("The Fibonacci series is as follows:\n");
    for(i=0; i<k; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}   