#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n,M,T;

int dp[105][205][205];
int m[105],t[105];
int main(){
    scanf("%d%d%d",&n,&M,&T);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m[i],&t[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=M;j++){
            for(int k=1;k<=T;k++){
                if(j>=m[i]&&k>=t[i]){
                    dp[i][j][k] = max(dp[i-1][j-m[i]][k-t[i]]+1,dp[i-1][j][k]);
                }
                else dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    printf("%d\n",dp[n][M][T]);
    return 0;
}