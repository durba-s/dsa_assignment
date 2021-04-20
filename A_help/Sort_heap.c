#include <stdio.h>
void maxHeapify(int arr[],int n,int i){
    int l=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[l])
        l=left;
    if(right<n&&arr[right]>arr[l])
        l=right;
    if(l!=i){
        int temp=arr[l];
        arr[l]=arr[i];
        arr[i]=temp;
        maxHeapify(arr,n,l);
    }
}
void buildMaxHeap(int arr[],int n){
    int start=(n/2)-1;
    for(int i=start;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}
int main()
{
    int n=5;
    int arr[5]={21,12,43,4,35};
    buildMaxHeap(arr,5);
    for(int i=0;i<n;i++){
        printf("%d ",arr[0]);
        int temp=arr[n-i-1];
        arr[n-i-1]=arr[0];
        arr[0]=temp;
        maxHeapify(arr,n-i-1,0);
    }
    return 0;
}
