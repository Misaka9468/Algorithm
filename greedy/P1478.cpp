#include<algorithm>
#include<iostream>

using namespace std;
#define MAXN 5050
int arr[MAXN];
int n,s,a,b;
int max_height;
int cnt;
int ans;
int x,y;

// 我还以为 第一次够不到的时候
// 已经要花费那么多体力了呢
int main(){
    scanf("%d %d",&n,&s);
    scanf("%d %d",&a,&b);
    max_height = a+b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        if(x>max_height) continue;
        else if(x<=b) arr[cnt++] = y;
        else arr[cnt++] = y;
    }
    sort(arr,arr+cnt);
    for(int i=0;i<cnt;i++){
        if(arr[i]<=s){
            ans++;
            s-=arr[i];
        }
        else break;
    }
    printf("%d",ans);
    return 0;
}