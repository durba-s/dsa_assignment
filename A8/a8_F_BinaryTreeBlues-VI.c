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
struct Node *lca(struct Node* root, int n1, int n2,int * arr)
{
    while (root != NULL)
    {
        if (arr[root->val] > n1 && arr[root->val] > n2)
        root = root->left;
  
        else if (arr[root->val] < n1 && arr[root->val] < n2)
        root = root->right;
  
        else break;
    }
    return root;
}
int main()
{
    int n,t;
    scanf("%d",&n);
    scanf("%d",&t);
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
    for(int i=0;i<t;i++){
        int n1,n2;
        scanf("%d",&n1);
        scanf("%d",&n2);
        struct Node* temp=lca(root,arr[n1],arr[n2],arr);
        printf("%d\n",temp->val);
    }
    
    return 0;
}

