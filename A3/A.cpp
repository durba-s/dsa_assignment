#include<stdio.h>
#include<stdlib.h>
#define N 10001
long long int abs(long long int a,long long int b){
	long long int diff=a>b?a-b:b-a;
	return diff;
}
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
	int n,m;
	long long int k;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%lld",&k);
	long long int *A=(long long int *)malloc(n*sizeof(long long int));
	long long int *S=(long long int *)malloc(m*sizeof(long long int));
	for(long long int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(long long int i=0;i<m;i++){
		scanf("%d",&S[i]);
	}

	long long int *A1=(long long int *)malloc((n)*sizeof(long long int));
	long long int *S1=(long long int *)malloc((m)*sizeof(long long int));
	sort(0,n-1,A,A1);
	sort(0,m-1,S,S1);
	int i=0, j=0, count=0;
	while(i<n && j<m)
	{
		if(S[j] >= A[i]-k && S[j] <= A[i]+k){
			i++;
			j++;
			count++;
		}
			
		else if(S[j] < A[i]-k){
			j++;
		}
			
		else{
			i++;
		}
			
	}
	printf("%d",count);
	free(A1);
	free(S1);
	free(A);
	free(S);
	return 0;
	
}
