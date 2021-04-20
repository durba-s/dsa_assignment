#include<stdio.h>
int main(){
		int n;
		int i=0;
		scanf("%d",&n);
		int arr[500];
		int max,min,sum=0;
		for(int m=0;m<n;m++){
				scanf("%d",&arr[m]);
				if(m%2==0)
					sum+=arr[m]*arr[m];
				else
					sum-=arr[m]*arr[m]*arr[m]; 
		}

		max=sum;
		min=sum;
		sum=0;
		for(int N=1;N<n;N++){
			int temp = arr[n - 1], i;
			for (i = n - 1; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = temp;	

		for(int m=0;m<n;m++){			
			if(m%2==0)
				sum+=arr[m]*arr[m];
			else
				sum-=arr[m]*arr[m]*arr[m];
			
		}
		
		if(sum>max)
			max=sum;
		if(sum<min)
			min=sum;
		sum=0;

		}
	    printf("%d",max-min);
	
	
	
	return 0;
}
/*	while(n--){		
		scanf("%d",&d);
		
		if(i%2==0){
		sum1+=d*d;
		sum2-=d*d*d;
		}
		else{
		sum2+=d*d;
		sum1-=d*d*d;
		}
		i++;}
		int diff=sum1>sum2?sum1-sum2:sum2-sum1;
	    printf("%d %d %d",diff,sum1,sum2);				
	}
*/
