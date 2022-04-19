#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef struct a {
    int x;
    int y;
    bool operator<(const struct a& other) const{
        return y<other.y;
    }
}section;

#define MAXN 150005
int N;
section arr[MAXN];
int pre[MAXN];
int dp[MAXN];
int t0,t1;
int l,r,mid;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&t0,&t1);
        arr[i] = section{t0,t1};
    }
    sort(arr+1,arr+N+1);
    // O(logn) find pre
    for(int i=1;i<=N;i++){
        l = 0,r = i;
        while(l<r){ // l alaways right
            mid = ((l+r)>>1)+1;
            if(arr[mid].y>=arr[i].x) r = mid-1;
            else l = mid;
        }
        pre[i] = l;
    }
    for(int i=1;i<=N;i++){
        dp[i] = max(dp[pre[i]]+arr[i].y-arr[i].x+1,dp[i-1]);
    }
    printf("%d",dp[N]);
    return 0;
}