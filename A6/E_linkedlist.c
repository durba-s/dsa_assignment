#include <stdio.h>  
#include <stdlib.h>   
struct node{  
    int num;  
    struct node *next;  
};
struct node *head, *tail= NULL;  
void addNode(int n) { 
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->num = n;  
    newNode->next = NULL;  
    if(head == NULL) {  
        head = newNode;  
        tail = newNode;
    }  
    else {  
        tail->next = newNode;
        tail = newNode;  
    }  
} 
void lr(int n){
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    temp1=head;
    for(int i=0;i<n-1;i++){
        temp1=temp1->next;
    }
    tail->next=head;
    tail=temp1;
    head=temp1->next;
    tail->next=NULL;
    
    
}
int main()  
{ 
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        int n1;
        scanf("%d",&n1);
        addNode(n1);
    }
    for(int i=0;i<k;i++){
        int n2;
        scanf("%d",&n2);
        lr(n2);
        printf("%d %d\n",head->num,tail->num);
    }
   
    return 0;  
} 
