#include<utility>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

int N,M,T;
int R1,C1,R2,C2;
#define MAXN 105
char arr[MAXN][MAXN];
int dp[MAXN][MAXN][16];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};


void dfs(int i,int j,int k){
    if(k==0&&!(i==R2&&j==C2)) return ;
    if(i==R2&&j==C2&&k==0){
        dp[i][j][k]=1;
        return ;
    }
    int x,y;
    for(int idx=0;idx<4;idx++){
        x = i+dir[idx][0];
        y = j+dir[idx][1];
        if(x<1||x>N||y<1||y>M) continue;
        if((abs(R2+C2-x-y)%2)!=((k-1)%2)) continue;
        if(abs(R2+C2-x-y)>k-1) continue;
        if(arr[x][y]=='*') continue;
        if(k==0) break;
        if(dp[x][y][k-1]!=0) 
            dp[i][j][k]+=dp[x][y][k-1];
        else{
            dfs(x,y,k-1);
            dp[i][j][k]+=dp[x][y][k-1];
        }
    }
}

int main(){
    scanf("%d%d%d",&N,&M,&T);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>arr[i][j];
    scanf("%d%d%d%d",&R1,&C1,&R2,&C2);
    memset(dp,0,sizeof(dp));
    dfs(R1,C1,T);
    printf("%d",dp[R1][C1][T]);
    return 0;
}