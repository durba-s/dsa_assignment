#include<stdio.h>
#include<stdlib.h>
#define N 10001
void merging(int low,int mid,int high,long long int* a,long long int *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low,int high,long long int* a,long long int *b) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid,a,b);
      sort(mid+1, high,a,b);
      merging(low, mid, high,a,b);
   } else { 
      return;
   }   
}
int main(){
	int n,idx;
	long long int k1,k2;
	scanf("%d",&n);
	long long int arr[N];
	scanf("%lld",&k1);
	scanf("%lld",&k2);
	long long int k,b;
	k=k2-k1;
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&b);
		arr[i]=arr[i]-b;
	}
	long long int *A1=(long long int *)malloc(n*sizeof(long long int));
	sort(0,n-1,arr,A1);
	long long int nop=0;

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]>k){
				idx=n-j;
				break;
			}
		}
		if(idx!=0){
			nop=nop+idx;
			idx=0;
		}
	}

		
	
	printf("%lld",nop);
	
	return 0;
}

