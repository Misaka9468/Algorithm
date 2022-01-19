#include<iostream>
#include<algorithm>

using namespace std;
int n,m;
int arr[105][105];
int dp[105][105];
int max_num = 0;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]){
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                max_num = max(max_num,dp[i][j]);
            }
        }
    }
    printf("%d",max_num);
    return 0;
}