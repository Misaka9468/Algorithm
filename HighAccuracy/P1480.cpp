#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 5005
#define ll long long
string sa;
ll b;  
int a[MAXN];
int ans[MAXN];
int len_a,len_ans;

void div(){
    // res有可能超出
    ll res = 0;
    for(int i=0;i<=len_a;i++){
        ans[i] = (res*10+a[i])/b;
        res = (res*10+a[i])%b;
    }
    len_ans = 0;
    while(ans[len_ans]==0) len_ans++;
}

int main(){
    cin>>sa;
    scanf("%d",&b);
    len_a = sa.size();
    for(int i=0;i<len_a;i++)
        a[i] = sa[i]-'0';
    div();
    for(int i=min(len_ans,len_a-1);i<len_a;i++)
        printf("%d",ans[i]);
    return 0;
}