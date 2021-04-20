#include <stdio.h>
int longest_common_subsequence(int m,int n,char arr1[],char arr2[]){
    int len[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i*j==0){
                len[i][j]=0;
            }
            else if(arr1[i-1]==arr2[j-1]){
                len[i][j] = len[i-1][j-1] + 1;
            }
            else{
                if(len[i-1][j]>=len[i][j-1]){
                    len[i][j]=len[i-1][j];
                }
                else{
                    len[i][j]=len[i][j-1];
                }
            }
        }
    }
    return len[m][n];
}
int main()
{
    int m,n;
    char c;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%c",&c);
    char arr1[m],arr2[n];
    for(int i=0;i<m;i++){
        scanf("%c",&arr1[i]);
    }
    scanf("%c",&c);
    for(int i=0;i<n;i++){
        scanf("%c",&arr2[i]);
    }
    scanf("%c",&c);
    int num=longest_common_subsequence(m,n,arr1,arr2);
    printf("%d",num);
    return 0;
}
