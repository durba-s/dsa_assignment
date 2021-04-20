#include<stdio.h>
int main(){
	int a,p,c;
	scanf("%d",&a);
	scanf("%d",&p);
	scanf("%d",&c);
	int noa[a],auth[p],h_index[a];
	int indeg[p]={0};
	for(int i=0;i<p;i++){
		scanf("%d",&auth[i]);
	}
	for(int i=0;i<c;i++){
		int v1,v2;
		scanf("%d",&v1);
		scanf("%d",&v2);
		indeg[v2]++;
	}
	int cou,f;
	for(int i=0;i<a;i++){
		cou=0;
		f=0;
		for (int j = 0; j< p; ++j)
		{
			if(auth[j]==i){
				
				if(indeg[j]<cou+1){
					f=1;
					break;

				}
				cou++;

			}

		}
		
		h_index[i]=cou;
	}
	for(int i=0;i<a;i++){
		printf("%d ",h_index[i]);
	}
}
