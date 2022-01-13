#include<iostream>
#include<algorithm>

#define MAXNT 100000003
#define MAXNM 100003
#define ll long long
using namespace std;

int T,M;
int w[MAXNM],v[MAXNM]; // weight and value
ll dp[MAXNT];

int main(){
    
    scanf("%d %d",&T,&M);
    for(int i=1;i<=M;i++){
        scanf("%d %d",&w[i],&v[i]);
    }
    // 01背包问题的一维DP回滚
    // 重复选取的01背包问题
    for(int i=1;i<=M;i++){
        for(int j=0;j<=T+2;j++){
            if(w[i]<=j){
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }

    printf("%lld\n",dp[T]);

    return 0;
}
