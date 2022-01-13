#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 2000010
#define ll long long
struct point{
    int a,b;
    bool operator < (const struct point& x){
        return a<x.a;
    }
}p[MAXN];
ll tot_cost;
int n,m;
int left;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d",&p[i].a,&p[i].b);
    sort(p,p+m);
    for(int i=0;i<m;i++){
        if(n>p[i].b){
            n -= p[i].b;
            tot_cost += p[i].a * p[i].b;
        }
        else{  // n<=p[i].b
            tot_cost += p[i].a * n;
            break;
        }
    }
    printf("%lld",tot_cost);
    return 0;
}
