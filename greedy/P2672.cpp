#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 100005
int N;

struct people{
    int S;
    int A;
    bool operator < (const struct people other) {
        return A>other.A;
    }
}arr[MAXN];
int preSum[MAXN];
int before_maxS[MAXN];
int after_maxAS[MAXN];


int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&arr[i].S);
    for(int i=1;i<=N;i++)
        scanf("%d",&arr[i].A);
    sort(arr+1,arr+N+1); // 降序
    // 前缀和
    for(int i=1;i<=N;i++)
        preSum[i]=preSum[i-1]+arr[i].A;    
    // 目标结果是 A和+其中2*max(S)
    
    // 更新最大前
    for(int i=1;i<=N;i++)
        before_maxS[i] = max(before_maxS[i-1],2*arr[i].S);
    // 更新最大后,维护的是区间[i,n]中maxS + A
    for(int i=N;i>=1;i--)
        after_maxAS[i] = max(after_maxAS[i+1],2*arr[i].S+arr[i].A);
    for(int i=1;i<=N;i++){
        printf("%d\n",max(preSum[i]+before_maxS[i],preSum[i-1]+after_maxAS[i]));
    }
    return 0;
}