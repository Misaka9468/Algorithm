#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define MAXN 1000005

int status[MAXN];
int diff[MAXN];
int diff_copy[MAXN];
int req[MAXN][3];
int n,m;
// 试试O(nlogm)的写法
// 若可以满足返回true
bool judge(int pos){
    memset(diff_copy,0,sizeof(diff_copy));
    for(int i=1;i<=n;i++){
        diff_copy[i] = diff[i];
    }
    for(int i=1;i<=pos;i++){
        int a,b,c;
        a = req[i][0];b=req[i][1];c=req[i][2];
        diff_copy[b]-=a;
        diff_copy[c+1]+=a;
    }
    for(int i=1;i<=n;i++){
        diff_copy[i]+=diff_copy[i-1];
        if(diff_copy[i]<0) return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    // 第i天需求
    for(int i=1;i<=n;i++){
        scanf("%d",&status[i]);
        diff[i]=status[i]-status[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&req[i][0],&req[i][1],&req[i][2]);
    }
    int l=0,r=m,mid;
    if(judge(m)){ // 需求满足
        printf("0");
    }
    else{
        // 找到第一个不满足的，因此靠右的是靠谱的
        while(l<r){
            mid = l + (r-l)/2; // 偏左
            // 为true表示mid时还可以满足
            if(judge(mid))  l = mid+1;
            else  r = mid;
        }
        printf("-1\n%d",r);
    }
    
    return 0;
}