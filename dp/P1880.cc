#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAXN 210
int dp_min[MAXN][MAXN];
int dp_max[MAXN][MAXN];
int min_num = 0x3f3f3f3f,max_num = -1;
int arr[MAXN];
int sum[MAXN];
int N;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        arr[i+N] = arr[i];
    }
    for(int i=1;i<=2*N;i++){
        sum[i] = sum[i-1] + arr[i];
    }
    for(int r=2;r<=2*N;r++){
        for(int l=r-1;l>=1&&l>=r-N+1;l--){
            dp_min[l][r] = 0x3f3f3f3f;
            for(int k=l;k<r;k++){
                dp_max[l][r] = max(dp_max[l][r],dp_max[l][k]+dp_max[k+1][r]+sum[r]-sum[l-1]);
                dp_min[l][r] = min(dp_min[l][r],dp_min[l][k]+dp_min[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    for(int l=1;l<=N;l++){
        int r = l+N-1;
        min_num = min(min_num,dp_min[l][r]);
        max_num = max(max_num,dp_max[l][r]);
    }
    printf("%d\n%d",min_num,max_num);
    return 0;
}
