#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
    return (a>b?b:a);
}
int max(int a,int b){
    return (a>b?a:b);
}
int countPairs(int a[], int n) 
{ 
    int mn = a[0];
    int mx = a[0]; 
    for (int i = 0; i < n; i++) { 
        mn = min(mn, a[i]); 
        mx = max(mx, a[i]); 
    } 
    int c1 = 0; 
    int c2 = 0; // Count variables 
    for (int i = 0; i < n; i++) { 
        if (a[i] == mn) 
            c1++; 
        if (a[i] == mx) 
            c2++; 
    } 
    if (mn == mx) 
        return n * (n - 1) / 2; 
    else
        return c1 * c2; 
} 
int main()
{
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int m;
    scanf("%d",&m);
    int a[m];
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    int mn = a[0];
    int mx = a[0]; 
    for (int i = 0; i < m; i++) { 
        mn = min(mn, a[i]); 
        mx = max(mx, a[i]); 
    } 
    printf("%d %d",mx-mn,countPairs(a,m));
    
    return 0;
}