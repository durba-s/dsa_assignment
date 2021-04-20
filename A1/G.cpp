#include<stdio.h>
#include<stdlib.h>
int dfs(int **adj, int start, int *visited,int v,int n,int *col)
{
	visited[start]=n ;
	for (int i=0; i<v; ++i) {
		if (adj[start][i]==1&&visited[i]==0){	
			col[n]++;
			dfs(adj, i, visited,v,n,col);
			}
	}
	return 0;
}
int main(){
	int m,n,v1,v2;
	scanf("%d",&m);
	scanf("%d",&n);
	int **adj = (int **)malloc(m * sizeof(int *)); 
    for (int i=0; i<m; i++) 
         adj[i] = (int *)malloc(m * sizeof(int));
	int *visited;
	int *col;
	visited = (int *)malloc(m * sizeof(int));
	col = (int *)malloc(m * sizeof(int));
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			adj[i][j]=0;
		}
		visited[i]=0;
		col[i]=1;		
	}	  
	while(n--){
		scanf("%d",&v1);
		scanf("%d",&v2);
		adj[v1][v2] =1;
		adj[v2][v1]=1;		
	}
	int count=1;
	for(int i=0;i<m;i++){
		if(visited[i]==0){
			int l=dfs(adj,i,visited,m,count,col);
			count++;
			}
	}
	printf("%d\n",count-1);
	for(int i=1;i<count;i++){
		printf("%d ",col[i]);	
	}
	
	free(adj);
	free(visited);
	free(col);

         
	return 0;
}
