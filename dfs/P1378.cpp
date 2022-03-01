#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
#define PI 3.1415926535898
int N;
double a,b,c,d;
double x_1,y_1,x_2,y_2;
double x[8],y[8];
bool vis[8];
double len[8];
double max_square=0;
double now_square=0;

double dist(double x_1,double y_1,double x_2,double y_2){
    return 1.0*sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
}

double solve(int idx){
    double xi = x[idx],yi=y[idx];
    double min_r = min(min(x_2-xi,xi-x_1),min(y_2-yi,yi-y_1));
    for(int i=0;i<N;i++){
        if(i!=idx&&vis[i]){
            double d=dist(xi,yi,x[i],y[i]);
            min_r=min(min_r,max(d-len[i],0.0));
        }
    }
    return min_r;
}
void dfs(int idx,double sum){
    if(idx>N){
        max_square=max(max_square,sum);
        return ;
    }
    for(int i=0;i<N;i++){
        if(!vis[i]){
            len[i] = solve(i);
            vis[i] =1;
            dfs(idx+1,sum+PI*len[i]*len[i]);
            vis[i] = 0;
        }
    }
}

int main(){
    scanf("%d",&N);
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    // 强行划分为左下与右上
    x_1 = min(a,c),x_2 = max(a,c);
    y_1 = min(b,d),y_2 = max(b,d);
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    dfs(1,0);
    printf("%d",(int)((y_2-y_1)*(x_2-x_1)-max_square+0.5));
}
