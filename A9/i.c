#include<stdio.h>
#include<stdlib.h>
 
#define MIN(a, b) ((a)<(b)?(a):(b))
 
int cmp(const void* p, const void* q) { return *((int*) p) - *((int*) q);}
 
int main()
{
    int n, k; scanf("%d %d", &n, &k);
    int A[n]; for(int i=0; i<n; i++) scanf("%d", &A[i]);
 
    qsort(A, n, sizeof(int), cmp);
 
    int minCount = (int) 1e9;
    for(int i=0; i<n; i++) {
        int j=0, end=A[i]+k, count=1;
        while(j<n) {
            int correct = (i+j)>=n?360:0;
            if(A[(i+j)%n]+correct > end) {
                count++;
                end = A[(i+j)%n]+correct+k;
            }
            j++;
        }
        minCount = MIN(minCount, count);
    }
 
    printf("%d", minCount);
}
