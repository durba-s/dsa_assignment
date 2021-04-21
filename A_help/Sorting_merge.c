#include <stdio.h>
void merge(int l,int m,int r,int arr[]){
    int la=m-l+1;
    int ra=r-m;
    int i=0,j=0,k=l;
    int L[la],R[ra];
    for(int p=0;p<la;p++){
        L[p]=arr[l+p];
    }
    for(int p=0;p<ra;p++){
        R[p]=arr[m+1+p];
    }
    while(i<la&&j<ra){
        if(R[j]<=L[i]){
            arr[k++]=R[j++];
        }
        else{
            arr[k++]=L[i++];
        }
    }
    while(i<la){
        arr[k++]=L[i++];
    }
    while(j<ra){
        arr[k++]=R[j++];
    }
}
void mergeSort(int srt,int end,int arr[]){
    if(end<=srt) return;
    int mid=(srt+end)/2;
    mergeSort(srt,mid,arr);
    mergeSort(mid+1,end,arr);
    merge(srt,mid,end,arr);
}
int main()
{
    int n=5;
    int A[5]={21,12,43,4,35};
    mergeSort(0,4,A);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
