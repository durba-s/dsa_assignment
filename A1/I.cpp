#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
void insert(int n){
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr!=NULL){	
		ptr->data=n;
		ptr->next=NULL;
		if(head==NULL){			
			head=ptr;
			last=ptr;
		}
		else{
			last->next=ptr;
			last=last->next;		
		}
	}	
}
void reverse(){
	struct node* prev = NULL;
    struct node* current =head;
    struct node* next = NULL;
    while (current != NULL) {        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head= prev;

}
void display(){
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	int n;
	scanf("%d ",&n);
	while(n!=-1){
		insert(n);
		scanf("%d",&n);
	}
	reverse();
	display();
	return 0;
}
