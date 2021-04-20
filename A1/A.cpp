#include<stdio.h>
int count=1;
int n;
int pat=0;
int y=1,ind;
void sub(){
	if(count==n+1){
		if(y){
			printf("NO ");
		}
		return;
	}
	char c;
	scanf("%c",&c);
	count++;
	if(pat==0&&c=='b'){
		ind=count-1;
		pat++;
	}
	else if(pat==1||pat==2){
		if(c=='a')
			pat++;
		else
			pat=0;
	}
	else if(pat==3){
		if(c=='b'){
			pat=1;
			
			if(y){
				printf("YES ");
				y=0;
			}
			printf("%d ",ind);
			ind=count-1;			
		}
		else
			pat=0;
	}
	

	sub();
}
int main(){
	
	scanf("%d",&n);		
    char c;
    scanf("%c",&c);
	sub();

	return 0;
}
