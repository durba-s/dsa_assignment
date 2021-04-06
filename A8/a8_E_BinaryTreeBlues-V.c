#include<stdio.h>
int t=0;
int j= 0;
void getPostOrder(int si, int ei,int n,int* in, int* pr)
{
    if (si<=ei){
    int i=0;
    for(i=si;i<ei;i++){
        if(in[i]==pr[j]){
            break;
        }
    }
    j++;
    getPostOrder(si,i-1,n,in,pr);
    getPostOrder(i+1,ei,n,in,pr);
    if(t<n-1){
        printf("%d ",in[i]);
        t++;
       }
    else{
        printf("%d",in[i]);
    }
    }
    else{
        return;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int pr[n],in[n];
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }
    getPostOrder(0,n-1,n,in,pr);
    return 0;
}
