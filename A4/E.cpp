#include<stdio.h>
#include<stdlib.h>
#define max 3e10
#define min  -300000000
struct point{
	long long int x;
	long long int y;
	int q;
	double m;
};
long long int abso(long long int a,long long int b){
	return a>b?a-b:b-a;
}
long long int dist(long long int x1,long long int x2,long long int y1,long long int y2){
	return abso(x1,x2)+abso(y1,y2);
}
void merging(int low,int mid,int high,struct point* a,struct point *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].q < a[l2].q)
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
void merging1(int low,int mid,int high,struct point* a,struct point *b) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1].m <= a[l2].m)
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

void sort1(int low,int high,struct point* a,struct point*b) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort1(low, mid,a,b);
      sort1(mid+1, high,a,b);
      merging1(low, mid, high,a,b);
   } else { 
      return;
   }   
}

int main(){
	int n;
	scanf("%d",&n);
	struct point * inp=(struct point *)malloc(n*sizeof(struct point));
	struct point * inp1=(struct point *)malloc(n*sizeof(struct point));
	for(int i=0;i<n;i++){
		scanf("%lld",&inp[i].x);
		scanf("%lld",&inp[i].y);
		long long int x=inp[i].x;
		long long int y=inp[i].y;
		if(inp[i].y==0.0&&inp[i].x>0){
			inp[i].q=0;
			inp[i].m=0;
		}
		else if(inp[i].y>0&&inp[i].x>0){
			inp[i].q=1;
			inp[i].m=y/x;
		}
		else if(inp[i].y>0&&inp[i].x==0.0){
			inp[i].q=2;
			inp[i].m=max;
		}
		else if(inp[i].y>0&&inp[i].x<0){
			inp[i].q=3;
			inp[i].m=y/x;
		}
		else if(inp[i].y==0.0&&inp[i].x<0){
			inp[i].q=4;
			inp[i].m=0;
		}
		else if(inp[i].y<0&&inp[i].x<0){
			inp[i].q=5;
			inp[i].m=y/x;
		}
		else if(inp[i].y<0&&inp[i].x==0.0){
			inp[i].q=6;
			inp[i].m=min;
		}
		else if(inp[i].y<0&&inp[i].x>0){
			inp[i].q=7;
			inp[i].m=min;
		}
	}
	
	sort(0,n-1,inp,inp1);

	int count[8]={0},sum[8]={0};
	sum[0]=count[0];
	for(int i=0;i<n;i++){
		if(inp[i].q==i)	count[i]++;
	}
	for(int i=0;i<8;i++){
			sum[i]=sum[i-1]+count[i];
		
	}
	for(int i=0;i<8;i++){
		if(count[i]>0){
			int idx=count[i];
			
			inp1=(struct point *)malloc(n*sizeof(struct point));
			if(i==0)
				sort1(0,idx-1,inp,inp1);
			else{
				int cou1=sum[i-1];
				sort1(cou1,cou1+idx-1,inp,inp1);
			}
				
			
		}
	}
	long long int res=dist(inp[0].x,inp[n-1].x,inp[0].y,inp[n-1].y);
	for(int i=0;i<n-1;i++){
		res+=dist(inp[i].x,inp[i+1].x,inp[i].y,inp[i+1].y);
	}
	printf("%lld",res);
	return 0;
}
