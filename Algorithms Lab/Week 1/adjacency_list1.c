#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node * next;
}NODE;
int main()
{
	int v,e1,e2;
	int i,j;
	NODE ** graph;
	scanf("%d",&v);
	int adj_matrix[v][v];
	graph = (NODE **) calloc(v+1,sizeof(NODE *));
	for(i=0;i<v;i++)
	{
		graph[i]=(NODE *) malloc(sizeof(NODE));
		graph[i]->val=i+1;
		graph[i]->next=NULL;
	}
	int ch;
	while(1)
	{
		scanf("%d",&e1);
		scanf("%d",&e2);
		adj_matrix[e1-1][e2-1]=1;
		NODE * head = graph[e1-1];
		while(head->next!=NULL)
		{
			head=head->next;
		}
		NODE *n = (NODE *) malloc(sizeof(NODE));
		n->val=e2;
		head->next=n;
		n->next=NULL;

		head = graph[e2-1];
		while(head->next!=NULL)
			head=head->next;

		NODE * n2 = (NODE *) malloc(sizeof(NODE));
		n2->val = e1;
		head->next=n2;
		n2->next=NULL;

		printf("Enter more?\n");
		scanf("%d",&ch);
		if(ch==0)
			break;
	}

	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			if(adj_matrix[i][j]!=1)
				adj_matrix[i][j]=0;

	for(i=0;i<v;i++)
	{
		NODE * head = graph[i];
		while(head!=NULL)
			{
				printf("%d->",head->val);
				head=head->next;
			}
		printf("NULL\n");
	}

	for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
				printf("%d ",adj_matrix[i][j]);
			printf("\n");
		}

}
