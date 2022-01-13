#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[22];
int mines[22];
int max_index;
int max_num = 0;
int N;
int tmp;
vector<vector<int>> path(22);
vector<vector<int>> father(22);

// 我至今仍认为，从1开始走也能得到最优解
// dp[i]表示选择点i时的最大地雷数
// 需要为每个点维护一个father, dp[i] = max(dp[j], j in father[i]) + mines[i]
// 同时为每个点维护一个path
int main(){
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
        scanf("%d ",&mines[i]);
    
    for(int i=1;i<N;i++){
        for(int j=1;j<=N-i;j++){
            scanf("%d",&tmp);
            if(tmp) father[i+j].push_back(i);
        }
    }

    dp[1] = mines[1];
    path[1].push_back(1);

    for(int i=2;i<=N;i++){
        int max_idx = -1;
        int max_dp = -1;
        if(father[i].size()==0){
            dp[i] = mines[i];
            path[i].push_back(i);
        }
        else{
            for(int j=0;j<father[i].size();j++){
                if(dp[father[i][j]]>max_dp){
                    max_dp = dp[father[i][j]];
                    max_idx = father[i][j];
                }
            }
            dp[i] = max_dp + mines[i];
            path[i] = path[max_idx];
            path[i].push_back(i);
        }
    }

    for(int i=1;i<=N;i++){
        if(max_num<dp[i]){
            max_num = dp[i];
            max_index = i;
        }
    }

    for(int i=0;i<path[max_index].size();i++)
        cout<<path[max_index][i]<<" ";
    cout<<endl;
    cout<<max_num<<endl;
    return 0;
}