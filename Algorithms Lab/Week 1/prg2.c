#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char val;
	struct node * next;
}* Node;


typedef struct graph{
	int v;
	Node * array;
} Graph;


Graph addEdge(Graph graph,char src, char dst)
{	

	Node cur=graph.array[src-'A'];
	while(cur->next)
		cur=cur->next;
	cur->next=(Node) malloc(sizeof(struct node));
	cur=cur->next;
	cur->val=dst;
	cur->next=NULL;
	cur=graph.array[dst-'A'];
	while(cur->next)
		cur=cur->next;
	cur->next=(Node) malloc(sizeof(struct node));
	cur=cur->next;
	cur->val=src;
	cur->next=NULL;
	return graph;
}

Graph createGraph()
{
	Graph graph;
	int v,e;
	printf("%s", "Enter number of vertices: ");
	scanf("%d",&v);
	graph.v=v;
	graph.array= (Node *) calloc(v,sizeof(Node));
	printf("%s", "Enter number of edges: ");
	scanf("%d",&e);
	for(int i=0;i<graph.v;i++)
	{
		graph.array[i]=(Node) malloc(sizeof(struct node));
		graph.array[i]->val= 'A'+i;
		graph.array[i]->next=NULL;
	}
	for(int i=0;i<e;i++)
	{
		char src,dst;
		printf("%s","Enter src and dst: ");
		scanf(" %c",&src);
		scanf(" %c",&dst);
		graph= addEdge(graph,src,dst);		
	}
	return graph;

}

void displayGraph(Graph graph)
{
	printf("%s\n","\nAdjacency List");
	for(int i=0;i<graph.v;i++)
	{	
		Node cur=graph.array[i];
		while(cur->next)
			{printf("%c-->",cur->val);
			 cur=cur->next;}
		printf("%c\n",cur->val );
	}
}

int ** createMatrix(Graph graph)
{
	int ** matrix = (int **) calloc(graph.v,sizeof(int *));
	for(int i=0;i<graph.v;i++)
		matrix[i]=(int *) calloc(graph.v,sizeof(int));
	for(int i=0;i<graph.v;i++)
	{	
		Node cur=graph.array[i];
		while(cur->next)
			{cur=cur->next;
			 matrix[i][cur->val-'A']=1;}
	}
	return matrix;
}

void displayMatrix(int ** matrix,int v)
{
	printf("%s\n","Adjacency Matrix");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

void main()
{
	Graph graph=createGraph();
	displayGraph(graph);
	int ** matrix=createMatrix(graph);
	displayMatrix(matrix,graph.v);
}