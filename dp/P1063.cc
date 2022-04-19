#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
#define MAXN 210
int N;
int maxn = -1;
int head[MAXN],tail[MAXN];
int dp[MAXN][MAXN];

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&head[i]);
        head[i+N] = head[i];
    }
    for(int i=1;i<=2*N;i++)
        tail[i] = head[i+1];

    for(int r=2;r<=2*N;r++){
        for(int l=r-1;l>=1&&l>=r-N+1;l--){
            for(int k=l;k<r;k++){
                dp[l][r] = max(dp[l][r],dp[l][k]+dp[k+1][r]+head[l]*tail[k]*tail[r]);
            }
        }
    }
    for(int i=1;i<=N;i++)
        maxn = max(maxn,dp[i][i+N-1]);
    printf("%d",maxn);
    return 0;
}