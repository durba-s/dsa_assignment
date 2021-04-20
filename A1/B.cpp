#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *prev;
	struct node *next;
};
struct node *head;
struct node *last;
void insert(char c){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *temp;
	if(ptr!=NULL){
		ptr->data=c;
		if(head==NULL){
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
			last=ptr;
		}
		else{
			temp=last;
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
			last=ptr;
		}
	}
}

bool palindrome(){
	if(head->next==NULL)
		return true;
	else{
		struct node *temp1;
		struct node *temp2;
		temp1=head;
		temp2=last;
		while(temp1!=temp2&&temp1->prev!=temp2){
			if(temp1->data!=temp2->data)
				return false;
			temp1=temp1->next;
			temp2=temp2->prev;			
		}
		return true;		
	}
}

int main(){
	int n;
	char c;
	scanf("%d",&n);
	scanf("%c",&c);
	while(n--){
		scanf("%c",&c);
		insert(c);
	}
	if(palindrome()){
		printf("PALINDROME");
	}
	else{
		printf("NOT A PALINDROME");
	}
	return 0;
}
