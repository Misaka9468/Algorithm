#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;
#define MAXN 35
int arr[MAXN][MAXN];
int mark[MAXN][MAXN];
int n;


void bfs(int posx,int posy){
    queue<pair<int,int>> q;
    q.push(make_pair(posx,posy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x<1||x>n||y<1||y>n) {
            mark[x][y]=1;
            continue;
        }
        mark[x][y] = 1;
        if(!mark[x-1][y]) q.push(make_pair(x-1,y));
        if(!mark[x+1][y]) q.push(make_pair(x+1,y));
        if(!mark[x][y-1]) q.push(make_pair(x,y-1));
        if(!mark[x][y+1]) q.push(make_pair(x,y+1));
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    memcpy(mark,arr,sizeof(arr));
    for(int i=1;i<=n;i++){
        if(!mark[1][i]) bfs(1,i);
        if(!mark[i][1]) bfs(i,1);
        if(!mark[i][n]) bfs(i,n);
        if(!mark[n][i]) bfs(n,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]) printf("1 ");
            else if(mark[i][j]) printf("0 ");
            else printf("2 ");
        }
        printf("\n");
    }
    return 0;
}