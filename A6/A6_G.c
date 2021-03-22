#include <stdio.h>
#define max 10000
int a1[max];
int a2[max];
int a1i=0;
int a2i=0;
int p(int i){
    return (i-1)/2;
}
int l(int i){
    return 1+(2*i);
}
int r(int i){
    return 2+(2*i);
}
int search(int x,int n,int *arr){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}
void desc(int ia,int* arr,int n){
    if(arr[ia]==-1||ia>=n) return;
    if((l(ia)>=n&&r(ia)>=n)||(arr[l(ia)]==-1&&arr[r(ia)]==-1)||(arr[l(ia)]==-1&&r(ia)>=n))
        a1[a1i++]=arr[ia];
    desc(l(ia),arr,n);
    desc(r(ia),arr,n);
    return;
}
void desc1(int ia,int* arr,int n){
    if(arr[ia]==-1||ia>=n) return;
    if((l(ia)>=n&&r(ia)>=n)||(arr[l(ia)]==-1&&arr[r(ia)]==-1)||(arr[l(ia)]==-1&&r(ia)>=n))
        a2[a2i++]=arr[ia];
    desc1(l(ia),arr,n);
    desc1(r(ia),arr,n);
    return;
}
int hd(int n1, int n2) 
{ 
    int x = n1 ^ n2; 
    int setBits = 0; 
  
    while (x > 0) { 
        setBits += x & 1; 
        x >>= 1; 
    } 
  
    return setBits; 
} 
int main()
{
    int n,a,b;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ia=search(a,n,arr);
    int ib=search(b,n,arr);
    if(ia==-1||ib==-1){
        printf("-1");
    }
    else{
        desc(ia,arr,n);
        desc1(ib,arr,n);
        int min=hd(a1[0],a2[0]);
        for(int i=0;i<a1i;i++){
            for(int j=0;j<a2i;j++){
                int d=hd(a1[i],a2[j]);
                if(d<min){
                    min=d;
                }
            }
        }
        printf("%d",min);
        
    }
    return 0;
}
