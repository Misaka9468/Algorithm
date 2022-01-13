#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 1003
int n,m;
int a,b,c,d;
int arr[MAXN][MAXN];

int main(){
    // 从1计数是美德捏
    scanf("%d %d",&n,&m);
    // 差分
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        arr[a][b] += 1;
        arr[a][d+1] -= 1;
        arr[c+1][b] -= 1;
        arr[c+1][d+1] += 1;
    }
    // 前缀和还原
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}