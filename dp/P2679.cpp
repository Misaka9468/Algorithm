#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
#define MOD 1000000007
char A[1005],B[1005];
int dp[2][201][201][2];
int n,m,k;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    cin>>(A+1);
    cin>>(B+1);
    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int p=1;p<=k&&p<=j;p++){
                if(A[i]==B[j]){
                    // pick B[j]
                    dp[i&1][j][p][1]=(dp[1-(i&1)][j-1][p][1]+dp[1-(i&1)][j-1][p-1][0])%MOD;
                    dp[i&1][j][p][1]=(dp[i&1][j][p][1]+dp[1-(i&1)][j-1][p-1][1])%MOD;
                    // do not pick B[j]
                    dp[i&1][j][p][0] = (dp[1-(i&1)][j][p][0]+dp[1-(i&1)][j][p][1])%MOD;
                }
                else{
                    dp[i&1][j][p][1] = 0;
                    dp[i&1][j][p][0] = (dp[1-(i&1)][j][p][0]+dp[1-(i&1)][j][p][1])%MOD;
                }
            }
        }
    }
    printf("%d",(dp[n&1][m][k][0]+dp[n&1][m][k][1])%MOD);
    return 0;
}