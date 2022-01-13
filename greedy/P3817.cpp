#include<iostream>
#include<algorithm>

using namespace std;
#define ll long long
int n,x;
ll now;
ll ans;
ll before=0;

// 贪心: 考虑2个数,改变后面的数更优(还会减少对后面的影响)
int main(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%lld",&now);
        if(now+before>x){
            ans += now+before-x;
            now = x - before;
        }
        before = now;
    }
    printf("%lld",ans);
    return 0;
}