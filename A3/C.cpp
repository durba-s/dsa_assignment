#include <stdio.h>
#define me 10000ll
const int mod = 0x3b9aca07;
void merging(long long int low, long long int mid,long long int high,long long int* a,long long int *b) {
   long long int l1, l2, i;

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

void sort(long long int low,long long int high,long long int* a,long long int *b) {
   long long int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid,a,b);
      sort(mid+1, high,a,b);
      merging(low, mid, high,a,b);
   } else { 
      return;
   }   
}

long long int t, n, c;
long long int a[me],a1[me];
int main() {
        scanf("%d",&c);
        scanf("%d",&n);
        for(int i = 0; i < n; i ++)
            scanf("%d",&a[i]);
        sort(0,n-1,a,a1);
        long long int low = 0, high = a[n-1], mid, best = 0;
        while(low <= high){
            mid = (low + high + 1) / 2;
            long long int cnt = 1, left = 0;
            for(long long int i = 1; i < n && cnt < c; i ++){
                if(a[i] - a[left] >= mid)
                    left = i, cnt ++;
            }
            if(cnt >= c){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        printf("%d",best);
    
    
    return 0;
}
