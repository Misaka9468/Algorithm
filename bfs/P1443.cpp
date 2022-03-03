#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;
#define MAXN 403
int n,m,x,y;

int steps[MAXN][MAXN];


void bfs(int posx,int posy){
    int k=1;
    queue<pair<int,int>> q;
    q.push(make_pair(posx,posy));
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            steps[i][j]=k;
            if(i+1<=n&&j+2<=m&&!steps[i+1][j+2]) 
                q.push(make_pair(i+1,j+2)),steps[i+1][j+2]=k+1;
            if(i+2<=n&&j+1<=m&&!steps[i+2][j+1]) 
                q.push(make_pair(i+2,j+1)),steps[i+2][j+1]=k+1;
            if(i+2<=n&&j-1>=1&&!steps[i+2][j-1]) 
                q.push(make_pair(i+2,j-1)),steps[i+2][j-1]=k+1;
            if(i+1<=n&&j-2>=1&&!steps[i+1][j-2]) 
                q.push(make_pair(i+1,j-2)),steps[i+1][j-2]=k+1;
            if(i-1>=1&&j-2>=1&&!steps[i-1][j-2]) 
                q.push(make_pair(i-1,j-2)),steps[i-1][j-2]=k+1;
            if(i-2>=1&&j-1>=1&&!steps[i-2][j-1]) 
                q.push(make_pair(i-2,j-1)),steps[i-2][j-1]=k+1;
            if(i-2>=1&&j+1<=m&&!steps[i-2][j+1]) 
                q.push(make_pair(i-2,j+1)),steps[i-2][j+1]=k+1;
            if(i-1>=1&&j+2<=m&&!steps[i-1][j+2]) 
                q.push(make_pair(i-1,j+2)),steps[i-1][j+2]=k+1;
        }
        k++;
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",steps[i][j]-1);
        }
        printf("\n");
    }
    return 0;
}

