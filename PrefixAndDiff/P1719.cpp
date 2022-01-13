#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 125
int n;
int arr[MAXN][MAXN];
int result=-999999999;

// 考虑过一维最大字段和吗?
// dp[i] = max(dp[i-1]+num_i,num_i)
// 对于二维矩阵，我们可以对每一行也这么做
// 不过，该行的每个元素向y轴扩展，想象一条线从左到右扫描
// 成为一个矩形
// 我们要遍历矩阵的底,其中遍历矩阵的高
// 想象吧, 一个变异的一维最大字段和
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
            arr[i][j] += arr[i-1][j];
        }
    }

    for(int i=1;i<=n;i++){  // 每一行
        for(int k=1;k<=i;k++){ // 该行每一个元素代表的列数
            int ans=0;
            int dp[MAXN]={0};
            for(int j=1;j<=n;j++){
                ans = arr[i][j] - arr[i-k][j];
                dp[j] = max(dp[j-1]+ans,ans); // 一维DP
                result = max(result,dp[j]);
            }
        }
    }

    printf("%d",result);
    return 0;
}
