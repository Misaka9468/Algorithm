#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>


using namespace std;
#define MAXN 360
int N,M;
int cnt[5],tmp;
int score[MAXN];
int dp[41][41][41][41];

int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&score[i]);
    for(int i=1;i<=M;i++){
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    dp[0][0][0][0] = score[1];
    for(int i=0;i<=cnt[1];i++){
        for(int j=0;j<=cnt[2];j++){
            for(int n=0;n<=cnt[3];n++){
                for(int m=0;m<=cnt[4];m++){
                    tmp = i*1+j*2+n*3+m*4;
                    if(i>0) 
                        dp[i][j][n][m] = max(dp[i-1][j][n][m]+score[tmp+1],dp[i][j][n][m]);
                    if(j>0) 
                        dp[i][j][n][m] = max(dp[i][j-1][n][m]+score[tmp+1],dp[i][j][n][m]);
                    if(n>0) 
                        dp[i][j][n][m] = max(dp[i][j][n-1][m]+score[tmp+1],dp[i][j][n][m]);
                    if(m>0) 
                        dp[i][j][n][m] = max(dp[i][j][n][m-1]+score[tmp+1],dp[i][j][n][m]);
                }
            }
        }
    }
    printf("%d",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}