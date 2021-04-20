#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  char vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};
struct node* createNode(char v) {
  struct node* newNode = ( struct node*)malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph =(struct Graph*) malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists =(struct node**) malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}
void addEdge(struct Graph* graph, char s, char d) {
  struct node* newNode = createNode(d);
  //printf("%c %c",s,d);
  newNode->next = graph->adjLists[s-'A'];
  graph->adjLists[s-'A'] = newNode;
}
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    if(temp){
    	printf("\n Vertex %c\n: ", v+'A');
    	while (temp) {
      	printf("%c -> ", temp->vertex);
      	temp = temp->next;
    }
    
	}
  }
}
int main(){
	int n;
	struct Graph* graph = createAGraph(26);
	scanf("%d",&n);
	char c,c1,c2,c3;
	scanf("%c",&c);
	for(int i=0;i<n;i++){
		scanf("%c",&c);
		scanf("%c",&c1);
		scanf("%c",&c2);
		scanf("%c",&c3);
		addEdge(graph,c, c2);
	}
	printGraph(graph);
	return 0;
}
