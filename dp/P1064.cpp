#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define MAXN 32005
#define ll long long
int n,m;
ll dp[65][MAXN];
int v,p,q;
// vi[x][0]->cnt  vi[x][1] -> first_app vi[x][2]->second_app
int vi[65][3],pi[65][3];
int v_m[65],p_m[65];
int cnt=1;
int fk[65]; // input order -> main order

int vwm,vwm1,vwm2;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&v,&p,&q);
        if(q==0) {
            v_m[cnt]=v;
            p_m[cnt]=p;
            fk[i] = cnt;
            cnt++;
        }
        else{
            vi[fk[q]][0]++;pi[fk[q]][0]++;
            vi[fk[q]][vi[fk[q]][0]] = v;
            pi[fk[q]][pi[fk[q]][0]] = p;
        }
    }
    for(int i=1;i<=cnt-1;i++){
        for(int j=1;j<=n;j++){
            vwm = p_m[i]*v_m[i];
            vwm1 = pi[i][1]*vi[i][1];
            vwm2 = pi[i][2]*vi[i][2];
            dp[i][j] = max(dp[i-1][j],dp[i][j]);
            // 1~2. not pick + pick main
            if(j>=v_m[i]) 
                dp[i][j] = max(dp[i][j],vwm+dp[i-1][j-v_m[i]]);
            // 3. pick app1 
            if(j>=v_m[i]+vi[i][1])
                dp[i][j] = max(dp[i][j],vwm+vwm1+dp[i-1][j-v_m[i]-vi[i][1]]);
            // 4. pick app2
            if(j>=v_m[i]+vi[i][2])
                dp[i][j] = max(dp[i][j],vwm+vwm2+dp[i-1][j-v_m[i]-vi[i][2]]);
            // 5. pick app1 and app2
            if(j>=v_m[i]+vi[i][1]+vi[i][2])
                dp[i][j] = max(dp[i][j],vwm+vwm1+vwm2+dp[i-1][j-v_m[i]-vi[i][1]-vi[i][2]]);
        }
    }
    printf("%lld",dp[cnt-1][n]);
    return 0;
}
