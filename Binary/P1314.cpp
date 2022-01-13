#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;
#define ll long long 
#define MAXN 200005
int n,m;
int tmp1,tmp2;
int minL=99999999999999,maxR=-1;
ll s,ans=99999999999999;
int wi[MAXN],vi[MAXN];
ll pre_wi[MAXN],pre_vi[MAXN];
vector<pair<int,int>> vec;

// 才理解，区间的意思是 矿石序号的区间
// 也就是一次取多少矿石
ll judge(int W){
    ll tmp_ans=0;
    memset(pre_wi,0,sizeof(pre_wi));
    memset(pre_vi,0,sizeof(pre_vi));

    for(int i=1;i<=n;i++){
        if(wi[i]>=W){
            pre_wi[i] = pre_wi[i-1]+1;
            pre_vi[i] = pre_vi[i-1]+vi[i];
        }
        else{
            pre_wi[i] = pre_wi[i-1];
            pre_vi[i] = pre_vi[i-1];
        }
    }
    for(int i=0;i<m;i++){
        int li = vec[i].first;
        int ri = vec[i].second;
        tmp_ans += (pre_wi[ri]-pre_wi[li-1])*(pre_vi[ri]-pre_vi[li-1]);
    }
    return tmp_ans;
}

// 二分枚举答案
// 题目的特点是：符合条件的最小值
int main(){
    scanf("%d%d",&n,&m);
    scanf("%lld",&s);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&wi[i],&vi[i]);
        minL = min(minL,wi[i]);
        maxR = max(maxR,wi[i]); 
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&tmp1,&tmp2);
        vec.push_back(make_pair(tmp1,tmp2));
    }
    
    int l=minL-2,r=maxR+2,mid;
    // 每次枚举的结果(mid)，计算出的值judgemid和维护的ans比较
    // W越大，计算出的值越小
    // 如果>s,那么W小了；如果<s，那么W大了
    while(l<r){
        mid = l + (r-l)/2; // 偏左 
        ll tmp_ans = judge(mid)-s;
        if(tmp_ans==0){
            printf("0");
            return 0;
        }
        if(llabs(tmp_ans)<ans){ // 是不需要替换的
            ans = llabs(tmp_ans);
        }
        if(tmp_ans>0) // mid小了
            l = mid+1;
        else // mid大了
            r = mid;
    }
    printf("%lld",ans);
    return 0;
}
