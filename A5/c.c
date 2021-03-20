#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void sort(int la,int lb,char * a,char *b,char *c) {
    int i=0,j=0,k=0,f1=0,f2=0;
    while(1){
    	if(i>la-1){
    		f1=1;
    		break;
    	}
    	else if(j>lb-1){
    		f2=1;
    		break;
    	}
    	else{
    		if(a[i]>b[j]){
    			c[k]=a[i];
    			k++;
    			i++;
    		}
    		else{
    			c[k]=b[j];
    			k++;
    			j++;
    		}

    	}

    }
    if(f1==1){
    	for(int t=j;t<lb;t++){
    		c[k++]=b[t];
    	}
    }
    else if(f2==1){
    	for(int t=i;t<la;t++){
    		c[k++]=a[t];
    	}
    }   
}
int main(){
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    char arr[200],arr1[200],o[400];
    char c;

    scanf("%s",arr);
    scanf("%c",&c);
    scanf("%s",arr1);
    scanf("%c",&c);
    int j=strlen(arr);
    int k=strlen(arr1);
    sort(j,k,arr,arr1,o);
    for(int i=0;i<j+k;i++){
    	printf("%c",o[i]);
    }
    
}