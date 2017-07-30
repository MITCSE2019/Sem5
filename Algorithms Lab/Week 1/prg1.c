#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
	int val;
	struct node * left;
	struct node * right;
} * Node;

Node add (Node root,int a)
{
	
	Node cur=root;
	Node prev=cur;
	while(cur)
	{
		prev=cur;
		if(a>cur->val)
			cur=cur->right;
		else
			cur=cur->left;
	}
	Node temp = malloc(sizeof(struct node));
	temp->val =a;
	temp->left =NULL;
	temp->right =NULL;
	if(!root)
		return temp;
	if(a>prev->val)
		prev->right=temp;
	else
		prev->left=temp;
	return root;
}

void inorder(Node root)
{
	if(!root)
		return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

void preorder(Node root)
{
	if(!root)
		return;
	printf("%d ",root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->val);
}


Node insert(Node root)
{
	int n,a;
	printf("%s","Enter number of nodes: " );
	scanf("%d",&n);
	printf("%s", "Nodes: ");
	for(int i=0;i<n;i++)
		{scanf("%d",&a);
		 root=add(root,a);
		}
	return root;
}

void search(Node root)
{
	int a;
	printf("%s", "Value: ");
	scanf("%d",&a);
	Node cur=root;
	Node prev=cur;
	while(cur)
	{	prev=cur;
		if(a==cur->val)
			{printf("%s\n", "Key Found");
			 return;}
		else if(a>cur->val)
			cur=cur->right;
		else
			cur=cur->left;
	}
	printf("%s\n", "Not Found, but inserted");
	Node temp = malloc(sizeof(struct node));
	temp->val =a;
	temp->left =NULL;
	temp->right =NULL;
	if(a>prev->val)
		prev->right=temp;
	else
		prev->left=temp;
	return;
}


void main()
{
	Node root=NULL;
	int choice;
	
	while(1)
	{printf("%s","\n\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\nEnter choice (1-5) : " );
	 scanf("%d",&choice);
	 switch(choice)
	 {	
	 	 case 1:root=insert(root);
	 		    break;
	     case 2:search(root);
	     		break;
	     case 3:inorder(root);
	     	   break;
	     case 4:preorder(root);
	     	   break;
	     case 5:postorder(root);
	     	   break;
	     default: exit(0);
	 }
	}
}