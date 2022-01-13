#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
struct p{
    ll a,b;
    bool operator < (const struct p& x)  {
        return a*b<x.a*x.b;
    }
}pe[1005];
int n;
int len_pre=1,len_ans=1,len_tmp=1;
int ans[10005]={0,1},tmp[10005]={0,1},pre[10005]={0,1};

void multi(ll x){
    ll carry=0;
    for(int i=1;i<=len_pre;i++){
        pre[i] *= x;
    }
    for(int i=1;i<=len_pre;i++){
        carry += pre[i];
        pre[i] = carry%10;
        carry /= 10;
    }
    // 对剩余位数的处理
    while(carry>0){
        ++len_pre;
        pre[len_pre] = carry%10;
        carry /= 10;
    }
}


void div(ll x){
    memset(tmp,0,sizeof(tmp));
    len_tmp = len_pre;
    ll carry = 0;
    for(int i=len_tmp;i>=1;i--){
        carry*=10;
        carry+=pre[i];
        if(carry>=x){
            tmp[i] = carry/x;
            carry %= x;
        } 
    }
    // 回退表示数字头部的idx
    while(tmp[len_tmp]==0){
        if(len_tmp==1)
            break;
        len_tmp--;
    }
}

void cmp(){
    // 寻找最大值,长度大的肯定大
    if(len_tmp>len_ans){
        for(int i=1;i<=len_tmp;i++){
            ans[i] = tmp[i];
        }
        len_ans = len_tmp;
    }
    else if(len_tmp==len_ans){
        for(int i=len_tmp;i>=1;i--){
            if(tmp[i]>ans[i]){ // 还是发现大
                for(int j=1;j<=len_tmp;j++){
                    ans[j] = tmp[j];
                }
                len_ans = len_tmp;
                break;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%lld %lld",&(pe[i].a),&(pe[i].b));
    }
    sort(pe+1,pe+n+1);
    for(int i=1;i<=n;i++){
        multi(pe[i-1].a);
        div(pe[i].b);
        cmp();
    }
    for(int i=len_ans;i>=1;i--)
        printf("%d",ans[i]);
    return 0;
}