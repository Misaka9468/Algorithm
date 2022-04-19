#include<iostream>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
#define MAXN 55
string a;
int N;
int dp[MAXN][MAXN];

int main(){
    cin>>a;
    N = a.size();
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            dp[i][j] = 0x3f3f3f3f;
            if(i==j) dp[i][j]=1;
        }
    for(int r=2;r<=N;r++){
        for(int l=r-1;l>=1;l--){
            if(a[l-1]==a[r-1]) dp[l][r] = min(dp[l+1][r],dp[l][r-1]);
            else{
                for(int k=l;k<r;k++){
                    dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
            }
        }
    }
    printf("%d",dp[1][N]);
    return 0;
}