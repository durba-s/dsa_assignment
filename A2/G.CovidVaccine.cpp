#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int b;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&b);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			 if (arr[i] < arr[j]) 
                {
                    int a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		int flag=1;
		if(arr[i]!=-1){		
			for(int j=i+1;j<n;j++){
				if(arr[i]+arr[j]<=b&&arr[j]!=-1){
					arr[i]=-1;
					arr[j]=-1;
					count++;
					flag=0;
					break;
				}	
			}
			if(flag){
				count++;
				arr[i]=-1;
			}
		}
	}
	printf("%d",count);
	return 0;
}
