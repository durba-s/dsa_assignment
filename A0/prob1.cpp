#include<stdio.h>
int main(){
	
		char A[1001];
		char B[1001];
		char res[1001];
		char c;
		
		scanf("%s",A);
		scanf("%c",&c);
		scanf("%s",B);
		
		int la,lb;
		for(la=0;A[la]!='\0';la++);
		for(lb=0;B[lb]!='\0';lb++);
	
		int diff=la-lb;
		int j=0,carry=0;
		
		for(int i=lb-1;i>=0;i--){
			int sum=(int)A[i+diff]+(int)B[i]-48-48;
			res[j++]=((sum+carry)%10)+48;
			carry=(sum+carry)/10;
		}
		for(int i=diff-1;i>=0;i--){
			int sum=(int)A[i]-48;
			res[j++]=((sum+carry)%10)+48;
			carry=(sum+carry)/10;
		}
		if(carry>0){
			res[j++]=carry+48;
		}
		
		for(int i=j-1;i>=0;i--){
			printf("%c",res[i]);
		}
	
	
		return 0;
}
