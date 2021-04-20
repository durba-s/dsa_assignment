#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int nov;
  struct node** adjLists;
};
struct node * createNode(int v){
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
	newnode->vertex=v;
	newnode->next=NULL;
	return newnode;
}
void addEdge(struct Graph* graph, int s, int d) {
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}
void BFS(Graph* graph, int startVertex, int endVertex) { 
    if (startVertex == endVertex) {
        printf("0");
        return;
    }
 
    int visited[5001] = {0}, dist[5001] = {INT_MAX}, pred[5001] = {-1};
    int q[5001], front = 0, rear = 0;
    q[rear++] = startVertex; 
    visited[startVertex] = 1;
    dist[startVertex] = 0;
 
    while (front < rear) {
        int v = q[front++];
        front %= 5001;
        for (node* u = graph->adjLists[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;
                dist[u->vertex] = dist[v] + 1;
                pred[u->vertex] = v;
                q[rear++] = u->vertex;
                rear %= 5001;
                if (u->vertex == endVertex) {
                    printf("%d", dist[u->vertex] * 100);
                    return;
                }
            }
        }
 
    }
	printf("0");
}
int main() {
	int n,m,s,t;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	scanf("%d",&t);
  	struct Graph* graph = (struct Graph *)malloc(sizeof(struct Graph));
  	graph->nov=n;
  	graph->adjLists = (struct node **)malloc(n*sizeof(struct node *));
  	for(int i=0;i<n;i++){
  		graph->adjLists[i]=NULL;
	  }
  	int v1,v2;
  	for(int k=0;k<m;k++){
  		scanf("%d",&v1);
  		scanf("%d",&v2);
  		addEdge(graph, v1, v2);
	  }
	BFS(graph,s,t);



  return 0;
}
