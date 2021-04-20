#include<stdio.h>
#include<stdlib.h>
#define int long long
int merging(int arr[], int temp[], int left, int mid, int right) 
{ 
    int count = 0; 
  
    int i = left; 
    int j = mid;  
    int k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            count = count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return count; 
} 
int sort(int arr[], int temp[], int left, int right) 
{ 
    int mid, count = 0; 
    if (right > left){ 
        mid = (right + left)/2;
        count  = sort(arr, temp, left, mid); 
        count += sort(arr, temp, mid+1, right); 
        count += merging(arr, temp, left, mid+1, right); 
    } 
  
    return count; 
} 
int main(){
	int n;
	scanf("%lld",&n);
	int arr[n];
	for(int i=0;i<n;i++)	scanf("%lld",&arr[i]);
	int temp[n]; 
	printf("%lld",sort(arr, temp, 0, n - 1));
	return 0ll;
}
