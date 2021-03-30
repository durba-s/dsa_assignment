#include <stdio.h>
#include<stdlib.h>
struct node{
    int num;
    struct node* next;
};
struct node *head=NULL,*tail=NULL;
void insert(int x){
    struct node *new=malloc(sizeof(struct node));
    new->num=x;
    new->next=NULL;
    if(head==NULL){
        head=new;
        tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}
void delete(int x){
    struct node *new=malloc(sizeof(struct node));
    struct node *prev=malloc(sizeof(struct node));
    new=head;
    while(new!=NULL){
        if(new->num==x){
            if(new!=head){
                prev->next=new->next;
                return;
            }
            else{
                head=new->next;
                return;
            }
        }
        prev=new;
        new=new->next;
    }
}
void checkParity()
void print(){
    struct node *new=malloc(sizeof(struct node));
    new=head;
    while(new!=NULL){
        printf("%d ",new->num);
        new=new->next;
    }
}
int main()
{
    insert(1);
    insert(8);
    insert(3);
    insert(4);
    insert(15);
    insert(6);
    insert(1);
    delete(1);
    print();
    return 0;
}
