#include<stdio.h>
#include<stdlib.h>
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
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	long long int rest[m],mon[n],a[m];
	int vis[n];
	for(int i=0;i<m;i++){
		scanf("%lld",&rest[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&mon[i]);
	}
	sort(0,m-1,rest,a);
	int idx=0;
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			if(rest[j]<=mon[i]){
				idx=j+1;
				break;
			}
		}
		vis[i]=idx;
		idx=0;
	}
	for(int i=0;i<n;i++){
		printf("%lld ",vis[i]);
	}
	return 0;
}
