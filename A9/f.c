#include<stdio.h>
#include<stdlib.h>
#define int long long int
struct Node {
    int val ;
    struct Node* left;
    struct Node* right;
};
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
    if (node->val==v)
        return node;
    if(v<(node->val))
        return findNode(v,node->right);
    return findNode(v,node->left);
}
struct Node* insertBST(int v,struct Node* node){
     if (node==NULL)
        return createNode(v);
    if (node->val<v)
        node->right = insertBST(v,node->right);
    else if (node->val>v)
        node->left = insertBST(v,node->left);
    return node;
}
void printPostOrder(struct Node* current,int n){
    
    if(current==NULL)
        return;
    else{
        printPostOrder(current->left,n);
        printPostOrder(current->right,n);
        if(current->val!=n){
        printf("%lld ",current->val);
        }
        else{
           printf("%lld",current->val);
        }
    }
}
int main(){
    int n;
    scanf("%lld",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    int s=1;
    struct Node* root=createNode(arr[0]);
    for(int i=1;i<n;i++){
        if(findNode(arr[i],root)==NULL){
            insertBST(arr[i],root);
            s++;
        }
    }
    printPostOrder(root,root->val);
    return 0ll;
    
}
