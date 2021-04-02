#include<stdio.h>
int preIndex = 0;
int search(int arr[], int startIn,int endIn, int data)
{
    int i = 0;
    for (i = startIn; i < endIn; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return i;
}
void printPost(int arr[], int pre[],int inStrt, int inEnd)
{
    if (inStrt > inEnd)
    {
        return;
    }
    int inIndex = search(arr, inStrt, inEnd,pre[preIndex++]);
 
    printPost(arr, pre, inStrt, inIndex - 1);
 
    printPost(arr, pre, inIndex + 1, inEnd);
    printf("%d ",arr[inIndex]);
}
int main()
{
    int n;
    scanf("%d",&n);
    int pr[n],in[n];
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }
    printPost(in,pr,0,n-1);
    return 0;
}

