#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 505
int a[MAXN],b[MAXN];
char buf[MAXN];
int len_a,len_b,len_ans;
int ans[MAXN];

string sa,sb;

void add(){
    int carry = 0;
    int max_len = max(len_a,len_b);
    len_ans = max_len;
    for(int i=0;i<max_len;i++){
        ans[i] = a[i]+b[i]+carry;
        carry = ans[i]/10;
        ans[i] = ans[i]%10;
    }
    if(carry){
        ans[max_len] = 1;
        len_ans++;
    }
    len_ans--;
}

int main(){
    cin>>sa>>sb;
    len_a = sa.size();
    len_b = sb.size();
    for(int i=0;i<len_a;i++)
        a[i] = sa[len_a-i-1]-'0';
    for(int i=0;i<len_b;i++)
        b[i] = sb[len_b-i-1]-'0';
    add();
    for(int i=len_ans;i>=0;i--)
        printf("%d",ans[i]);
    return 0;
}