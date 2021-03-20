#include<stdio.h>
#include<stdlib.h>
struct task{
    int index;
    long long int e;
    long long int p;

};
int parent(int i)
{
 
    return (i - 1) / 2;
}
int leftChild(int i)
{
 
    return ((2 * i) + 1);
}
int rightChild(int i)
{
 
    return ((2 * i) + 2);
}
void heapify(struct task *array, int size, int i) {
   if (size >1) {
    
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);
    if (l < size && array[l].p < array[smallest].p)
      smallest = l;
    if (r < size && array[r].p<array[smallest].p)
      smallest = r;
    if(l < size && array[l].p == array[smallest].p ){
        if(array[l].e < array[smallest].e) smallest = l;
        else if(array[l].e==array[smallest].e&&array[l].index<array[smallest].index)
                smallest = l;
    }
    if(r < size && array[r].p == array[smallest].p ){
        if(array[r].e < array[smallest].e) smallest = r;
        else if(array[r].e==array[smallest].e&&array[r].index<array[smallest].index)
                smallest = r;
        
    }
    if (smallest != i) {
        struct task temp=array[i];
        array[i]=array[smallest];
        array[smallest]=temp;
      heapify(array, size, smallest);
    }
  }
}
void buildminheap(struct task* array,int n) {
    int startIdx = (n / 2) - 1; 

    for (int i = startIdx; i >= 0; i--) { 
        heapify(array, n, i); 
    } 
}

int main(){



    int t,k;
    scanf("%d",&t);
    scanf("%d",&k);
    struct task* a=(struct task*)malloc(t*sizeof(struct task));
    for(int ind=0;ind<t;ind++){
        long long int n1;
        scanf("%lld",&n1);
        a[ind].e=n1;
        a[ind].p=n1%k;
        a[ind].index=ind;

    }
    buildminheap(a,t);
    for(int ind=0;ind<t;ind++){
        printf("%d ",a[0].e);
        struct task temp=a[0];
        a[0]=a[t-ind-1];
        a[t-ind-1]=a[0];
        heapify(a,t-ind-1,0);

    }
    return 0;

}
