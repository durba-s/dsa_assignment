#include<stdio.h>
int main(){
	int m,n;
	scanf("%d",&n);
	scanf("%d",&m);
	unsigned long long int pow[n],mult[m];
	for(int i=0;i<n;i++)
		scanf("%llu",&pow[i]);
	for(int i=0;i<m;i++)
		scanf("%llu",&mult[i]);
	pow[n-1]=pow[n-1]*mult[m-1];
	for(int i=0;i<m-1;i++){
		for(int j=0;j<=i;j++){
			pow[i]=pow[i]*mult[j];
		}
	}
	unsigned long long int product=1;
	for(int i=0;i<m;i++)
		product=product*mult[i];
	for(int i=m-1;i<n-1;i++){
		pow[i]=pow[i]*product;
	}
	for(int i=0;i<n;i++){
		printf("%llu ",pow[i]%1000000007);
	}
	return 0;
}
