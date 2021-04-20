#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e6;
int result[100000];
void merge(long long int arr[],long long int l,long long int m,long long int r){
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 = r - m;
    long long int L[n1], R[n2];
    long long int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        l1[i]=arr[l+i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        r1[j]=arr[m+j+1];
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr[k] = l1[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr[k]= r1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        arr[k] = r1[j];
        j++;
        k++;
    }
 
 
}
 
void mergeSort(long long int arr[],long long int l,long long int r){
    if(l<r){
        long long int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
 
    }
 
}
int main(){
    long long int n,m,l;
    scanf("%lld %lld %lld",&n,&m,&l);
    long long int u,v,a,b,k;
    scanf("%lld %lld %lld %lld %lld",&u,&v,&a,&b,&k);
    long long int t[m];
    for (long long int i = 0; i < m; ++i)
    {
        scanf("%lld",&t[i]);
    }
    long long int g[l];
    for (long long int i = 0; i < l; ++i)
    {
        scanf("%lld",&g[i]);
    }
    mergeSort(t,0,m-1);
    mergeSort(g,0,l-1);
    long long int sum=0;
    long long int start=0,end=m-1;;
    long long int lr=0,rr=m-1;
    while(lr<rr){
         long long int mr = (lr+rr)/2;
         if(t[mr]<u){
             lr=mr+1;
         }
         else{
             rr=mr;
         }
    }
    start = lr;
    lr=0,rr=m-1;
    while(lr<rr){
         long long int mr = (lr+rr)/2;
         if(t[mr]<v){
             lr=mr+1;
         }
         else{
             rr=mr;
         }
    }
    end = lr;
    long long int f=0;
    for (long long int i = start; i < end ; ++i)
    {
        //printf("%lld->",t[i]);
 
        long long int d = ((t[i+1]-t[i])-b);
        if(d%a){
            d/=a;
            d++;
        }
        else{
           d/=a;
 
        }
        //printf("%lld ",d);
 
        if(d>g[l-1]){
            f=1;
            break;
        }
        long long int left = 0,right = l-1;
        
        while(left<right){
            long long int mid = left + (right-left)/2;
            if(g[mid]>=d){
                right=mid;
            }
            else{
                left=mid+1;
            }
 
        }
        sum += g[left];
        //printf("%lld \n",g[left]);
  
    }
    if(f){
        printf("NOT POSSIBLE");
    }
    else{
    printf("%lld",sum*k);}
    return 0;
}
