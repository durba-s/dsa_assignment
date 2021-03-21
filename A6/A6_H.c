#include <stdio.h>
#define MAX 10000
void push(int data,int stack[], int *top)  
{ 
   if(*top != MAX-1) // if stack is not full
   {  *top = *top + 1;   
      stack[*top] = data;
        
   } 	
   else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}
int pop(int stack[], int *top) 
{
   int data;	
   if(*top != -1) //checking whether stack contains some elements
   {
      data = stack[*top];
      *top = *top - 1;
	    
      return data;
   } 
   else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}
void fun(int n,char* arr,char* fin){
    int square[MAX];
    int curly[MAX];
    int square_top = -1; 
    int curly_top = -1;
    int i=0;
    int j=0;
    while(i<n&&j<n){
        if(arr[i]=='('){
            push(i,curly,&curly_top);
        }
        else if(arr[i]=='['){
            push(i,square,&square_top);
        }
        else if(arr[i]>='a'&&arr[i]<='z'&&square_top==-1&&curly_top==-1){
            fin[j++]=arr[i];
        }
        else if(arr[i]==')'){
            int st=pop(curly,&curly_top);
            for(int p=i-1;p>st;p--){
                fin[j++]=arr[p];
            }
        }
        else if(arr[i]==']'){
            int st=pop(square,&square_top);
            for(int p=st+1;p<i;p++){
                if(arr[p]<'z'){
                    fin[j++]=arr[p]+1;
                }
                else{
                    fin[j++]='a';
                }
            }
            
        }
        i++;
    }
    
    
}
int main()  
{ 
    char arr[MAX],fin[MAX],c1;
    scanf("%s",arr);
    scanf("%c",&c1);
    int l=0;
    for(l=0;arr[l]!='\0';l++);;
    fun(l,arr,fin);
    printf("%s",fin);
    return 0;  
}  
