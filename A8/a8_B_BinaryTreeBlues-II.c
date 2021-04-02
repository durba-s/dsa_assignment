#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
struct Node {
    int val ;
    struct Node* left;
    struct Node* right;
};
struct Node* root;
struct stackNode{
    struct Node* t;
    struct stackNode* next;
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
int i1=0,i2=0,i3=0;
void pre_order_traversal(struct Node* current,int arr[],int arr1[])
{
    if(current != NULL) {
      arr1[i1++]=arr[current->val];
      pre_order_traversal(current->left,arr,arr1);
      pre_order_traversal(current->right,arr,arr1);
   }
}
void post_order_traversal(struct Node* current,int arr[],int arr1[])
{
    if(current != NULL) {
      post_order_traversal(current->left,arr,arr1);
      post_order_traversal(current->right,arr,arr1);
      arr1[i2++]=arr[current->val];
   }
}
void in_order_traversal(struct Node* current,int arr[],int arr1[])
{
    if(current != NULL) {
      in_order_traversal(current->left,arr,arr1);
      arr1[i3++]=arr[current->val];
      in_order_traversal(current->right,arr,arr1);
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
    int pr[n],po[n],in[n];
    pre_order_traversal(root,arr,pr);
    post_order_traversal(root,arr,po);
    in_order_traversal(root,arr,in);
    int sum=0;
    for(int i=0;i<n;i++){
        int diff=pr[i]>po[i]?(pr[i]-po[i]):(po[i]-pr[i]);
        diff=(diff*in[i])%mod;
        sum=(sum+diff)%mod;
        
    }
    printf("%d",sum);
    return 0;
}
