#include <stdio.h>
#include <stdlib.h>

int opcount=0;

typedef struct node{
  int data;
  struct node *left,*right;
}* Node;

Node create(){
    Node root = (Node) malloc(sizeof(struct node));
    //printf("Enter data: ");
    int x;
    scanf("%d",&x);
    if(x==-1){
      return NULL;
    }
    root->data=x;
    //printf("Left child of %d\n",x);
    root->left = create();
    //printf("Right child of %d\n",x);
    root->right = create();
} 

int count(Node root) 
{  
  opcount++;
  if (!root) 
    return 0;
  else    
    return(count(root->left) + 1 + count(root->right));  
}

void main()
{
  Node root=NULL;
  printf("Creating Tree (-1 for NULL)\nEnter data\n");
  root=create();
  int c=count(root);
  printf("Count is %d\n",c);
  printf("Opcount is %d\n",opcount);
}

// 0 1 2 -1 -1 3 4 -1 -1 5 -1 -1 6 -1 7 -1 8 9 10 -1 -1 11 -1 -1 12 -1 -1
// 0 1 2 3 -1 -1 4 5 6 -1 -1 7 -1 -1 -1 8 -1 9 10 -1 -1 11 -1 12 -1 -1 13 -1 14 -1 -1
// 0 1 -1 -1 2 3 -1 -1 -1