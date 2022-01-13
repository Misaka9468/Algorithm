#include<iostream>
#include<algorithm>

#define MAXN 1005
#define ll long long
using namespace std;
int n,x; // 对手以及药物数量
int lose[MAXN];
int win[MAXN];
int use[MAXN];
ll dp[MAXN][MAXN];

int main(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&lose[i],&win[i],&use[i]);

    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            if(use[i]>j) // 直接开摆
                dp[i][j] = dp[i-1][j] + lose[i];
            else{
                // 选 or 不选
                dp[i][j] = max(dp[i-1][j-use[i]]+win[i],dp[i-1][j]+lose[i]);
            }
        }
    }

    printf("%lld\n",5*dp[n][x]);
    return 0;

}