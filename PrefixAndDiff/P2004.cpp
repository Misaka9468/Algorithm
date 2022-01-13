#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 1005
#define ll long long
ll arr[MAXN][MAXN];
int C;
int N,M;
ll max_val = -9999999;
int x,y;

int main(){
    // 行  列   C*C
    scanf("%d %d %d",&N,&M,&C);
    // 前缀和
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%lld",&arr[i][j]);
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for(int i=C;i<=N;i++){
        for(int j=C;j<=M;j++){
            ll tmp = arr[i][j] - arr[i-C][j] -arr[i][j-C] + arr[i-C][j-C];
            if(tmp>max_val) {
                max_val = tmp;
                x = i-C+1;
                y = j-C+1;
            }
        }
    }

    printf("%d %d\n",x,y);
    return 0;
}
