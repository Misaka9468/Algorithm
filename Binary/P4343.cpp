#include<iostream>
#include<algorithm>

#define MAXN 100005
#define ll long long
using namespace std;
int arr[MAXN];
bool flag=false;
int l,k;
ll ans=-1;

ll judge(ll num){
    ll cnt=0;
    ll tmp_sum=0;
    for(int i=1;i<=l;i++){
        if(arr[i]>=0){
            tmp_sum+=arr[i];
            if(tmp_sum>=num){
                cnt++;
                tmp_sum=0;
            }
        }
        else{ //arr[i]<0
            if(tmp_sum+arr[i]>0){
                tmp_sum+=arr[i];
            }
            else tmp_sum=0;
        }
    }
    return cnt;
}


int main(){
    scanf("%d%d",&l,&k);
    for(int i=1;i<=l;i++){
        scanf("%d",&arr[i]);
    }
    ll l=1,r=1e18,mid;
    // 还需要一个标志，用来判断是是否不存在这样一个n
    // 寻找最小值
    while(l<r){
        mid = l + (r-l)/2;
        // mid满足条件返回true 符合条件的永远是右边
        ll tmp_ans = judge(mid);
        if(tmp_ans<=k){
            r = mid;
            if(tmp_ans==k) flag=true;
        }
        else l = mid+1;
    }
    if(!flag){
        printf("-1");
        return 0;
    }
    else 
        printf("%lld ",r);
    // 寻找最大值
    // 左边永远有效
    l=1;r=1e18;
    while(l<r){
        mid = l + (r-l)/2+1;
        ll tmp_ans = judge(mid);
        if(tmp_ans>=k){
            l = mid;
        }
        else r = mid-1;
    }
    printf("%lld",l);
    return 0;
}