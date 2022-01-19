#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define MAXN 100005
#define ll long long
int n;
int arr[MAXN];
int diff[MAXN];
ll tot1,tot2;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    diff[1] = arr[1];
    for(int i=2;i<=n;i++){
        diff[i] = arr[i]-arr[i-1];
        if(diff[i]>0) tot1+=diff[i];
        else tot2+=diff[i]; 
    }
    tot2 = abs(tot2);
    printf("%lld\n",max(tot1,tot2));
    printf("%lld",abs(tot1-tot2)+1);
    return 0;        
}