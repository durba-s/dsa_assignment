#include<stdio.h>
int main(){	
	unsigned long long int n,i,a,sum,count=0,j=1,multip=1;
	scanf("%llu",&n);
	int flag=0;	
	while(j<n){
		for(i=0;i<j;i++){
			if(count==n){
				flag=1;
				break;
			}
			scanf("%llu",&a);
			sum=sum+multip*a;
			count++;
		}
		if(flag) break;
		j=j*2;
		multip++;
	}


	printf("%llu",sum);
	return 0;
}
