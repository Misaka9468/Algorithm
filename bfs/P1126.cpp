#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define MAXN 55

typedef struct status{
    int x;
    int y;
    int t; // time
    int dir; // 0 1 2 3  E S W N
}point;
const int inf = 0x3f3f3f3f;
int N,M;
bool chess[MAXN][MAXN];
int costs[MAXN][MAXN];

void bfs(int start_x,int start_y,int end_x,int end_y,int dir){
    queue<point> q;
    q.push(point{start_x,start_y,0,dir});
    costs[start_x][start_y] = 0;
    int x,y,t,d,cost;
    bool flag;
    while(!q.empty()){
        point pt = q.front();
        q.pop();
        x=pt.x,y=pt.y,t=pt.t,d=pt.dir;
        
        // GO S
        for(int i=1;i<=3;i++){
            flag = true;
            if(x+i<N&&!chess[x+i][y]){
                flag = false;
                if(d==0||d==2) cost = 1+1;
                else if(d==1) cost=1;
                else cost = 2+1;
                if(costs[x+i][y]>t+cost){
                    q.push(point{x+i,y,t+cost,1});
                    costs[x+i][y] = min(costs[x+i][y],t+cost);
                } 
            }
            // If I cannot move 1 steps, then I cannot move more
            if(flag) break;
        }
        // GO N
        for(int i=1;i<=3;i++){
            flag = true;
            if(x-i>=1&&!chess[x-i][y]){
                flag = false;
                if(d==0||d==2) cost = 1+1;
                else if(d==3) cost=1;
                else cost = 2+1;
                if(costs[x-i][y]>t+cost){
                    q.push(point{x-i,y,t+cost,3});
                    costs[x-i][y] = min(costs[x-i][y],t+cost);
                } 
            }
            if(flag) break;
        }

        // GO W
        for(int i=1;i<=3;i++){
            flag = true;
            if(y-i>=1&&!chess[x][y-i]){
                flag = false;
                if(d==1||d==3) cost = 1+1;
                else if(d==2) cost=1;
                else cost = 2+1;
                if(costs[x][y-i]>t+cost){
                    q.push(point{x,y-i,t+cost,2});
                    costs[x][y-i] = min(costs[x][y-i],t+cost);
                } 
            }
            if(flag) break;
        }

        // GO E
        for(int i=1;i<=3;i++){
            flag = true;
            if(y+i<M&&!chess[x][y+i]){
                flag = false;
                if(d==1||d==3) cost = 1+1;
                else if(d==0) cost=1;
                else cost = 2+1;
                if(costs[x][y+i]>t+cost){
                    q.push(point{x,y+i,t+cost,0});
                    costs[x][y+i] = min(costs[x][y+i],t+cost);
                } 
            }
            if(flag) break;
        }

    } // end while
}


int main(){
    int tmp;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            costs[i][j] = inf;
            scanf("%d",&tmp);
            if(tmp)
                chess[i][j]=chess[i-1][j]=chess[i][j-1]=chess[i-1][j-1]=1;
        }
    }
    char ch;
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>ch;
    if(ch=='E') e = 0;
    else if(ch=='S') e = 1;
    else if(ch=='W') e = 2;
    else if(ch=='N') e = 3; 
    bfs(a,b,c,d,e);
    printf("%d",(costs[c][d]==inf)?-1:costs[c][d]);
    return 0;
}