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

void display(){
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%c",temp->data);
		temp=temp->next;
	}
}

void LR(){
	if(head->next==NULL){		
	}
	else{	
		struct node *temp1;
		struct node *temp2;
		temp1=head;
		temp2=head->next;
		head=temp2;
		head->prev=NULL;
		last->next=temp1;
		temp1->prev=last;
		last=temp1;
		last->next=NULL;
	}
}

void RR(){
	if(head->next==NULL){		
	}
	else{
		struct node *temp1;
		struct node *temp2;
		temp1=last;
		temp2=last->prev;
		last=temp2;
		last->next=NULL;
		temp1->next=head;
		head->prev=temp1;
		head=temp1;
		temp1->prev=NULL;
	}
}

void LS(){
	LR();
	last->data='0';	
}

void RS(){
	RR();
	head->data='0';	
}

void INC(){
	char carr='1';
	struct node *ptr;
	ptr=last;
	while(ptr!=NULL){
		if(ptr->data=='0'&&carr=='0'){
			ptr->data='0';
			carr='0';
		}
		else if(ptr->data=='0'&&carr=='1'){
			ptr->data='1';
			carr='0';
		}
		else if(ptr->data=='1'&&carr=='0'){
			ptr->data='1';
			carr='0';
		}
		else if(ptr->data=='1'&&carr=='1'){
			ptr->data='0';
			carr='1';
		}
		ptr=ptr->prev;
			
	}	
}

void DEC(){
	char carr='0';
	struct node *ptr;
	ptr=last;
	while(ptr!=NULL){
		if(ptr->data=='0'&&carr=='0'){
			ptr->data='1';
			carr='0';
		}
		else if(ptr->data=='0'&&carr=='1'){
			ptr->data='0';
			carr='1';
		}
		else if(ptr->data=='1'&&carr=='0'){
			ptr->data='0';
			carr='1';
		}
		else if(ptr->data=='1'&&carr=='1'){
			ptr->data='1';
			carr='1';
		}
		ptr=ptr->prev;
			
	}
			
}

int main(){
	char c,c1,c2;
	scanf("%c",&c);
	while(c!='\n'){
		insert(c);
		scanf("%c",&c);
	}
	int n;
	char query;
	scanf("%d",&n);
	scanf("%c",&c1);
	while(n--){
		scanf("%c",&query);
		if(query=='L'){
			scanf("%c",&query);
			scanf("%c",&c1);
			if(query=='R')
				LR();
			else
				LS();
		}
		else if(query=='R'){
			scanf("%c",&query);
			scanf("%c",&c1);
			if(query=='R')
				RR();
			else
				RS();
		}
		else if(query=='I'){
			scanf("%c",&query);
			scanf("%c",&c1);
			scanf("%c",&c2);
			INC();
		}
		else{
			scanf("%c%c",&query,&query);
			scanf("%c",&c1);			
			DEC();
		}				
	}
	display();
	return 0;
}
