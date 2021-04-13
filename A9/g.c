#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const double DOUBLE_MAX = 1e9;
int result[26]={-1};
 
 
 
int abs_dist(int a,int b){
  return a>b ? a-b:b-a;
 
}
 
 
 
 
 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
 
    int n,s;
    scanf("%lld%lld",&n,&s);
 
    int mx=-1,t=0;
    while(n--){
 
    	int p;
    	char c;
    	scanf("%lld %c\n",&p,&c);
    	if(c=='L'){
    		t=p;
    	}
    	else{
    		t=s-p;
    	}
    	if(t>mx){
    		mx=t;
    	}
 
    }
    printf("%lld",mx);
    
 
 
   return 0;
}
