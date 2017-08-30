#include <stdio.h>
#include <stdlib.h>

typedef struct rr{
    int pid;
    int AT;
    int BT;
}pr;
void sort ( pr a[],int n ){
    for ( int i = 0; i < n-1; i++ ){    
        for ( int j = 0; j <n-i-1; j++ ){      
            if ( a[j].AT > a[j+1].AT ){
                pr c;
                c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
        }
    }
}
void round(pr arr[],int n,int total,pr arr1[], int quan){
    int x=1;//index for array...to determine when a process should enter the queue
    int completion_time[100];
    for(int i=0;i<n;i++){
        completion_time[i]=0;
    }
    pr q[100];
    for(int i=0;i<100;i++){   //To avoid overprinting problem of queue
        q[i].pid=-1;
        q[i].AT=0;
        q[i].BT=0;
    }
    int f=0;
    int r=-1;
    q[++r]=arr[0];    
    total+=arr[0].AT;
    int i=arr[0].AT;
    while(i<=total){
        int j=i;
        int id=q[f].pid;
        while(x<n){
            if(i>=arr[x].AT){
                q[++r]=arr[x];
                x++;
            }else
                break;            
        }
        pr y;
        if(q[f].pid==-1)
            break;        
        if(q[f].BT>quan){
            q[f].BT=q[f].BT-quan;
            y=q[f];
            f++;            
            while(x<n){
                if((i+quan)>=arr[x].AT){
                    q[++r]=arr[x];
                    x++;
                }else
                    break;             
            }
            q[++r]=y;
            i=i+quan;
        }else{                        
            while(x<n){
                if((i+q[f].BT)>=arr[x].AT){
                    q[++r]=arr[x];
                    x++;
                }else
                    break;             
            }
            i=i+q[f].BT;
            completion_time[q[f].pid-1]=i;
            f++;
        }
        printf("p%d (%d-%d)\n",id,j,i );
    }
    printf("Completion time :\n");
    for(int i=0;i<n;i++){
        printf("\nfor process p%d completion time is %d",i+1,completion_time[i]);
    }
    printf("\n");
    float tat=0;
    float wait=0;
    for(int i=0;i<n;i++){
        printf("\nProcess %d turnaround time is %d ,waiting time is %d ",i+1,completion_time[i]-arr1[i].AT,completion_time[i]-arr1[i].AT-arr1[i].BT);
        tat+=completion_time[i]-arr1[i].AT;
        wait+=completion_time[i]-arr1[i].AT-arr1[i].BT;
    }
    printf("\naverage turnaround time is %f average waiting time is %f\n",(float)tat/n,(float)wait/n );
}
int main(){
    printf("Enter number of processes\n");
    int n,quan;
    scanf("%d",&n);
    printf("Enter quantum size\n");
    scanf( "%d", &quan);
    pr arr[10],arr1[10];
    int total=0;
    for(int i=0;i<n;i++){
        printf("%d process\n,enter arrival and burst time\n",i+1 );
        int x,y;
        scanf("%d %d",&arr[i].AT,&arr[i].BT);
        arr[i].pid=i+1;    
        total+=arr[i].BT;
        arr1[i].pid=i+1;
        arr1[i].AT=arr[i].AT;
        arr1[i].BT=arr[i].BT;
    }
    for(int i=0;i<n;i++){
        printf("Process %d , arrival time %d burst time %d\n",arr[i].pid,arr[i].AT,arr[i].BT );
    }
    sort(arr,n);
    round(arr,n,total,arr1,quan);
}

//Contributed by Dattatreya Nayak
