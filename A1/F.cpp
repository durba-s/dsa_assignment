#include<stdio.h>
long long int dig[10]={0};
void arr(long long int n){
	while(n!=0){
		dig[n%10]++;
		n/=10;		
	}
}
int prime(long long int n){
	for(long long int i=2;i*i<=n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
void maxdig(long long int lower,long long int upper){
	for(long long int i=lower;i<=upper;i++){
		if(prime(i)){
			arr(i);
		}
	}
}

int main(){	
	long long int lower,upper;
	scanf("%lld",&lower);
	scanf("%lld",&upper);
	maxdig(lower,upper);
	long long int max=dig[0];
	int k=0;
	for(int i=1;i<9;i++){
		if(dig[i]>max){
			max=dig[i];
			k=i;
		}
	}
	printf("%d %lld",k,max);		
	return 0;
}
