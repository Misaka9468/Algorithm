#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int C;
int R;
int i,j;
int tot_maxval = 1;
int dp[102][102];
int nums[102][102];
typedef struct node{
    int i;
    int j;
    int val;
} height;

struct cmp{
    bool operator()(height a,height b){
        return a.val>b.val;
    }
};
priority_queue<height,vector<height>,cmp> q;

int main(){
    scanf("%d %d",&R,&C);
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            scanf("%d",&nums[i][j]);
            dp[i][j] = 1;
            height tmp;
            tmp.i = i;
            tmp.j = j;
            tmp.val = nums[i][j];
            q.push(tmp);
        }
    }

    while(!q.empty()){
        int tmp_max = 0;
        height now = q.top();
        q.pop();
        i = now.i;
        j = now.j;
        if(nums[i][j]>nums[i-1][j])
            tmp_max = max(tmp_max,dp[i-1][j]+1);
        if(nums[i][j]>nums[i+1][j])
            tmp_max = max(tmp_max,dp[i+1][j]+1);
        if(nums[i][j]>nums[i][j-1])
            tmp_max = max(tmp_max,dp[i][j-1]+1);
        if(nums[i][j]>nums[i][j+1])
            tmp_max = max(tmp_max,dp[i][j+1]+1);
        dp[i][j] = max(dp[i][j],tmp_max);
        tot_maxval = max(tot_maxval,dp[i][j]);
    }
    cout<<tot_maxval;
    return 0;
}