#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int queue[500000];
int queue2[500000];
 
int f1,r1;
int f2,r2;
int n;
 
int size1(){
	return (-f1+r1);
}
int isEmpty1(){
	return f1==r1;
}
int front1(){
	return queue[f1];
}
void dequeue1(){
	for(int i=0;i<r1-1;i++){
	    queue[i]=queue[i+1];
	}
	r1--;
}
void enqueue1(int x){
	queue[r1]=x;
	r1=(r1+1);
}
 
 
int size2(){
	return (-f2+r2);
}
int isEmpty2(){
	return f2==r2;
}
int front2(){
	return queue2[f2];
}
void dequeue2(){
	for(int i=0;i<r2-1;i++){
	    queue2[i]=queue2[i+1];
	}
	r2--;
}
void enqueue2(int x){
	queue2[r2]=x;
	r2=(r2+1);
}
 
 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
 
    int n;
    scanf("%lld",&n);
    int top;
    while(n--){
    	char s[10];
    	scanf("%s",&s);
    	if(!strcmp(s,"PUSH")){
    	int x;
    	scanf("%lld",&x);
    	if(isEmpty1()&&isEmpty2()){
    	        	enqueue1(x);
 
    	}
    	else if(!isEmpty1()){
    	    enqueue1(x);
    	}
    	else if(!isEmpty2()){
    	    enqueue2(x);
    	}
        }
        if(!strcmp(s,"PRINT")){
            if(isEmpty1()){
        		while(size2()>1){
        			int t=front2();
        			dequeue2();
        			enqueue1(t);
        		}
        		top=front2();
        		enqueue1(top);
        		dequeue2();
        	}
        	else{
        		while(size1()>1){
        			int t=front1();
        			dequeue1();
        			enqueue2(t);
        		}
        		top=front1();
        		enqueue2(top);
        		dequeue1();
 
        	}
        	printf("%lld\n",top);
        	
        		
        }
        if(!strcmp(s,"POP")){
        	if(isEmpty1()){
        		while(size2()>1){
        			int t=front2();
        			dequeue2();
        			enqueue1(t);
        		}
        		top=front2();
        		dequeue2();
        	}
        	else{
        		while(size1()>1){
        			int t=front1();
        			dequeue1();
        			enqueue2(t);
        		}
        		top=front1();
        		dequeue1();
 
        	}
 
        }
 
 
 
 
    } 
 
   return 0;
}
