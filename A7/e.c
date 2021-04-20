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


//m2
#include <stdio.h>
#include <string.h>
#define M 11
int cnt[1 << M];

int main() {
    int i, n, x; char s[10];
    for(scanf("%d", &n); n--; ) {
        scanf(" %s %d", s, &x);
        int mask = 0;
        for(i = 0; i < M; i++, x /= 10)
            mask += (x % 10 & 1) << i;
        if(!strcmp(s, "add")) cnt[mask]++;
        else if(!strcmp(s, "delete")) cnt[mask]--;
        else printf("%d\n", cnt[mask]);
    }
}

//m3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parity_checker(int a, int b);

int main(){
    int N;
    scanf("%d",&N);
    int d[N];
    int q=0;
    int query[N];
    int j=0;
    int c=0;
    int max=0;
    for(int i=0;i<N-1;i++){
        char s[6];
        int t=0;
        scanf("%s %d",s,&t);
        if(s[0]=='a'){
            d[j++]=t;
        }
        else if(s[0]=='d'){
            for(int k=0;k<j;k++){
                if(d[k]==t){
                    d[k]=-1;
                    break;
                }
            }
        } else {
            int h=0;
            for(int k=0;k<j;k++){
                if(d[k]!=-1){
                    h+=parity_checker(d[k],t);
                }
            }
            query[q++]=h;
        }
    }
    for(int i=0;i<q;i++)printf("%d\n",query[i]);
}

int parity_checker(int a, int b){
    for(int i=1;i<=9;i++){
        if((a%10 + b%10) % 2){
            return 0;
        }
        a/=10;
        b/=10;
    }
    return 1;
}
