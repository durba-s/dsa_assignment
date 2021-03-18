#include <stdio.h>
int count=0;
int partitions(int arr[], int r){
    int idx=r-1;
    if(idx<0){
	    return count;
	}
	int max=0;
	for(int i=0;i<r;i++)
	    if(arr[i]>max){
	         max=arr[i];
	         idx=i;
	    }
	count++;
	partitions(arr,idx);

}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",partitions(arr,n));

    return 0;
}
