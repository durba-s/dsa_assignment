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
struct Node* getParent(int v,struct Node* node){
    if(node==NULL)  return NULL;
    if (node->left == NULL && node->right==NULL)
        return NULL;
    if (node->left!=NULL&&node->left->val == v)
        return node;
    if (node->right!=NULL&&node->right->val == v)
        return node;
    struct Node* ls = getParent(v,node->left);
    if(ls!=NULL) return ls;
    struct Node* rs = getParent(v,node->right);
    return rs;
}
void swap(int a,int b,struct Node* root){
    struct Node* ap=getParent(a,root);
    struct Node* bp=getParent(b,root);
    if(ap==NULL||bp==NULL){
        if(ap==NULL&&bp==NULL)  return;
        if(ap!=NULL){
            if(ap->left!=NULL&&ap->left->val==a)  ap->left=NULL;
            else    ap->right=NULL;
        }
        else{
            if(bp->left!=NULL&&bp->left->val==b)  bp->left=NULL;
            else    bp->right=NULL;
        }
    }
    else{
    if(ap->left!=NULL&&ap->left->val==a){
        if(bp->left!=NULL&&bp->left->val==b){
            struct Node* temp=ap->left;
            ap->left=bp->left;
            bp->left=temp;
        }
        else{
            struct Node* temp=ap->left;
            ap->left=bp->right;
            bp->right=temp;
        }
    }
    else{
         if(bp->left!=NULL&&bp->left->val==b){
            struct Node* temp=ap->right;
            ap->right=bp->left;
            bp->left=temp;
        }
        else{
            struct Node* temp=ap->right;
            ap->right=bp->right;
            bp->right=temp;
        }
        
    }
    }
    
}
void delete(int a,struct Node* root){
    struct Node* ap=getParent(a,root);
    if(ap==NULL)    return;
    if(ap->right!=NULL&&ap->right->val==a)  ap->right=NULL;
    else    ap->left=NULL;
}
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct Node* node)
{
    if (node == NULL)
        return 0;
 
    return 1+max(height(node->left), height(node->right));
}
int diameter(struct Node* tree)
{
    if (tree == NULL)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight,max(ldiameter, rdiameter));
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
    root->val=arr[0];
    for(int i=0;i<n-1;i++){
        scanf("%d",&p);
        scanf("%d",&c);
        scanf("%c",&c1);
        scanf("%c",&a);
        scanf("%c",&c1);
        insertNode(arr[p],arr[c],a);
    }
    int num1,num2;
    for(int i=0;i<t;i++){
        scanf("%c",&c1);
        if(c=='D'){
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%d",&num1);
            scanf("%c",&c1);
            delete(num1,root);
        }
        else{
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%c",&c1);
            scanf("%d",&num1);
            scanf("%c",&c1);
            scanf("%d",&num2);
            scanf("%c",&c1);
            swap(num1,num2,root);
        }
    }
    printf("%d",diameter(root));
    return 0;
}
