#include<stdio.h>
void maxheapify(int a[], int i, int heapsize)
{
    int temp, largest, left, right, k;
    left = (2*i+1);
    right = ((2*i)+2);
    if (left >= heapsize)
        return;
    else {
        if (left < (heapsize) && a[left] > a[i]) 
            largest = left;
        else
            largest = i;
        if (right < (heapsize) && a[right] > a[largest])  
            largest = right;
        if (largest != i) {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(a, largest, heapsize);
        }
    }
}
void buildHeap(int arr[], int n) 
{  
    for (int j = n/2; j >= 0; j--) {
        maxheapify(arr, j,n);
    } 
} 
int main(){
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1]-arr[i];
    }
    buildHeap(arr,n-1);
    for(int i=0;i<k;i++){
 
        arr[0]=(arr[0]/2)+(arr[0]%2);
        maxheapify(arr,0,n-1) ;
        
    }
    printf("%d",arr[0]);
    return 0;
}