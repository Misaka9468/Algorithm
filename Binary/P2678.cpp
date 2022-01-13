#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 1000000005
#define ll long long
using namespace std;
ll L,N,M;
ll tmp;
ll arr[50005];

// 0 12 2
// 二分枚举
bool judge(ll step){
    int cnt=0,j=1;
    for(int i=0;i<=N;){
        if(cnt>M) break;
        if(i+j>N+1) break;
        if(arr[i+j]-arr[i]<step){ // 需要减掉arr[i+j]
            cnt++;
            j++;
        }
        else{i+=j;j=1;}
    }
    return cnt<=M;
}

// 25 5 2
// (0) 2 11 14 17 21 (25)
int main(){

    scanf("%lld%lld%lld",&L,&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%lld",&tmp);
        arr[i] = tmp;
    }
    arr[0]=0;arr[N+1]=L;
    ll l=0,r=L,mid;
    // 考虑1 2
    // 左边至少会能完成，所以取mid r来衰退
    while(l<r){
        mid = l + (r-l)/2 + 1; // 偏右一下，不然可能对不齐
        if(judge(mid)){ // right
            l = mid;
        }
        else{ // left
            r = mid-1;
        }
    }
    printf("%lld",r);
    return 0;
}