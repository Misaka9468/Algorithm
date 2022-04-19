#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define MAXN 30005
int n,m;
int dp[26][MAXN];
int v[26];
int w[26];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&w[i],&v[i]);
        v[i]*=w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>=w[i]) dp[i][j] = max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d",dp[m][n]);
    return 0;
}