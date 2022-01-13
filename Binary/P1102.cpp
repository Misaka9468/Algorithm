#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
#define MAXN 200010
#define ll long long
map<ll,ll> mp;
ll N,C;
ll num;
ll mem;
ll cnt;

int main(){
    scanf("%lld %lld",&N,&C);
    for(int i=0;i<N;i++){
        mem = -9999999999;
        scanf("%lld",&num);
        if(mp.find(C+num)!=mp.end()){
            cnt+= mp[C+num];
            mem = C+num;
        }
        if(mp.find(num-C)!=mp.end()){
            if(num-C==mem&&C==0);
            else
                cnt+= mp[num-C];
        }
        if(mp.find(num)!=mp.end())
            mp[num]++;
        else mp[num] = 1;
    }
    printf("%lld",cnt);
    return 0;
}

