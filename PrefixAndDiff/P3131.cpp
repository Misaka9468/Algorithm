#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 50005
#define ll long long
ll arr[MAXN];
int memo[8];
int N;
int max_num = 0;

// 
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%lld",&arr[i]);
        arr[i]+=arr[i-1];
        arr[i]%=7;
    }
    memset(memo,-1,sizeof(memo));
    memo[0]=0;
    for(int i=1;i<=N;i++){
        if(memo[arr[i]]!=-1)
            max_num = max(max_num,i-memo[arr[i]]);
        else memo[arr[i]]=i;
    }
    printf("%d",max_num);
    return 0;
}