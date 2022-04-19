#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define MAXN 1005
int m,n;
int ta,tb,tc;
int maxc;
int cnt[1005];
int w[MAXN][MAXN];
int v[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&ta,&tb,&tc);
        cnt[tc]++;
        maxc = max(tc,maxc);
        w[tc][cnt[tc]] = ta;
        v[tc][cnt[tc]] = tb;
    }
    for(int i=1;i<=maxc;i++){  // every group
        for(int j=1;j<=m;j++){ // every weight  
            for(int k=1;k<=cnt[i];k++){ // every sth in group i
                if(j>=w[i][k]) 
                    dp[i][j] = max(dp[i][j],dp[i-1][j-w[i][k]]+v[i][k]);
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
    }
    printf("%d\n",dp[maxc][m]);
    return 0;
}