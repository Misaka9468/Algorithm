#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
#define MAXN 10100
int a[MAXN],b[MAXN];
char buf[MAXN];
int len_a,len_b,len_ans;
int ans[MAXN];
string sa,sb;

void sub(){
    // 根据swap 我们已经保证了a-b>0
    int carry = 0;
    for(int i=0;i<len_a;i++){
        if(a[i]-b[i]-carry<0){
            a[i]+=10;
            ans[i] = a[i]-b[i]-carry;
            carry = 1;
        }
        else{
            ans[i] = a[i]-b[i]-carry;
            carry = 0;
        }
    }
    len_ans = len_a-1;
    while(ans[len_ans]==0&&len_ans>1) len_ans--;
}


int main(){
    bool flag = false;
    cin>>sa>>sb;
    if((sa.size()<sb.size())||(sa.size()==sb.size()&&sa<sb)){
        swap(sa,sb);
        flag = true;
    }
    len_a = sa.size();
    len_b = sb.size();
    
    for(int i=0;i<len_a;i++)
        a[i] = sa[len_a-i-1]-'0';
    for(int i=0;i<len_b;i++)
        b[i] = sb[len_b-i-1]-'0';    
    sub();
    if(flag) printf("-");
    for(int i=len_ans;i>=0;i--)
        printf("%d",ans[i]);
    return 0;
}