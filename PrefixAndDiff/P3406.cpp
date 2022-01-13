#include<iostream>
#include<algorithm>
#define MAXN 100004
#define ll long long 
using namespace std;

int N,M;  // 总城市数、要访问的城市数
int max_idx=0,min_idx = 0;
int Pi[MAXN];
ll cnt[MAXN];
ll Ai,Bi,Ci;
ll ans=0;

int main(){
    scanf("%d %d",&N,&M);
    // 用差分处理访问城市的Pi
    // 因为访问城市实际上就是对某个区间进行+1
    for(int i=1;i<=M;i++)   scanf("%d",&Pi[i]);
    
    for(int i=1;i<M;i++){
        max_idx = max(Pi[i+1],Pi[i]);
        min_idx = min(Pi[i+1],Pi[i]);
        cnt[max_idx]--;
        cnt[min_idx]++;
    }
    for(int i=1;i<=N+2;i++)   cnt[i] += cnt[i-1];

    // 利用cnt来判断
    for(int i=1;i<=N-1;i++){
        scanf("%d %d %d",&Ai,&Bi,&Ci);
        ans += min(Ai*cnt[i],Bi*cnt[i]+Ci);
    }

    printf("%lld",ans);
    return 0;

}