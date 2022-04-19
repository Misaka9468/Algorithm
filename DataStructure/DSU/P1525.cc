#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 20005
int N,M;
int fa[2*20005];
typedef struct edge{
    int a,b,c;
    bool operator < (const struct edge& other) const{
        return c>other.c;
    }
} ed;

ed eds[100005];
int maxc = 0;

void init(){
    for(int i=1;i<=2*20005;i++)
        fa[i] = i;
}

int findfa(int x){
    if(x == fa[x]) return x;
    else return fa[x] = findfa(fa[x]);
}

void merge(int x,int y){
    fa[findfa(x)] = findfa(y);
}


int main(){
    init();
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++){
        scanf("%d%d%d",&eds[i].a,&eds[i].b,&eds[i].c);
    }
    sort(eds+1,eds+M+1);
    maxc = 0;
    for(int i=1;i<=M;i++){
        int a,b;
        a = eds[i].a; b = eds[i].b;
        if(findfa(a)==findfa(b)){
            maxc = eds[i].c;
            break;
        }
        merge(a,b+N);
        merge(b,a+N);
    }
    printf("%d",maxc);
    return 0;
}