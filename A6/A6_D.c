#include <stdio.h>
int main()
{
    int n,k,x;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&x);
    int stud[n],stop[k],total;
    int extra[n],ind[n];
    for(int i=0;i<n;i++){
        scanf("%d",&stud[i]);
        extra[i]=0;
        ind[i]=0;
    }
    for(int i=0;i<k;i++){
        scanf("%d",&stop[i]);
        ind[stop[i]]=1;
    }
    extra[0]=stud[0]*ind[0];
    int tot=stud[0]*(1-ind[0]);
    for(int i=1;i<n;i++){
        extra[i]=extra[i-1]+stud[i]*ind[i];
        tot=tot+stud[i]*(1-ind[i]);
        
    }
    int max=tot;
    for(int i=0;i<k;i++){
        int last=(stop[i]+x-1)>=n?n-1:(stop[i]+x-1);
        int x1=stop[i]>0?extra[stop[i]-1]:0;
        int temp=extra[last]-x1;
        if((tot+temp)>max)
            max=temp+tot;
        
    }
    printf("%d %d",tot,max);
    return 0;
}
