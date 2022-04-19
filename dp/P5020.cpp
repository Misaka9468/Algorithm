#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define MAXN 25005
int a[105];
int dp[1000];
int T;
int n;
int cnt=0;

int main(){
    scanf("%d",&T);
    while(T>0){
        cnt = 0;
        T--;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            if(dp[a[i]]){
                cnt++;
                continue;
            }
            for(int j=a[i];j<=a[n];j++)
                dp[j] = dp[a[i]]|dp[j-a[i]];
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}