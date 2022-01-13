#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 10005
int n;
int tmp;
int a,b;
int ans;

priority_queue<int,vector<int>,greater<int>> q;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        q.push(tmp);
    }
    while(!q.empty()){
        if(q.size()==1){
            q.pop();
        }
        else{
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            ans += a+b;
            q.push(a+b);
        }
    }
    printf("%d",ans);
    return 0;
}