#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

// 记忆化搜索
bool isNotHunter[5002] = {0}; // 为false表明为顶级掠食者
vector<vector<int>> food(5002); // food[i][j] 表明 j是i的一个食物
int mod = 80112002;
int dp[5002];
int n,m;
int A,B;

int dfs(int index){
    int num = 0;
    if(!food[index].size()){  // dfs搜索的叶子节点 是消费者捏
        dp[index] = 1;
        return 1;
    }
    for(int i = 0; i < food[index].size(); i++){
        if(dp[food[index][i]]==0)
            num += dfs(food[index][i]);
        else
            num += dp[food[index][i]];
        num %= mod;  
    }
    dp[index] = num;
    return num;
}

int main(){
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&A,&B);
        food[B].push_back(A);
        isNotHunter[A] = true;
    }
    
    for(int i = 1; i<=n; i++){
        if(!isNotHunter[i])
            ans = (ans + dfs(i))%mod;
    }
    printf("%d",ans);
    return 0;
}