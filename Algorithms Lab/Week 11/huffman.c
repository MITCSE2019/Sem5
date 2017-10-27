#include <stdio.h>
#include <stdlib.h>
 
struct node{
    char data;
    float val;
    struct node * left;
    struct node *right;
};
 
int find_min(struct node *a[],int n){
    int pos;
    float min=100.0;
    for(int i=(n+1)/2-1;i<n;i++){
        if(a[i]->val<min){
            pos=i;
            min = a[i]->val;
        }
    }
    printf(" min index%d\n", pos);
    return pos;
}
 
void get_codes(struct node *root,char *p,int *i){
    if(root){        
        p[(*i)++]='0';
        get_codes(root->left,p,i) ;        
        (*i)--;
        if(root->data!= ' '){
            printf(" %c ",root->data );
            for(int x=0;x<*i;x++){
                printf("%c",p[x] );
            }
            printf("\n");
           
            return;
        }
        p[(*i)++]='1';
        get_codes(root->right,p,i);
        (*i)--;
    }
}
 
void levelorder(struct node *root){
    struct node *Q[30];
    int f=0;
    int r=0;
    Q[f]=root;
    Q[r]=root;    
    Q[++r]=NULL;
    struct node *temp;
    while(f<=r){
        temp = Q[f++];
        if(temp==NULL){
            if(f<r){
                Q[++r]=NULL;
            }
            printf("\n\n");
        }
        else{
           
                printf("%c->%f ",temp->data,temp->val);
            if(temp->left){
                Q[++r]=temp->left;
            }
            if(temp->right){
                Q[++r]=temp->right;
            }
        }
    }
}
 
void heapify(struct node *a[],int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int m=i;
    if(l<n && a[l]->val>a[m]->val)
        m=l;
    if(r<n && a[r]->val>a[m]->val)
        m=r;
    if(m!=i){
        struct node *t=a[i];
        a[i]=a[m];
        a[m]=t;
        heapify(a,n,m);
    }
}
 
void makeheap(struct node *a[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=0;i<n;i++){
        printf("%f,%c  ",a[i]->val,a[i]->data );       
    }
    printf("\n");
}
 
struct node * generate_tree(struct node *a[],int n){
    makeheap(a,n);
   
    while(n>0){
        struct node *temp = (struct node *)malloc(sizeof(struct node));      
       /* temp->left = a[n-1];
        temp->right = a[n-2];
        a[n-1]=NULL;
        a[n-2]=NULL;
        n--;*/
        int pos = find_min(a,n);
        struct node *abc = a[pos];
        a[pos]=a[n-1];
        a[n-1] = abc;
        temp->left = a[n-1];
        a[n-1]=NULL;
        abc=NULL;
        n--;
        if(n==0){
            break;
        }
        makeheap(a,n);
 
        //n--;
        pos = find_min(a,n);
        abc = a[pos];
        a[pos]=a[n-1];
        a[n-1] = abc;
        temp->right = a[n-1];
        a[n-1]=NULL;
        n--;
        abc = NULL;
 
        n++;
        temp->val = temp->left->val + temp->right->val;
        temp->data = ' ';
        a[n-1] = temp;
        //levelorder(temp);
        char *p = (char *)malloc(sizeof(char)*10);
        int i=0;
        get_codes(temp,p,&i);    
        free(p);
 
        printf("\n");
        makeheap(a,n);
    }
    return a[0];
}
 
int main(){
    printf("enter no of elements\n");
    int n;
    scanf("%d",&n);
    struct node *a[10];
    for(int i=0;i<n;i++){
        a[i]=(struct node *)malloc(sizeof(struct node));
        a[i]->left=NULL;
        a[i]->right=NULL;
    }
    char ch;
    float x;
    for(int i=0;i<n;i++){
        printf("enter character and value\n");
        scanf(" %c",&ch);
        scanf("%f",&x);
        a[i]->data=ch;
        a[i]->val=x;
    }
 
    for(int i=0;i<n;i++){
        printf("%c %f\n",a[i]->data,a[i]->val );
    }
    struct node *y=NULL;
    y = generate_tree(a,n);
    printf("\n\n");
    levelorder(y);
}

//Contributed by Dattatreya Nayak
