#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 1005
#define ll long long
struct p{
    int x;
    int idx;
    bool operator < (const struct p& a){
        return x<a.x;
    }
}arr[MAXN];

int n,T;
ll ans;
double result;

// 前面的排队时长会对后面产生累加
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i].x);
        arr[i].idx = i;
    }
    sort(arr+1,arr+n+1);

    for(int i=1;i<=n;i++){
        ans += arr[i].x*(n-i);
    }

    result = ans * 1.0 / n;
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i].idx);
    }
    printf("\n%.2lf",result);
    
    return 0;
}