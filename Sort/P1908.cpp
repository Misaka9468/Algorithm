#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
ll n;
ll cnt;
ll arr[MAXN];

// 前闭后闭 升序

void findReverse(ll start,ll end){
    if(end==start) return;
    if(end-start==1){
        if(arr[start]>arr[end]){
            cnt++;
            ll tmp=arr[end];arr[end]=arr[start];arr[start]=tmp;
        }
        return ;        
    }
    ll mid = start + (end-start)/2;
    findReverse(start,mid);
    findReverse(mid+1,end);
    ll buf[end-start+1];
    memset(buf,0,sizeof(buf));
    ll idx=0,i=start,j=mid+1;
    while(idx<end-start+1){
        if(i>mid){
            buf[idx] = arr[j];
            j++;idx++;
            continue;
        }
        if(j>end){
            buf[idx] = arr[i];
            i++;idx++;
            continue;
        } 
        if(arr[i]>arr[j]){
            cnt+=mid-i+1;
            buf[idx]=arr[j];
            j++;
        }
        else{
            buf[idx]=arr[i];
            i++;
        }
        idx++;
    }
    for(ll i=start,j=0;i<=end;i++,j++){
        arr[i]=buf[j];
    }
}

ll main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    findReverse(1,n);
    prllf("%lld",cnt);
    return 0;
}