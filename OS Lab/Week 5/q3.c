#include <pthread.h>
#include <stdio.h>
#include <string.h>
int count;
void* child_thread(void *param)
{
    int i, j;
    int* arr=(int*)(param);
    //printf("Upper limit is %d\n", upper);
    for(i=arr[0]; i<=arr[1]; i++)
    {
        count=0;
        for(j=1; j<=i; j++)
        {
            if(i%j==0)
                count++;
        }
        if(count==2)
            printf("%d ", i);
    }
    printf("\n");
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int arr[2], i, a;
    printf("Enter Lower and Upper limits:\n");
    for(i=0; i<2; i++)
    {
        scanf("%d", &a);
        arr[i]=a;
    }  
    pthread_t thread;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_create(&thread, &attributes, child_thread, (void *)arr);   
    pthread_join(thread, NULL);
}