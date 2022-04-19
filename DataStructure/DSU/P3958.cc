#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>


using namespace std;
#define MAXN 1005
#define ll long long
int fa[MAXN];
int u[MAXN],d[MAXN],ulen=1,dlen=1;

typedef struct point{
    ll x, y, z;
}pt;

pt pts[MAXN];
int T;
int n,h;
ll r;


int findfa(int x){
    if(x == fa[x]) return fa[x];
    else return fa[x] = findfa(fa[x]);
}

void merge(int x, int y){
    fa[findfa(x)] = findfa(y);
}

void init(){
    for(int i=0;i<MAXN;i++)
        fa[i] = i;
    memset(pts,0,sizeof(pts));
    ulen = dlen = 1;
    memset(u,0,sizeof(u));
    memset(d,0,sizeof(d));
}

bool judge(pt a, pt b){
    ll ans = (a.x-b.x)*(a.x-b.x) + 
                 (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    return ans<=4*r*r;
}


int main(){
    scanf("%d",&T);
    while(T){
        T--;
        init();
        scanf("%d%d%lld",&n,&h,&r);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&pts[i].x,&pts[i].y,&pts[i].z);
            if(pts[i].z + r >= h){
                u[ulen] = i;
                ulen++;
            } 
            if(pts[i].z - r <= 0){
                d[dlen] = i;
                dlen++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(findfa(i)==findfa(j)) continue;
                if(judge(pts[i],pts[j])){
                    merge(i,j);
                }
            }
        }
        // judge
        int flag = 0;
        for(int i=1;i<ulen;i++){
            for(int j=1;j<dlen;j++){
                if(findfa(u[i])==findfa(d[j])){
                    flag = 1;
                    i = ulen + 1;
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}