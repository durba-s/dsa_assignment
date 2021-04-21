#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main () {
   int values[] = { 88, 56, 100, 2, 25 };
   qsort(values, 5, sizeof(int), cmpfunc);
   for(int n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
   return(0);
}
