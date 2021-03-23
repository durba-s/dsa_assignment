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
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int stack1[n];
    int top1 = -1; 
    int x;
    for (int i=0; i<n; i++)
    {
        while(top1>=0 && arr[stack1[top1]]>arr[i])
            x=pop(stack1,&top1);
        if(top1==-1){
            printf("-1 ");
        }
        else{
            printf("%d ",stack1[top1]+1);
        }
            
        push(i,stack1,&top1);
    }
    
}
