#include <stdio.h>
int partitions(int arr[], int n){
   int count = 0;
   int max = arr[0];
   int min=arr[0];
   int temp=1;
   for(int i=1;i<n;i++){
       if(arr[i]<=min){
           min=arr[i];
           temp++;
           continue;
       }
       if(arr[i]>max){
           min=arr[i];
           if(temp>count)
            count=temp;
           temp=1;
           max=arr[i];
       }
   }
   return count;
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
