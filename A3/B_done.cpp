#include<stdio.h>
#include<stdlib.h>
struct body{
	long long int skill;
	long long int gold;
};
void merging(int low,int mid,int high,struct body* a,struct body *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].skill <= a[l2].skill)
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

void sort(int low,int high,struct body* a,struct body *b) {
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

int main()
{
    int n,m;    
    long long int agold[10000]={0},askill[10000];
    scanf("%d",&n);
    scanf("%d",&m);
    struct body *inp=(struct body *)malloc((m)*sizeof(struct body));
    
    for(int i=0;i<n;i++){
        scanf("%lld",&askill[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&inp[i].skill);
        scanf("%lld",&inp[i].gold);
    }
 
    struct body *A1=(struct body *)malloc((m)*sizeof(struct body));
	sort(0,m-1,inp,A1);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(inp[j].skill<=askill[i]){
			
				agold[i]+=inp[j].gold;
			}
			else{
				
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%lld ",agold[i]);
	}
    free(A1);
    free(inp);
    
 
    return 0;
}
