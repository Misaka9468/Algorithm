#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 250

int dp[MAXN][MAXN];

int arr[MAXN];
int maxn=-1;
int N;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        dp[i][i] = arr[i];
    }

    for(int r=2;r<=N;r++)
        for(int l=r-1;l>=1;l--)
            for(int k=l;k<r;k++){
                if(dp[l][k]==dp[k+1][r]&&dp[l][k]){
                    dp[l][r] = max(dp[l][r],dp[l][k]+1);
                    maxn = max(maxn,dp[l][k]+1);
                }
            }
    printf("%d",maxn);
    return 0;
}
