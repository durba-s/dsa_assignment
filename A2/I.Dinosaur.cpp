#include<stdio.h> 
int main() {
    
    int arr1[37]={0};
    char arr[20];
    int n,m;
    int idx=0;
    char c1;
    int count=0;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%c",&c1);
    for(int i=0;i<n;i++){
        char c;
        scanf("%c",&c);
        arr[i]=c;
        while(c!='\n'){
            scanf("%c",&c);
        }
    }
    for(int i=0;i<n;i++)  
    {
     	count=1;
    	if(arr[i]!='\0')
    	{
 		  for(int j=i+1;j<n;j++)  
	      { 
	        if(arr[i]==arr[j])
    	    { count++;
                 arr[j]='\0';
	     	}
	      } 
	      arr1[idx]=count;
	      idx++;
    	 }
    }
    
   int fig=0;
    for(int i=0;i<idx;i++){
        if(arr1[i]>m){
            int q=(arr1[i])/m;
            int r=(arr1[i])%m;
           
            fig=fig+((r*(q+1))/2)+(((m-r)*q*(q-1))/2);
            
        }
        
    }
    printf("%d",fig);
    
    
    return 0;
}
