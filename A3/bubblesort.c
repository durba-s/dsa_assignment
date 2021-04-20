#include<stdio.h>
void bubblesort(int arr[],n){
	int isswapped=0;
	for(int j=0;j<n-2;j++){
		for(int i=0;i<n-j;i++){
			if(arr[i]>arr[i+1]){
				int k=arr[i];
				arr[i]=arr[j];
				arr[j]=k;
				isswapped=1;
			}
		}
		if(isswapped==0)
				return;
	}
	return;
}