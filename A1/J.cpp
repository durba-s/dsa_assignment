#include<stdio.h>
#include<stdlib.h>
int color(int m,int **arr,int *col){
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(arr[i][j]==1){
					if(col[i]==col[j]&&col[j]==0){
						col[j]=1;
					}
					else if(col[i]==col[j]&&col[j]==1){
						return 0;
					}
				}
			}
		}
	return 1;
}
int main(){
	int m,n,v1,v2;
	scanf("%d",&m);
	scanf("%d",&n);
	int **arr = (int **)malloc(m * sizeof(int *)); 
    for (int i=0; i<m; i++) 
         arr[i] = (int *)malloc(m * sizeof(int));
	int *col;
	col = (int *)malloc(m * sizeof(int));
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			arr[i][j]=0;
		}
		col[i]=0;		
	}
	  
	while(n--){
		scanf("%d",&v1);
		scanf("%d",&v2);
		arr[v1][v2] =1;
		arr[v2][v1]=1;		
	}
	if(color(m,arr,col)){
		for(int i=0;i<m;i++){
			if(*(col+i)==0) printf("R");
			else printf("B");			
		}
	}
	else{
		printf("NEED MORE COLOURS");
	}
	free(arr);
	free(col);     
         
	return 0;
}
