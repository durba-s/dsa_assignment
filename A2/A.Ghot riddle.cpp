#include<stdio.h>
#include<math.h>
int isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int isPerfectSquare(int n)
{
    for (int i = 1; i * i <= n; i++) { 
        if ((n % i == 0) && (n / i == i)) {
            return 1;
        }
    }
    return 0;
}
int f(int n){
	if(isPrime(n)||(isPerfectSquare(n)&&isPrime(sqrt(n))))
		return n;
	else{
		int div1,div2;
		int count=0;
		for(int i=n-1;i>1;i--){
			if(n%i==0){
				if(count==0){
					div1=i;
					count++;
				}
				else if(count==1){
					div2=i;
					count++;
				}
				else if(count==2){
					break;
				}
			}
		}
		return f(div1)+f(div2);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
}
