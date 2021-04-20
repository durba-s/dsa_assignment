#include<stdio.h>
 
int main()
{
    int n, x, pos;
    scanf("%d%d%d", &n, &x, &pos);
 
    long long low = 0, high = n, result = 1,countSmall = 0, countLarge = 0;
    long long MOD = 1e9 + 7;
 
    while(low<high) {
        int mid = (low + high) /2;
 
        if(mid == pos) low = mid + 1;
        else if(mid < pos) {
            ++countSmall;
            low = mid + 1;
        } else {
            ++countLarge;
            high = mid;
        }
    }
 
    int i = x-1, fact = n - countSmall - countLarge - 1;
 
    while(countSmall) {
        result = (result * i) % MOD;
        --i;
        --countSmall;
    }
 
    i = n-x;
 
    while(countLarge) {
        result = (result * i) % MOD;
        --i;
        --countLarge;
    }
 
    while(fact) {
        result = (result * fact) % MOD;
        --fact;
    }
    printf("%lld", result);
    return 0;
}
