#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef struct s{
    int x,y,t;
    bool operator< (const struct s& other) const{
        return t < other.t;
    };
}road;

road roads[100005];

int fa[1005];
int N,M;
int valid_t;

int findfa(int x){
    if(x == fa[x]) return fa[x];
    else return fa[x] = findfa(fa[x]);
}

void merge(int x, int y){
    fa[findfa(x)] = findfa(y);
}

void init(){
    for(int i=0;i<1005;i++)
        fa[i] = i;
}

int main(){
    init();
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++){
        scanf("%d%d%d",&roads[i].x,&roads[i].y,&roads[i].t);
    }
    sort(roads+1,roads+M+1);
    for(int i=1;i<=M;i++){
        int x,y,t;
        x = roads[i].x; y = roads[i].y; t = roads[i].t;
        if(findfa(x)==findfa(y)) continue;
        merge(x,y);
        valid_t = t;
    }
    int tmp = findfa(1);
    for(int i=2;i<=N;i++){
        if(tmp!=findfa(i))
            valid_t = -1;
    }
    printf("%d",valid_t);
    return 0;
}