#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 8000
int a[MAXN],b[MAXN];
char buf[MAXN];
int len_a,len_b,len_ans;
int ans[MAXN];

string sa,sb;

void multi(){
    for(int i=0;i<len_a;i++){
        for(int j=0;j<len_b;j++){
            ans[i+j] += a[i]*b[j]; // key
        }
    }
    int len = len_a+len_b+10;
    int carry = 0;
    for(int i=0;i<len;i++){
        ans[i] += carry;
        carry = ans[i]/10;
        ans[i] = ans[i]%10;
    }
    while(ans[len]==0) len--;
    if(len==-1) len=0;
    else len_ans = len+1;
}

int main(){
    cin>>sa>>sb;
    len_a = sa.size();
    len_b = sb.size();
    for(int i=0;i<len_a;i++)
        a[i] = sa[len_a-i-1]-'0';
    for(int i=0;i<len_b;i++)
        b[i] = sb[len_b-i-1]-'0';
    multi();
    for(int i=len_ans-1;i>=0;i--)
        printf("%d",ans[i]);
    return 0;
}