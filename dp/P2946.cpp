#include<bits/stdc++.h>

using namespace std;
#define MAXN 2005
#define MOD 100000000
int N,F;
int dp[MAXN][1005];
int arr[MAXN];
int tmp;
int main(){
    scanf("%d%d",&N,&F);
    for(int i=1;i<=N;i++) {
	    scanf("%d",&tmp);
        arr[i] = tmp%F;
    }
    dp[0][0] = 1;
    for(int i=1;i<=N;i++)
        for(int j=0;j<=F;j++){
            dp[i][j] = (dp[i-1][j]+dp[i-1][(j+F-arr[i])%F])%MOD;
        }
    printf("%d\n",dp[N][F]);
    return 0;
}
