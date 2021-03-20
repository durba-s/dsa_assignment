#include <stdio.h>
#include <stdio.h>
#define mod 1000000007
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if(size>1)
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
int main()
{
	#ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m];
    int t;
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        insert(a, t);
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=(mx+a[0])%mod;
        a[0]=a[0]/3;
        heapify(a,m,0);
        
    }
    printf("%d",mx);
    return 0;

}