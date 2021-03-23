#include <stdio.h>
#define MAX 100001
void push(int data,int stack[], int *top)  
{ 
   if(*top != MAX-1) 
   {  *top = *top + 1;   
      stack[*top] = data;
        
   } 	
   else 
    printf("Stack Full");
}
int pop(int stack[], int *top) 
{
   int data;	
   if(*top != -1) 
   {
      data = stack[*top];
      *top = *top - 1;
	    
      return data;
   } 
   else 
    return -1;
}
void reverse(char s[],int a,int b){
    for(int i=a;i<=(a+b-1)/2;i++){
 
        char t=s[i];
        s[i]=s[b-i+a];
        s[b-i+a]=t;
    } 
}
 
void inc(char s[],int a,int b){
     for(int i=a;i<=b;i++){
        if(s[i]>='a'&&s[i]<'z')
            s[i]++;
        else if(s[i]=='z')
            s[i]='a';
    } 
}
void fun(int n,char* arr){
    int square[MAX];
    int curly[MAX];
    int square_top = -1; 
    int curly_top = -1;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]=='('){
            push(i,curly,&curly_top);
        }
        else if(arr[i]=='['){
            push(i,square,&square_top);
        }
        else if(arr[i]==')'){
            int x=pop(curly,&curly_top);
            reverse(arr,x+1,i-1);
        }
        else if(arr[i]==']'){
            int x=pop(square,&square_top);
            inc(arr,x+1,i-1);
            
        }
    }
    
    
}
int main()  
{ 
    char arr[MAX],c1;
    scanf("%s",arr);
    scanf("%c",&c1);
    int l=0;
    for(l=0;arr[l]!='\0';l++);;
    fun(l,arr);
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]>='a'&&arr[i]<='z')
            printf("%c",arr[i]);
 
    }
    return 0;  
} 
