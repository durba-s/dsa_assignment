#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define mod 1000000007
long long unsigned int stoll(char arr[],int j){
	long long unsigned int n=0;
	long long unsigned int p=1;
	for(int i=j-1;i>=0;i--){
		int a=(arr[i])-'0';
		n+=a*p;
		p=p*10;
	}
	return n;
}
long long unsigned int sum(char arr[]){
	long long unsigned int sum=0;
	char a[11]={'\0'};
	int j=0;
	for(int i=0;i<=strlen(arr);i++){

		if(arr[i]<'0'||arr[i]>'9'){
			a[j]='\0';
			sum+=stoll(a,j);
			j=0;

		}
		else{
			a[j]=arr[i];
			j++;
		}
	}
	return sum;
}
void merging(int low,int mid,int high,long long unsigned int* a,long long unsigned int *b) {
   int l1, l2, i;
 
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1]< a[l2])
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
 
void sort(int low,int high,long long unsigned int * a,long long unsigned int *b) {
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
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,t;
    scanf("%d",&n);
    scanf("%d",&t);
    char str[100];
    char c;
    long long unsigned int arr[n],arr1[n];
    int k=0;
    for(int i=0;i<n;i++){
    	scanf("%s",str);
    	scanf("%c",&c);
    	arr[k]=sum(str);
    	k++;
    }
    sort(0,n-1,arr,arr1);
    long long unsigned int s=0;
    for(int i=n-1;i>(n-1)-t;i--){
    	s+=(arr[i]%mod);
    }
    printf("%llu",s);
    return 0;
}