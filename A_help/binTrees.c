#include <stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node* left;
    struct node* right;
};
struct node* root;
struct node* newNode(int n){
    struct node* new=malloc(sizeof(struct node));
    new->v=n;
    new->left=NULL;
    new->right=NULL;
    return new;
}
struct node* findParent(int x,struct node* current){
    if(current==NULL)   return NULL;
    else if(current->left!=NULL&&current->left->v==x)
        return current;
    else if(current->right!=NULL&&current->right->v==x)
        return current;
    struct node* left_search=findParent(x,current->left);
    if(left_search!=NULL)   return left_search;
    else return findParent(x,current->right);
}
struct node* findNode(int x,struct node* current){
    if(current==NULL)   return NULL;
    else if(current->v==x)
        return current;
    struct node* left_search=findNode(x,current->left);
    if(left_search!=NULL)   return left_search;
    else return findNode(x,current->right);
}
void insert(int c,int p,char dir){
    struct node* chi=newNode(c);
    struct node* par=findNode(p,root);
    if(dir=='L'){
        par->left=chi;
        return;
    }
    else{
        par->right=chi;
        return;
    }
}
void pre_order(struct node* current){
    if(current!=NULL){
        printf("%d ",current->v);
        pre_order(current->left);
        pre_order(current->right);
    }
}
void post_order(struct node* current){
    if(current!=NULL){
        post_order(current->left);
        post_order(current->right);
        printf("%d ",current->v);
    }
}
void in_order(struct node* current){
    if(current!=NULL){
        in_order(current->left);
        printf("%d ",current->v);
        in_order(current->right);
    }
}
void delete(int v){}
void swap(int v){}
int main()
{
    int n=5;
    int arr[5]={1,2,3,4,5};
    root=newNode(1);
    insert(2,1,'L');
    insert(5,1,'R');
    insert(3,2,'L');
    insert(4,2,'R');
    pre_order(root);
    return 0;
}
