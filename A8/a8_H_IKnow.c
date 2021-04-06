#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
struct DataItem {
   int data;   
   int key;
};
struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;
int hashCode(int key) {
   return key % SIZE;
}
struct DataItem *search(int key) {
    int hashIndex = hashCode(key); 
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
      ++hashIndex;
      hashIndex %= SIZE;
   }
   return NULL;        
}
void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;
   int hashIndex = hashCode(key);
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      ++hashIndex;
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}
struct DataItem* delete(struct DataItem* item) {
   int key = item->key;
   int hashIndex = hashCode(key);
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
      ++hashIndex;
      hashIndex %= SIZE;
   } 
   return NULL;        
}
int main()
{
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 
   int n;
   scanf("%d",&n);
   int A[n],ps[n];
   for(int i=0;i<n;i++){
       scanf("%d",&A[i]);
   }
   int sum = 0;
   int maxLen = 0;
    for(int i = 0;i< n;i++)
    {
        sum = sum + A[i];
        if (sum == 0)
        {
            if (maxLen < i)
            {
                maxLen = i+1;
            }
        }
        else if(search(sum)!=NULL)
        {
            item=search(sum);
            if(maxLen < i-(item->data))
            {
                maxLen = i-(item->data);
            }
        }
        else
            insert(sum,i);
    }
    printf("%d",maxLen);

    return 0;
}
