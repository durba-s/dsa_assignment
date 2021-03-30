#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647
struct node {
  int num;
  struct node* next;
};
struct graph {
  int ver;
  struct node** list;
};
void enqueue(int arr[],int *tail,int x,int size){
    arr[*tail]=x;
    *tail=*tail+1;
    if(*tail==size) *tail=0;
}
int dequeue(int arr[],int *head,int size){
    int x=arr[*head];
    *head=*head+1;
    if(*head==size) *head=0;
    return x;
}
void edge(struct graph* g, int v1, int v2) {
  struct node* e1 = malloc(sizeof(struct node));
  e1->num= v1;
  e1->next = g->list[v2];
  g->list[v2] = e1;
  struct node* e2 = malloc(sizeof(struct node));
  e2->num= v2;
  e2->next = g->list[v1];
  g->list[v1] = e2;
}
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
void multiSourceBFS(struct graph* g,int q[],int visited[],int distance[],int head,int tail,int m,int n) { 
    struct node* temp;
    while (head < tail) {
        int v=dequeue(q,&head,m*n);
        temp = g->list[v];
        while(temp!=NULL){
             if (visited[temp->num]!=1) {
                visited[temp->num] = 1;
                distance[temp->num] = min(distance[temp->num], distance[v] + 1);
                enqueue(q,&tail,temp->num,m*n);
            }
            temp=temp->next;
        }

    }
    int current=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",distance[current++]);
        }
        printf("\n");
    }
}

int main(){
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    struct graph* g = malloc(sizeof(struct graph));
    g->ver = m*n;
 
    g->list = malloc(m*n* sizeof(struct node*));
    for (int i = 0; i < m*n; i++)
         g->list[i] = NULL;
    int k=0;
    for (int i=0; i<m; i++){   
        for (int j=0; j<n; j++){
            if (i==n-1){
                if (j!=m-1){
                    edge(g,k,k+1);
                }
            }
            else if (j==m-1){
                edge(g,k,k+m);
            }
            else{
                edge(g,k,k+1);
                edge(g,k,k+m);
            }
            k++;
        }
    }
    int distance[m*n], visited[m*n], q[m*n];
    for(int i=0;i<m*n;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    int current=0;
    int head=0,tail=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]==1) {
                distance[current] = 0;
                visited[current] = 1;
                enqueue(q,&tail,current,m*n);
            }
 
            current++;
        }
    }
   multiSourceBFS(g,q,visited,distance,head,tail,m,n);
   return 0;
}
