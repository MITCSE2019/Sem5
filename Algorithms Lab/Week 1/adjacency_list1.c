#Baap ka code!
#include <stdio.h>
#include <stdlib.h>
struct adj
{
    int data;
    struct adj* next;
};
int main()
{
    int V;
    int i;
    printf("Enter number of vertices ");
    scanf("%d",&V);
    struct adj* a[V];
    for(i=0;i<V;i++){
        a[i]=(struct adj*)malloc(sizeof(struct adj));
        a[i]->data=i;
        a[i]->next=NULL;
    }
    while(1){
            printf("Enter vertex pair \n");
            int x,y;
            scanf("%d %d",&x,&y);
        struct adj* node1;
        struct adj* temp=(struct adj*)malloc(sizeof(struct adj));
        node1=a[x];
        while(node1->next!=NULL){
            node1=node1->next;
        }
        temp->data=y;
        node1->next=temp;
        temp->next=NULL;

        struct adj* temp2=(struct adj*)malloc(sizeof(struct adj));
        node1=a[y];
        while(node1->next!=NULL){
            node1=node1->next;
        }
        temp2->data=x;
        node1->next=temp2;
        temp2->next=NULL;
        printf("Continue? ");
        int n;
        scanf("%d",&n);
        if(n!=1)
            break;
    }
    for( i=0;i<V;i++){
        struct adj* node;
        node=a[i];
        while(node!=NULL){
            printf("%d ",node->data);
            node=node->next;
        }
        printf("\n");
    }
    return 0;
}
