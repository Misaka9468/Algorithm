#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int before,now,n;
ll ans;

// 利用数学归纳法,从2个推广到n+1个
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){ 
        scanf("%d",&now);
        if(now>before) ans+=now-before;
        before = now;
    }
    printf("%lld",ans);
    return 0; 
}
