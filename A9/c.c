#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
#define SIZE 200000
 
const int MAX = 1e9;
int cou[100000000];
int flag[10000000];
 
 
 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
 
 
 
    int n;
    scanf("%lld",&n);
    int arr[n];
    int min[n];
    int k=0;
    for(int i=0;i<n;i++){
    	scanf("%lld",&arr[i]);
    	cou[arr[i]]++;
    	if(arr[i]%2==0&&cou[arr[i]]==1){
    		min[k]=arr[i];
    		k++;
    	}
    }
    int c=0;
    for(int i=0;i<k;i++){
        if(flag[min[i]]){
        	continue;
        }
        //printf("%lld\n",min[i]);
        while(min[i]%2==0){
        	
    		c++;
    		flag[min[i]]=1;	
    		min[i]/=2;}
    		
    	
    }
    printf("%lld",c);
 
    
 
 
    
    return 0;
}
