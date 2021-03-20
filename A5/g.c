#include <stdio.h>
#define int long long
#define MAX = 1e9;
void merge(int arr[],int l,int m,int r){
  int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
 
 
}
 
void mergeSort(int arr[],int l,int r){
  if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
 
  }
 
} 
int main() {
   
    int n,q;
    scanf("%lld %lld",&n,&q);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%lld",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    int sum[n];
    for (int i = 0; i < n; ++i)
    {
    	sum[i]=0;
    }
    sum[0]=arr[0];
    for (int i = 1; i < n; ++i)
    {
    	sum[i]=sum[i-1]+arr[i];
    }
    while(q--){
        int k;
        scanf("%lld",&k);
        printf("%lld\n",sum[n-1]-2*sum[k-1]);
    }
 
 
   return 0ll;
}
