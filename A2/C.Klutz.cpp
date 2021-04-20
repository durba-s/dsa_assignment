#include<stdio.h>
#include<stdlib.h>
int count=0;
int win(int v1,int v2,int** adj, int* visited,int n)
{
	if(count==1) return 1;
	visited[v1]=1;
	if(adj[v1][v2]==1){
		count=1;
		return 1;
	}	
	for (int i=0; i<n ; ++i) {		
		if (adj[v1][i]==1 && (!visited[i]))
			win(i,v2,adj, visited,n);		
	}
	return 0;		
}
int main(){
	int n;
	scanf("%d",&n);
	int e=(n*n-n)/2;
	int **adj = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         adj[i] = (int *)malloc(n * sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    	if(i==j) adj[i][j]=1;
    	else adj[i][j]=0; 
		visited[i]=0;   
	}
	int a,b;	
	for(int i=1;i<e;i++){
		
		scanf("%d",&a);
		scanf("%d",&b);
		adj[a-1][b-1]=2;
		adj[b-1][a-1]=1;
	}
	int v1,v2;
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j]==0&&i!=j&&adj[j][i]==0){
				v1=i;
				v2=j;
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	
	if(win(v1,v2,adj,visited,n))
		printf("%d %d",v1+1,v2+1);
	count=0;
	if(win(v2,v1,adj,visited,n))
		printf("%d %d",v2+1,v1+1);
	else
		printf("-1");
	return 0;
}
