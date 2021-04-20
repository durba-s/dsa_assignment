#include<stdio.h>
#include<math.h>
int log2(int n)
{   int ret = 0;
    while (n>>=1) 
    {
        ++ret;      
    }
    return ret;
}
int getcount(int m,int k)
{
    if(m==0)
		return 1;
    if(k<0)
		return 0;
    if(k==0)
		return 1;
    if(m>=pow(2,k))
		return getcount(m-pow(2,k),k)+getcount(m,k-1);
    else 
		return getcount(m,k-1);

}
int main()
{
    int m=0;
	scanf("%d",&m);        
	int k=log2(m);
    printf("%d",getcount(m,k));
    
    return 0;
}
