#include <stdio.h>

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
    int cr=0;
    for(int i=0;i<k;i++){
        int n2;
        scanf("%d",&n2);
        cr=cr+n2;
        printf("%d %d\n",arr[cr%n],arr[(n+(cr%n)-1)%n]);
    }
   
    return 0;  
}  
