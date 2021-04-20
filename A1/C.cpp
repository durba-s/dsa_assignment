#include<stdio.h>
int main(){
	int T;
	int tot=0;
	int i=0;
	int extra=0;
	int arr[500];
	char c,d;
	int n,num;
	scanf("%d",&T);
	scanf("%c",&d);
	while(T--){
		
		scanf("%c",&c);
		scanf("%d",&n);
		scanf("%c",&d);
		if(c=='E'){
			tot=tot+extra+n;
			extra=0;
			if(tot>5000){
				extra=tot-5000;
				tot=5000;
			}			
			
		}
		else if(c=='L'){
			for(int k=0;k<n;k++) scanf("%d",&num);
			scanf("%c",&d);
			tot=tot-n;
			tot=tot+extra;
			extra=0;
			if(tot>5000){
				extra=tot-5000;
				tot=5000;
			}
		}
		arr[i]=tot;
		i++;
	}
	int max=arr[0];
	for(int k=0;k<i;k++){
		if(arr[k]>max)
			max=arr[k];
	}
	printf("%d",max);
	return 0;
}

