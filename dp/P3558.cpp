#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define MAXN 1000005
int n;
int a;
int dp[2][3];
int main(){
    scanf("%d",&n);
    scanf("%d",&a);
    dp[1][0] = dp[1][1] = dp[1][2] = 0x3f3f3f3f;
    dp[1][a+1] = 0; 
    for(int i=2;i<=n;i++){
        scanf("%d",&a);
        if(a==-1){
            dp[i&1][0] = dp[1-(i&1)][0];
            dp[i&1][1] = 0x3f3f3f3f;
            dp[i&1][2] = dp[1-(i&1)][2]+2;
        }
        else if(a==0){
            dp[i&1][0] = dp[1-(i&1)][0]+1;
            dp[i&1][1] = min(dp[1-(i&1)][1],dp[1-(i&1)][0]);
            dp[i&1][2] = dp[1-(i&1)][2]+1;
        }
        else{
            dp[i&1][0] = dp[1-(i&1)][0]+2;
            dp[i&1][1] = dp[1-(i&1)][0]+1;
            dp[i&1][2] = min(min(dp[1-(i&1)][0],dp[1-(i&1)][1]),dp[1-(i&1)][2]);
        }
    }
    int m = min(min(dp[n&1][0],dp[n&1][1]),dp[n&1][2]);
    if(m>=0x3f3f3f3f) printf("BRAK\n");
    else printf("%d",m);
    return 0;
}