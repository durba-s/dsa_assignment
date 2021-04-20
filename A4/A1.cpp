#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#define TRUE (int)1
#define FALSE (int)0
 
#define N 26
 
int ans[26] = {0}, ans_rear = 0;
int parent[26] = {0};
 
struct Node {
    int vertex;
    struct Node* next;
};
 
struct Graph {
    int numVertices;
    struct Node** adjList;
};
 
typedef struct Node Node;
typedef struct Graph Graph;
 
Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
 
    return node;
}
 
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
 
    graph->numVertices = vertices;
    graph->adjList = (Node **)malloc(vertices * sizeof(Node*));
 
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }
 
    return graph;
}
 
void addEdge(Graph* graph, int s, int d) {
    Node* node = createNode(d);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;
}
 
void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
 
int DFS(Graph* graph, int start, int visited[N]) {
    visited[start] = 1;
 
    for (Node* u = graph->adjList[start]; u != NULL; u = u->next) {
        if (visited[u->vertex] == 0) {
            parent[u->vertex] = start;
            if (DFS(graph, u->vertex, visited)) {
                return TRUE;
            }
        } else if (visited[u->vertex] == 1) {
            return TRUE;
        }
    }
    visited[start] = 2;
    ans[ans_rear++] = start;
    return FALSE;
}
 
void topologicalSort(Graph* graph, int charset[N]) {
    int visited[N] = {0};
 
    for (int i = 0; i < N; ++i) {
        if (charset[i] && !visited[i]) {
            if (DFS(graph, i, visited)) {
                printf("ALIENS BE CRAZY");
                return;
            }
        }
    }
 
    for (int i = ans_rear - 1; i >= 0; --i) {
        printf("%c", (char)(ans[i] + 'A'));
    }
}
 
int main() {
    uint32_t n = N, m;
    char u, v;
    scanf("%d%*c", &m);
 
    Graph* language = createGraph(n);
 
    int charset[N] = {0};
 
    for (int i = 0; i < m; ++i) {
        scanf("%c %c%*c", &u, &v);
        addEdge(language, (int)u - 'A', (int)v - 'A');
        charset[(int)u - 'A'] = 1;
        charset[(int)v - 'A'] = 1;
    }
 
    // printGraph(language);
    // Check for cycles...
 
    topologicalSort(language, charset);
 
    return 0;
}
//min no of swaps to sort an array
/*struct body{
	int first;
	int second;
};
void merging(int low,int mid,int high,struct body* a,struct body *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].first <= a[l2].first)
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

void sort(int low,int high,struct body* a,struct body *b) {
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
int minSwaps(int arr[], int n)
{
    
    struct body *arrPos=(struct body *)malloc((n)*sizeof(struct body));
    struct body *a1=(struct body *)malloc((n)*sizeof(struct body));
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array 
    // element values to
    // get right position of 
    // every element as second
    // element of pair.
    sort(0,n-1,arrPos,a1);
 
    // To keep track of visited elements. 
    // Initialize
    // all elements as not visited or false.
    int vis[n]={0};
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i]==1 || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (vis[j]==0)
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle. 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
}*/
/* This function merges two sorted arrays and returns inversion 
   count in the arrays.*/
