#include<stdio.h>
int i=0;
int loop(int t){		
		int sum=0,d;
		char c;
		scanf("%c",&c);
		i++;
		while(c!='E'){			
		if(c=='F'){
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%d",&d);
			sum+=d;
			scanf("%c",&c);
		}
		if(c=='L'){
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%d",&d);
			int sum1=loop(d);
			sum=sum+sum1;
		}
		scanf("%c",&c);
		i++;
	}
	scanf("%c",&c);
	scanf("%c",&c);
	scanf("%c",&c);
	sum=(t*sum);
	return sum;
	
}
int main(){
	int noq;
	scanf("%d",&noq);
	int d,pos=0;
	char c,c1;
	scanf("%c",&c);
	while(i<noq){
		scanf("%c",&c);
		i++;
		if(c=='F'){
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%d",&d);
			scanf("%c",&c);
			pos+=d;
		}
		if(c=='L'){
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%c",&c);
			scanf("%d",&d);
			scanf("%c",&c);
			int sum=loop(d);
			pos=pos+sum;
		}
	}
	printf("%d",pos);
	return 0;
}
