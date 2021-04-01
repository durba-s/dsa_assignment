#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val ;
    struct Node* left;
    struct Node* right;
};
struct Node* root;
void pre_order_traversal(struct Node* current) {
   if(current != NULL) {
      printf("%d ",current->val);
      pre_order_traversal(current->left);
      pre_order_traversal(current->right);
   }
}
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
        else   tree[p]->right = tree[c];
 
    }
    pre_order_traversal(root);
    return 0;
}
