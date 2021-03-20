#include <stdio.h>  
#include <stdlib.h>   
void lr(int *arr,int n,int l){
    int temp[n];
    int count=0,j=0;
    for(int i=0;i<l;i++){
        temp[i]=arr[i];
    }
    for(int i=l;i<n;i++){
        arr[count]=arr[i];
        count++;
    }
    for(int i=count;i<n;i++){
        arr[i]=temp[j];
        j++;
    }
}
int main()  
{ 
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        int n1;
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<k;i++){
        int n2;
        scanf("%d",&n2);
        lr(arr,n,n2);
        printf("%d %d\n",arr[0],arr[n-1]);
    }
   
    return 0;  
}  
