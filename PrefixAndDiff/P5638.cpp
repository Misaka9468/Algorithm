#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define MAXN 1010010
int n,k;

ll path[MAXN];
ll ans= 9223372036854775800;

// 前缀和维护一下就行
// 太水太水
int main() {
	scanf("%d %d",&n,&k);
	for(int i=2;i<=n;i++) {
        scanf("%lld",&path[i]);
		path[i]+=path[i-1];
	}
	for(int i=1;i<=n;i++){
        int idx = min(i+k,n);
		ans = min(ans,path[n]-(path[idx]-path[i])); 
    }
	printf("%lld",ans);
    return 0;
}
