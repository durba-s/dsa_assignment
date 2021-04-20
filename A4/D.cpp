#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  float pro;
  struct node* next;
};
struct calc {
  int vert;
  float prob;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};
void merging(int low,int mid,int high,struct calc* a,struct calc*b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].prob <= a[l2].prob)
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low,int high,struct calc* a,struct calc*b) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid,a,b);
      sort(mid+1, high,a,b);
      merging(low, mid, high,a,b);
   } else { 
      return;
   }   
}

// Create a node
struct node* createNode(int v,float p) {
  struct node* newNode =(struct node*) malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->pro = p;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph =(struct Graph*) malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists =(struct node**) malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d,float p) {
  // Add edge from s to d
  struct node* newNode = createNode(d,p);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

  
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}
void sumProb(struct Graph* graph,struct calc *arr) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    arr[v].vert=v;
    arr[v].prob=0;
    while (temp) {
      arr[v].prob+=temp->pro;
      temp = temp->next;
    }
    arr[v].prob=1-arr[v].prob;
  }
}

int main() {
	int n,e,s;
	scanf("%d",&n);
	scanf("%d",&e);
	scanf("%d",&s);
  struct Graph* graph = createAGraph(n);
  for(int i=0;i<e;i++){
  	int s,d;
  	float p;
  	scanf("%d",&s);
  	scanf("%d",&d);
  	scanf("%f",&p);
  	
  	addEdge(graph, s, d,p);
  	
  }
  struct calc * arr=(struct calc *)malloc(n*sizeof(struct calc));
  struct calc * arr1=(struct calc *)malloc(n*sizeof(struct calc));
  sumProb(graph,arr);
  sort(0,n-1,arr,arr1);
  for(int i=0;i<n;i++){
  	printf("%d ",arr[i].vert);
  }
  
  

  //printGraph(graph);

  return 0;
}
/*
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000

struct Node
{
    int vertex;
    float weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjList;
};

typedef struct Node Node;
typedef struct Graph Graph;

float probabilities[N] = {1}, stopProb[N] = {0};
Graph* tree;

Node* createNode(int v, float w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;

    return node;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->numVertices = vertices;
    graph->adjList = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int s, int d, float w) {
    Node* node = createNode(d, w);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;
}

void travserse(Graph* g) {
    for (int i = 0; i < g->numVertices; ++i) {
        printf("%d [%.2f]", i, probabilities[i]);
        for (Node *u = g->adjList[i]; u != NULL; u = u->next) {
            printf(" -> %d[%.2f]", u->vertex, probabilities[u->vertex]);
        }
        printf("\n");
    }
}

void BFS(Graph* graph, int startVertex) { // Uses a circular queue
    int q[N], front = 0, rear = 0;

    int visited[N] = {0};

    // Enque startVertex
    q[rear++] = startVertex; 
    visited[startVertex] = 1;

    while (front < rear) {
        // Dequeu
        int v = q[front++];
        front %= N;

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;

                probabilities[u->vertex] = u->weight * probabilities[v];

                q[rear++] = u->vertex;
                rear %= N;
            }
        }
    }
}

void computeStopProb(Graph* g) {
    for (int i = 0; i < g->numVertices; ++i) {
        for (Node *u = g->adjList[i]; u != NULL; u = u->next) {
            stopProb[i] += u->weight;
        }
        stopProb[i] = (1 - stopProb[i]) * probabilities[i];
    }
}

int cmpfunc(const void* a, const void* b) {
    float diff = stopProb[*(int*)a] - stopProb[*(int*)b];
    if (diff == 0) return diff;
    if (diff < 0)  return  1;
    if (diff > 0)  return -1;
}

int main() {
    uint32_t n, e, s, u, v;
    float w;
    scanf("%d %d %d", &n, &e, &s);

    tree = createGraph(n);

    for (int i = 0; i < e; ++i) {
        scanf("%d %d %f", &u, &v, &w);
        probabilities[v] = w;
        addEdge(tree, u, v, w);
    }

    BFS(tree, s);

    computeStopProb(tree);

    int ordering[n];

    
    for (int i =0; i < n; ++i) {
        ordering[i] = i;
    }

    qsort(ordering, n, sizeof(int), cmpfunc);

    printf("\n");

    for (int i =0; i < n; ++i) {
        printf("%d ", ordering[i]);
    }

    return 0;
}
*/
