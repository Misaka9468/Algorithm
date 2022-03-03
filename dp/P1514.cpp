#include<bitset>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 505

int height[MAXN][MAXN];
int visited[MAXN][MAXN];
int _left[MAXN][MAXN],_right[MAXN][MAXN];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int N,M,cnt0;

void dfs(int x,int y){
    visited[x][y]=1;
    int xx,yy;
    for(int i=0;i<4;i++){
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if(xx<1||xx>N||yy<1||yy>M) continue;
        if(height[x][y]<=height[xx][yy]) continue;
        if(!visited[xx][yy])
            dfs(xx,yy);
        _left[x][y]=min(_left[x][y],_left[xx][yy]);
        _right[x][y]=max(_right[x][y],_right[xx][yy]);
    }
}


int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            _left[i][j] = 0x3f3f3f3f;
            _right[i][j] = 0;
        }
    }
    for(int i=1;i<=M;i++)
        _left[N][i]=_right[N][i]=i;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&height[i][j]);
    for(int i=1;i<=M;i++){
        if(!visited[1][i])
            dfs(1,i);
    }
    // judge not
    for(int i=1;i<=M;i++){
        if(!visited[N][i]){
            cnt0++;
        }
    } 
    if(cnt0){
        printf("0\n%d",cnt0);
        return 0;
    }
    // judge ok
    int idx0=1,idx1=1;
    while(idx0<=M){
        for(int i=1;i<=M;i++){
            if(_left[N][i]<=idx0){
                idx1 = max(idx1,_right[N][i]);
            }
        }
        cnt0++;
        idx0 = idx1+1;
    }
    printf("1\n%d",cnt0);
    return 0;
}