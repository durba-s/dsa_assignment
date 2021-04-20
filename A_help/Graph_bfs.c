//adjacency lists for undirected graph
#include <stdio.h>
#include<stdlib.h>
#define N 10000
struct node{
    int v;
    struct node* next;
};
struct node** adjList;
int nov;
int* visited;
struct node* createNode(int n){
    struct node* new=malloc(sizeof(struct node));
    new->v=n;
    new->next=NULL;
    return new;
}
void bfs(int initv){
    int queue[N];
    int start=0;
    int end=0;
    visited[initv]=1;
    queue[end]=initv;
    end=end+1;
    while(end>start){
        int temp=queue[start];
        start=(start+1)%N;
        struct node* current=adjList[temp];
        while(current!=NULL){
            if(visited[current->v]==0){
                visited[current->v]=1;
                queue[end]=current->v;
                end=(end+1)%N;
            }
            current=current->next;
        }
    }
    for(int i=0;i<nov;i++){
        if(visited[i]==1)
            printf("%d ",i);
    }
}
int main()
{
    int n,e;
    scanf("%d",&n);
    scanf("%d",&e);
    nov=n;
    adjList= malloc(n*sizeof(struct node*));
    visited=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {  
        adjList[i]=NULL;
        visited[i]=0;
    }
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d",&v1);
        scanf("%d",&v2);
        struct node* inv=createNode(v1);
        inv->next=adjList[v2];
        adjList[v2]=inv;
        inv=createNode(v2);
        inv->next=adjList[v1];
        adjList[v1]=inv;
        
    }
    bfs(2);
    
    /*for(int i=0;i<n;i++){
        struct node* current=adjList[i];
        printf("%d: ",i);
        while(current){
            printf("->%d",current->v);
            current=current->next;
        }
        printf("\n");
    }*/
    return 0;
}
