#include<stdio.h>
#include<stdlib.h>
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
void zizagtraversal(struct Node* root,int* arr)
{
    if (!root)
        return;
    struct stackNode* currentlevel=malloc(sizeof(struct stackNode));
    struct stackNode* nextlevel=malloc(sizeof(struct stackNode));
    
    currentlevel->t=root;
    currentlevel->next=NULL;
    int lefttoright =1;
    
    while (currentlevel!=NULL) {
        struct Node* temp = currentlevel->t;
        currentlevel= currentlevel->next;
        if (temp) {
            printf("%d ",arr[temp->val]);
            if (lefttoright==1) {
                if (temp->left){
                    struct stackNode* new=malloc(sizeof(struct stackNode));
                    new->t=temp->left;
                    new->next=nextlevel;
                    nextlevel=new;}
                if (temp->right){
                    struct stackNode* new=malloc(sizeof(struct stackNode));
                    new->t=temp->right;
                    new->next=nextlevel;
                    nextlevel=new;}
            }
            else {
                if (temp->right){
                    struct stackNode* new=malloc(sizeof(struct stackNode));
                    new->t=temp->right;
                    new->next=nextlevel;
                    nextlevel=new;}
                if (temp->left){
                    struct stackNode* new=malloc(sizeof(struct stackNode));
                    new->t=temp->left;
                    new->next=nextlevel;
                    nextlevel=new;}  
            }
        }
 
        if (currentlevel==NULL) {
            lefttoright = !lefttoright;
            struct stackNode* temp=currentlevel;
            currentlevel=nextlevel;
            nextlevel=temp;
        }
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
    zizagtraversal(root,arr);
    return 0;
}

