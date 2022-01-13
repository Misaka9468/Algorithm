#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 1000010
#define ll long long

ll N,M;
ll arr[MAXN];
ll mid;

// 如果num满足要求,返回true
bool check(ll num){
    ll cnt = 0;
    for(int i=N-1;i>=0;i--){
        if(arr[i]-num>0){
            cnt += arr[i]-num;
            if(cnt>=M) return true;
        }
    }
    return false;
}

int main(){
    scanf("%lld %lld",&N,&M);
    for(int i=0;i<N;i++)    scanf("%lld",&arr[i]);
    sort(arr,arr+N);
    ll left = 0,right= arr[N-1];
    // 二分我一律坚持左闭右开
    while(left<right){
        // 保证mid向右倾斜
        mid = left + ( right+1 - left)/2;
        if(check(mid))
            left = mid;
        else
            right = mid-1;
    }
    printf("%lld",left);
    return 0;
}
