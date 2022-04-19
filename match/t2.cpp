#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll n,a,b,c;
ll ans;

int main(){
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&a,&b,&c);
    ans = 2*n-1;
    if(c<n){
        ans = 2*n-1;
    }
    else {
        ans+= min(b-a+1,2*(c-n+1));
    }
    printf("%lld",ans);
}