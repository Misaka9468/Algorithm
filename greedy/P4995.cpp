#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 305
#define ll long long
int n;
int arr[MAXN];
int last_idx;
ll ans;

// 保证每次两次距离之间间隔最大
// 或许可以用贪心的交换论证来证明
// 明天就考试了 题解暂时开摆
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    int i=1,j=n;
    while(i<j){
        if(i==j){
            ans += (arr[j]-arr[last_idx])* (arr[j]-arr[last_idx]);
            j--;i++;
        }
        else{
            ans += (arr[j]-arr[last_idx])* (arr[j]-arr[last_idx]);
            last_idx = j;
            ans += (arr[i]-arr[last_idx])* (arr[i]-arr[last_idx]);
            j--;
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}