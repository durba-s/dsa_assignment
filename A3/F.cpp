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
void merging(int low,int mid,int high,int* a,int *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
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

void sort(int low,int high,int* a,int *b) {
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
	int* col1 = (int *)malloc((count-1)* sizeof(int));
	//printf("%d\n",count-1);
	sort(1,count-2,col,col1);
	int min=0.8*m;
	int nop=0,nov=0;
	for(int i=count-1;i>1;i--){
		if(nop>min){
			break;
		}
		else{
			nop=nop+col[i];
			nov++;
		}	
	}
	printf("%d",nov);
	
	free(adj);
	free(visited);
	free(col);
	free(col1);

         
	return 0;
}
