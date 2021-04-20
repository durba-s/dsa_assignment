#include<stdio.h>
#include<stdlib.h>
int count=0;
long long int arr[26];
void noi(int* sub,int m,long long int n){
	long long int cost=0;
	int items=0;
	for(int i=0;i<m;i++){
		if(sub[i]==1){
			cost=cost+arr[i];
			items++;
		}
	}
	if(count<items&&cost<=n)
		count=items;
	return;
}
void substring(int m, int* sub, int i,long long int n) 
{ 
    if (i == m) { 
        noi(sub, m,n); 
        return; 
    }
    sub[i] = 0;
    substring(m, sub, i + 1,n);  
    sub[i] = 1; 
    substring(m, sub, i + 1,n); 
} 
int main(){
	long long int n;	
	int m;
	scanf("%lld",&n);
	scanf("%d",&m);
	int* sub=(int *)malloc(m * sizeof(int));
	for(int i=0;i<m;i++){
		scanf("%lld",&arr[i]);
	}	
	substring(m,sub, 0,n);
	printf("%d",count);
	free(sub);		
	return 0;
}
	/*long long int sum=0;
	for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
 
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int i;
    for(i=0;i<m;i++){
		sum=sum+arr[i];
		if(sum>n){
			break;
		}			
	}
	printf("%d",i);*/
