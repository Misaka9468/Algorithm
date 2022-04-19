#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll L,R;
ll ans=1;
ll mid;
int main(){
    scanf("%lld%lld",&L,&R);
    if(R%2==0) printf("%lld",R/2);
    else printf("%lld",(R-1)/2); 
    return 0;
}