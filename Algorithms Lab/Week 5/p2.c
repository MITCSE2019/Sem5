#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create(){
    struct  node *root = (struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no data)");
    int x;
    scanf("%d",&x);
    if(x==-1){
      return NULL;
    }
    root->data=x;
    printf("\nEnter left child of %d",x);
    root->left = create();
     printf("\nEnter right child of %d",x);
    root->right = create();
} 

int max(int a,int b){
  return a>b?a:b;
}
int height(struct node *root){
  if(root==NULL){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}

int diameter(struct node *root){
  if(root==NULL){
    return 0;
  }
  int lheight=height(root->left);
  int rheight=height(root->right);
  int ldiam=diameter(root->left);
  int rdiam=diameter(root->right);
  return max(1+lheight+rheight,max(ldiam,rdiam));
}

int main()
{
  struct  node *root = (struct node *)malloc(sizeof(struct node));
  root=NULL;
  root=create();
  printf("The diameter is %d\n",diameter(root) );
  return 0;
}