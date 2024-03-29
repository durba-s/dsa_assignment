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
void multiSourceBFS(struct graph* g,int onePos[],int visited[],int distance[],int head,int tail,int m,int n) { 
    struct node* temp;
    while (tail>head){
        int x=dequeue(onePos,&head,m*n);
        temp = g->list[x];
        while(temp!=NULL){
            int vnum=temp->num;
            if (visited[vnum]!=1) {
                visited[vnum] = 1;
                if(distance[x]+1<distance[vnum]){
                   distance[vnum]=distance[x]+1;
                }
                enqueue(onePos,&tail,vnum,m*n);
            }
            temp=temp->next;
        }

    }
    int current=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",distance[current]);
            current+=1;
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
    g->list = malloc(m*n*sizeof(struct node*));
    for (int i = 0; i < m*n; i++)
         g->list[i] = NULL;
    int k=0;
    for (int i=0; i<m; i++){   
        for (int j=0; j<n; j++){
            if (i==m-1){
                if (j!=n-1){
                    edge(g,k,k+1);
                }
            }
            else if (j==n-1){
                edge(g,k,k+n);
            }
            else{
                edge(g,k,k+1);
                edge(g,k,k+n);
            }
            k++;
        }
    }
    int distance[m*n], visited[m*n],onePos[m*n];
    int current=0,head=0,tail=0;
    for(int i=0;i<m*n;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (arr[i][j]==1) {
                distance[current]=0;
                visited[current]=1;
                enqueue(onePos,&tail,current,m*n);
            }
            current++;
        }
    }
   multiSourceBFS(g,onePos,visited,distance,head,tail,m,n);
   return 0;
}
