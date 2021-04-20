#include<stdio.h>
int range(int arr[], int n, int k) 
{ 
    int l = 0, r = n; 
    for (int i=0;i<n;i++) { 
        int s[n]={0};
		int q=0; 
        int j; 
        for (j =i;j<n;j++) { 
            s[q]=arr[j];
			q++; 
            if (q == k) { 
                if ((j - i) < (r - l)) { 
                    r = j; 
                    l = i; 
                } 
                break; 
            } 
        } 
        if (j == n) 
            break; 
    } 
 
    if (l == 0 && r == n) 
        return n; 
    else
        return r-l+1; 
}
int countDistinct(int arr[], int n) 
{ 
    int res = 1; 
    for (int i = 1; i < n; i++) { 
        int j = 0; 
        for (j = 0; j < i; j++) 
            if (arr[i] == arr[j]) 
                break; 
        if (i == j) 
            res++; 
    } 
    return res; 
} 
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	char c;
	scanf("%c",&c);
	for(int i=0;i<n;i++){
		scanf("%c",&c);
		arr[i]=c-'A';
	}
	scanf("%c",&c);
	int cou=countDistinct(arr,n); 
	//printf("%d",cou);
	int min=range(arr,n,cou);
	printf("%d",min);
	return 0;
}
