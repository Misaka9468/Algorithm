#include<iostream>
#include<algorithm>

#define MAXN 5005
using namespace std;
int arr[MAXN][MAXN];
int pre[MAXN][MAXN];
int max_num=1;
int max_v = 0;
int n,m,x,y,v;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&v);
        x++;y++;
        max_num = max(max_num,max(x,y));
        arr[x][y] = v;
    }
    for(int i=1;i<=max_num+3;i++){
        for(int j=1;j<=max_num+3;j++){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }

    for(int i=1;i<=max_num+3;i++){
        for(int j=1;j<=max_num+3;j++){
            int bi = max(0,i-m);
            int bj = max(0,j-m);
            max_v = max(arr[i][j]-arr[bi][j]-arr[i][bj]+arr[bi][bj],max_v);
        }
    }
    printf("%d",max_v);
    return 0;
}