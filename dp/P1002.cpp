#include<iostream>
#include<algorithm>

#define MAXN 25
#define ll long long
using namespace std;
ll dp[MAXN][MAXN];
bool flag[MAXN][MAXN];
int d[9][2] = {
    {0,0},{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}
};

int Bx,By,Hx,Hy; // B的xy坐标以及马的坐标
int x,y;

int main(){
    // 为了避免数组各种越界情况,可以用+2的方式
    // 避免跳马的问题
    scanf("%d %d %d %d",&Bx,&By,&Hx,&Hy);
    Bx+=2;By+=2;Hx+=2;Hy+=2;
    for(int i=0;i<9;i++)
        flag[Hx+d[i][0]][Hy+d[i][1]] = true;

    dp[2][1] = 1;

    for(int i=2;i<=Bx;i++){
        for(int j=2;j<=By;j++){
            if(flag[i][j]) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    printf("%lld\n",dp[Bx][By]);
    return 0;
}