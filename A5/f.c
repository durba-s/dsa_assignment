#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node* next;
};
struct graph{
    int nov;
    struct node **adjList;
};
struct node* createNode(int vert) {
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->v = vert;
  new->next = NULL;
  return new;
}
void add(struct graph* g, int s, int d) {
  
  struct node* temp = createNode(d);
  temp->next = g->adjList[s];
  g->adjList[s] = temp;
  temp = createNode(s);
  temp->next = g->adjList[d];
  g->adjList[d] = temp;
}
void dfs(struct graph*g,int start,int * visited){
    struct node* temp1 = g->adjList[start];
    while (temp1) {
      if((temp1->next!=NULL)&&((temp1->v)>(temp1->next->v))){
          int a=temp1->v;
          temp1->v=temp1->next->v;
          temp1->next->v=a;
      }
      temp1 = temp1->next;
    }
    printf ("%d ", start+1);
    struct node* temp = g->adjList[start];
    visited[start]=1 ;
    while(temp){
        int i=temp->v;
       if (visited[i]==0)
            dfs(g,i, visited);
       temp = temp->next; 
    }

}
int main()
{
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	
    int m,n;
    scanf("%d",&n);
    scanf("%d",&m);
    struct graph* g =(struct graph*) malloc(sizeof(struct graph));
    g->nov=n;
    g->adjList =(struct node **) malloc(n * sizeof(struct node*));
    for (int i = 0; i < n; i++)
        g->adjList[i] = NULL;
    int v1,v2;
    for(int i=0;i<m;i++){
        scanf("%d",&v1);
        scanf("%d",&v2);
        add(g,v1-1,v2-1);
    }
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    dfs(g,0,visited);

  return 0;
   

}