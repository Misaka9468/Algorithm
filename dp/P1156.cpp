#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int D,G;
int dp[105][105]; 
#define INF 0x3f3f3f3f
struct a{
    int t,f,h;

    bool operator <(struct a& other) const{
        return t<other.t;
    }
}arr[105];

int num = -0x3f3f3f3f;

int main(){
    scanf("%d%d",&D,&G);
    for(int i=1;i<=G;i++){
        scanf("%d%d%d",&arr[i].t,&arr[i].f,&arr[i].h);
    }
    sort(arr+1,arr+G+1);
    memset(dp,-3,sizeof(dp));
    dp[0][0] = 10;
    // 2 dim-> height   val -> life
    for(int i=1;i<=G;i++){
        for(int j=0;j<=D;j++){
            if(j-arr[i].h>=0&&dp[i-1][j-arr[i].h]-(arr[i].t-arr[i-1].t)>=0) // use
                dp[i][j] = max(dp[i][j],dp[i-1][j-arr[i].h]-(arr[i].t-arr[i-1].t));
            if(dp[i-1][j]-(arr[i].t-arr[i-1].t)>=0)  // eat
                dp[i][j] = max(dp[i][j],dp[i-1][j]- (arr[i].t-arr[i-1].t) + arr[i].f) ;
        }
        if(dp[i][D]>=0){
            printf("%d\n",arr[i].t);
            return 0;
        }
        num = max(num,dp[i][0] + arr[i].t);
    }
    printf("%d\n",num);
    return 0;
}