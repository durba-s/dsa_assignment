//adjacency lists for undirected graph
#include <stdio.h>
#include<stdlib.h>
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
void dfs(int v){
    printf("%d ",v);
    struct node* vertex=adjList[v];
    struct node* temp=vertex;
    visited[v]=1;
    while(temp!=NULL){
        int nextv=temp->v;
        if(visited[nextv]!=1){
            dfs(nextv);
        }
        temp=temp->next;
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
    //dfs(0);
    
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
