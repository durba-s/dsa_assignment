#include<stdio.h>
#include <stdio.h>
void merging(int low,int mid,int high,int* a,int *b) {
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

void sort(int low,int high,int* a,int *b) {
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
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
        if (key < ar[mid1]) {
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
    return -1;
}
int main(){
	int n,q;
	scanf("%d",&n);
	scanf("%d",&q);
	int arr[n],a1[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(0,n-1,arr,a1);
	int d;
	while(q--){
		scanf("%d",&d);
		if(ternarySearch(0,n,d,arr)>=0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
	}
	
	return 0;
}
