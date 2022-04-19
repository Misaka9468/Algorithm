#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#include<climits>

using namespace std;
int m,n; // size color
int a,b,c;
const int min_cost = INT_MAX-1;
int color[105][105];
int memo[105][105];
bool visited[105][105];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool flag = false;

// status: {  (-1)->no magic     (0)->red      (1)->yellow}
void dfs(int x,int y,int status,int cost){
    memo[x][y] = min(cost,memo[x][y]);
    if(x==m&&y==m){
        flag = true;
        return ;
    }
    for(int i=0;i<4;i++){
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx>=1&&xx<=m&&yy>=1&&yy<=m&&!visited[xx][yy]){
            // If I have just used magic
            if(color[x][y]==-1){
                if(color[xx][yy]==-1) {
                    continue;
                }
                else{
                    if(cost+(color[xx][yy]!=status)<memo[xx][yy]){
                        visited[xx][yy]=1;
                        dfs(xx,yy,-1,cost+(color[xx][yy]!=status));
                        visited[xx][yy]=0;
                    }
                }
            }
            else{
                if(color[xx][yy]==-1){ // Now use magic!
                    if(cost+2<memo[xx][yy]){
                        visited[xx][yy]=1;
                        dfs(xx,yy,color[x][y],cost+2);
                        visited[xx][yy]=0;
                    }
                }
                else{ // do not use magic!
                    if(cost+(color[x][y]!=color[xx][yy])<memo[xx][yy]){
                        visited[xx][yy]=1;
                        dfs(xx,yy,-1,cost+(color[x][y]!=color[xx][yy]));
                        visited[xx][yy]=0;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&m,&n);
    memset(color,-1,sizeof(color));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            memo[i][j]=min_cost;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        color[a][b] = c;
    }
    visited[1][1] = 1;
    dfs(1,1,-1,0);
    if(flag)
        printf("%d",memo[m][m]);
    else printf("-1");
    return 0;
}