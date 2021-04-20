#include<stdio.h>
#include<stdlib.h>
struct point{
	long long int diff;
	long long int a;
};
void merging(int low,int mid,int high,struct point* a,struct point *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].diff <= a[l2].diff)
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

void sort(int low,int high,struct point* a,struct point*b) {
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
	int n;
	scanf("%d",&n);
	struct point *arr=(struct point *)malloc(n*sizeof(struct point));
	struct point *a1=(struct point *)malloc(n*sizeof(struct point));
	long long int x,y,amp;
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		scanf("%lld",&y);
		scanf("%lld",&amp);
		arr[i].diff=y-x;
		arr[i].a=amp;
	}
	sort(0,n-1,arr,a1);
	free(a1);
	/*long long int sum1[n]={0},sum2[n]={0};
	sum1[0]=arr[0].a;
	sum2[n-1]=arr[n-1].a;
	for(int i=1;i<n;i++){
			sum1[i]=sum1[i-1]+arr[i].a;
			sum2[n-i-1]=sum2[n-i]+arr[n-i-1].a;
	}
	for(int i=0;i<n-1;i++){
		sum1[i]=sum1[i]-sum2[i+1];
	}
	int flag=0,idx;
		for(int i=0;i<n-1;i++){
		if(sum1[i]==0){
			flag=1;
			idx=i;
			break;
		}
	}*/
	long long int sum=0,s=0;
	int flag=0,idx;
	for(int i=0;i<n;i++){
		sum=sum+arr[i].a;
	}
	
	for(int i=0;i<n;i++){
		if(sum%2==1)	break;
		else if(s=sum/2){
			flag=1;
			idx=i;
			break;
		}
		else{
			s=s+arr[i].a;
		}
	}
	//printf("%d",idx);
	if(flag==0){
		printf("NO");
	}
	else if(arr[idx].diff==arr[idx+1].diff){
		printf("NO");
	}
	else{
		printf("YES");
	}
	
	return 0;
}
