#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val ;
    struct Node* left;
    struct Node* right;
};
struct Node* root;
struct Node* createNode(int v){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->val=v;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* findNode(int v,struct Node* node){
    if (node == NULL)
        return NULL;
    if (node->val == v)
        return node;
    struct Node* ls = findNode(v,node->left);
    if(ls!=NULL) return ls;
    struct Node* rs = findNode(v,node->right);
    return rs;
}
void insertNode(int p,int c,char d){
    struct Node* childNode=createNode(c);
    if(findNode(p,root)==NULL){
        struct Node* newNode=createNode(p);
        if(d=='L')  newNode->left=childNode;
        else     newNode->right=childNode;
        return;
    }
    else{
        struct Node* newNode=findNode(p,root);
        if(d=='L')  newNode->left=childNode;
        else   newNode->right=childNode;
        return;
    }
}
void pre_order_traversal(struct Node* current,int *arr) {
   if(current != NULL) {
      printf("%d ",arr[current->val]);
      pre_order_traversal(current->left,arr);
      pre_order_traversal(current->right,arr);
   }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int c,p;
    char a,c1;
    root=malloc(sizeof(struct Node));
    root->val=0;
    for(int i=0;i<n-1;i++){
        scanf("%d",&c);
        scanf("%d",&p);
        scanf("%c",&c1);
        scanf("%c",&a);
        scanf("%c",&c1);
        insertNode(c,p,a);
    }
    pre_order_traversal(root,arr);
    return 0;
}

