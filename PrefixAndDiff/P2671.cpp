#include<iostream>
#include<algorithm>

#define mod 10007
#define ll long long
#define maxn 100005

using namespace std;

int number[maxn]; // number[i]=j 格子i对应的number为j
int color[maxn]; // color[i]=j  格子i对应的color为j
int n,m; // 格子数与颜色数

ll ans = 0;

// 首先我们考虑颜色,将同颜色分为一个组 对应dim=0
// 再考虑同颜色内的奇偶性，分为2个组 对应dim=1
int ct[maxn][2]; // 记录了每个(color,奇/偶)组的元素个数

// dim=2对应的三个值分别为乘法分配律的后三项  在x固定时的和
// Σnumber_z   Σz   Σz*number_z
ll group[maxn][2][3]; 

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&number[i]);
    for(int i=1;i<=n;i++) scanf("%d",&color[i]);
    // 为了保证在运行中更新，我们采用i向前扫描方式
    for(int i=1;i<=n;i++){
        // 对于第一个x 并没有z对应 与初始化为0相符合
        // z次数 * [x*number_x] 对应第一项
        ans = (ans+ ct[color[i]][i%2] % mod * i%mod * number[i]%mod ) % mod; 
        // [x * Σnumber_z] 对应第二项
        ans = (ans + i%mod * group[color[i]][i%2][0]%mod ) % mod;
        // [number_x * Σz] 对应第三项
        ans = (ans + number[i]%mod * group[color[i]][i%2][1]%mod) % mod;
        // [Σz*number_z] 对应第四项
        ans = (ans + group[color[i]][i%2][2]) % mod;

        ct[color[i]][i%2] = (ct[color[i]][i%2]+1)%mod;  // 更新count
        group[color[i]][i%2][0] = (group[color[i]][i%2][0] + number[i]%mod)%mod;
        group[color[i]][i%2][1] = (group[color[i]][i%2][1] + i%mod)%mod;
        group[color[i]][i%2][2] = (group[color[i]][i%2][2] + (i%mod*number[i]%mod)%mod)%mod;
    }
    printf("%lld",ans);
    return 0;
}
