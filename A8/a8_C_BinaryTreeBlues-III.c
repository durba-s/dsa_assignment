#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val ;
    struct Node* left;
    struct Node* right;
};
struct Node* root;
struct stackNode{
  struct Node *t;
  struct stackNode *next;
};
struct stackNode *top;
struct stackNode *prev;
int main()
{
    int n;
    scanf("%d",&n);
    int v;
    struct Node* tree[n];
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        tree[i]=malloc(sizeof(struct Node));
        tree[i]->val=v;
        tree[i]->left=NULL;
        tree[i]->right=NULL;
    }
    int c,p;
    char a,c1;
    root=malloc(sizeof(struct Node));
    root=tree[0];
    for(int i=0;i<n-1;i++){
        scanf("%d",&p);
        scanf("%d",&c);
        scanf("%c",&c1);
        scanf("%c",&a);
        scanf("%c",&c1);
        if(a=='L')  tree[p]->left = tree[c];
        if(a=='R')  tree[p]->right = tree[c];
 
    }
    struct Node* current=root;
    struct stackNode* s=NULL;
    int done=0;
    while(done!=1){
        if(current !=  NULL)
        {
            struct stackNode* new=malloc(sizeof(struct stackNode));
            new->t=current;
            new->next=NULL;
            if(top==NULL){
                top=new;
                prev=NULL;
            }
            else{
                new->next=top;
                top=new;
            }                                              
           current = current->left; 
        }
   
        else                                                             
        {
              if (top!=NULL)
              {
                struct stackNode* temp = top;
                current = temp->t;
                top = temp->next;
                free(temp);
                printf("%d ", current->val);
                current = current->right;
              }
              else
                done = 1;
        } 
    }
    return 0;
}
