#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define MAXN 200004
int n;
ll num[MAXN];
ll max_num = 0;
ll min_num = 0;
ll ans = -999999999999;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        num[i] += num[i-1];
        ans = max(ans,num[i] - min_num);
        min_num = min(min_num,num[i]);
    }
    printf("%lld",ans);
    return 0;
}