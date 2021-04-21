#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main () {
   int values[] = { 88, 56, 100, 2, 25 };
   qsort(values, 5, sizeof(int), cmpfunc);
   for(int n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
   return(0);
}


//
int partition(int arr[],int l,int h){
    int e=arr[h];
    int i=l;
    int j=l;
    while(j<h){
        if(e>=arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
        j++;
    }
    int temp=arr[h];
    arr[h]=arr[i];
    arr[i]=temp;
    return i;
}
void quicksort(int arr[],int l,int h){
    if(h<=l)    return;
    int m=partition(arr,l,h);
    quicksort(arr,l,m-1);
    quicksort(arr,m+1,h);
}
