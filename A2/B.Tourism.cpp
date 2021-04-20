#include<stdio.h>
#include<stdlib.h>
void dfs(int** adj, int start, int* visited,int n)
{
	
	visited[start]=1 ;
	for (int i=0; i<n ; ++i) {
		if (adj[start][i] && (!visited[i]))
			dfs(adj, i, visited,n);
	}
}
int main(){
	int m,n;
	scanf("%d",&n);
	scanf("%d",&m);
	int **adj = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         adj[i] = (int *)malloc(n * sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    		adj[i][j]=0; 
		visited[i]=0;   
	}	
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d",&v1);
		scanf("%d",&v2);
		adj[v1-1][v2-1]=1;		
	}
	int max=0;
	for(int i=0;i<n;i++){
		int count=0;
		dfs(adj, i, visited,n);
		for(int j=0;j<n;j++){
			if(visited[j]==1){
				count++;
				visited[j]=0;
			}
		}
		if(max<count){
			max=count;
		}
	}
	printf("%d",max);
	free(adj);
	free(visited);
	return 0;
}
