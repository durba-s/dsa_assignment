#include<stdio.h>
void print(char* arr, int k) 
{ 
    for (int i = 0; i < k; i++) { 
       printf("%c",arr[i]); 
    } 
    printf("\n"); 
} 
  
void enumer(int k, char* arr,char *given,int i,int n) 
{ 
    if (i == k) { 
        print(arr, k); 
        return; 
    }
	for(int j=0;j<n;j++){
		arr[i]=given[j];
		enumer(k,arr,given,i+1,n);
	}
   
} 
int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	char c;
	scanf("%c",&c);
	char given[n];
	for(int i=0;i<n;i++){
		scanf("%c",&given[i]);
	}
	char arr[k];
	enumer(k,arr,given,0,n);
	return 0;
}
