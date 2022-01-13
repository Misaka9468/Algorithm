#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
#define MAXN 1005
int arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n,m,pij;

bool bfs(int mid){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(!vis[i][j]){
            vis[i][j] = 1;
            if(i==n) return true;
            if(i==0||i==n+1||j==0||j==m+1||arr[i][j]>mid) continue;
            if(arr[i+1][j]<=mid)
                q.push(make_pair(i+1,j)); //下
            if(arr[i-1][j]<=mid)    
                q.push(make_pair(i-1,j)); // 上
            if(arr[i][j-1]<=mid)
                q.push(make_pair(i,j-1)); // 左
            if(arr[i][j+1]<=mid) 
                q.push(make_pair(i,j+1)); //右
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int l=0,r=MAXN,mid=0;
    // 最大值的最小值，至少右是满足的
    while(l<r){
        mid = l + (r-l)/2;
        // 如果大的满足了，那么尝试更小的
        if(bfs(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    printf("%d",r);
    return 0;
}