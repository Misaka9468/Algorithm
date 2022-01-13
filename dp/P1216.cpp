#include<iostream>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int r;
int tmp;
int max_val = -1;

// dp思路：每一行的数都由上面两个数的max+本数得到
// 复杂度是O(r^2)
int main(){
    scanf("%d",&r);
    for(int i = 1;i<=r;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&tmp);
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + tmp;
        }
    }
    for(int i=1;i<=r;i++){
        max_val = max(max_val,dp[r][i]);
    }
    cout<<max_val;
    return 0;
}