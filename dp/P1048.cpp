#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 1003
using namespace std;
int T,M;
int t[MAXN],value[MAXN];
int dp[103][MAXN];

// 记忆化搜索
// 还有dp版本的 写在博客里吧 算是给01背包问题一个专题
int memoSearch(int index,int time_left){
    if(index>M) return 0;
    if(dp[index][time_left]!=-1) return dp[index][time_left];

    if(t[index]<=time_left){
        dp[index][time_left] = max(value[index]+memoSearch(index+1,time_left-t[index]),memoSearch(index+1,time_left));
        return dp[index][time_left];
    }
    if(t[index]>time_left){
        dp[index][time_left] = memoSearch(index+1,time_left);
        return dp[index][time_left];
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&T,&M);
    for(int i=1;i<=M;i++)
        scanf("%d %d",&t[i],&value[i]);
    int ans = memoSearch(1,T);
    printf("%d",ans);
    return 0;
}
