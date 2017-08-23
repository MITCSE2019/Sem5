#include <stdlib.h>
#include <stdio.h>

void recurSum(int *arr,int n,int *ind,int i,int *sum,int *finalInd){
    if(i==n){
        int t=0;
        for(int a=0;a<n;a++){
            t+=arr[a*n + ind[a]];
        }
        if(*sum<t){
            *sum=t;
            //printf("Index\n");
            for(int b=0;b<n;b++){
                finalInd[b]=ind[b];
                //printf("%d ",ind[b]);
            }
            //printf("\nGreatest sum: %d\n",t);
        }
        return;
    }
    else{
        for(int a=0;a<n;a++){
            int t=0;
            if(i==0){
                for(int c=0;c<n;c++){
                    ind[c]=-1;
                }
            }
            for(int b=0;b<=i;b++){
                if(ind[b]==a){
                    t=1;
                    break;
                }
            }
            if(t){
                continue;
            }
            ind[i]=a;
            // printf("At %d,%d\n",i,ind[i]);
            recurSum(arr,n,ind,i+1,sum,finalInd);
        }
    }
}

int main(){
    int i,j,n,sum=0,costMat[100],ind[20],finalInd[20];
    printf("Enter no. of workers: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        ind[i]=-1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter pay for job %d by worker %d:\n",j,i);
            scanf("%d",&costMat[i*n+j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", costMat[i*n+j]);
        }
        printf("\n");
    }
    recurSum(costMat,n,ind,0,&sum,finalInd);
    printf("Selected Indices:\n");
    for(i=0;i<n;i++){
        printf("%d ",finalInd[i]);
    }
    printf("\nGreatest Sum is: %d\n",sum);
}