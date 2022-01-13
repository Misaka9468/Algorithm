#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 100010
int n,arr[MAXN];
int q[MAXN],len[MAXN];
// 分别代表队尾和队列长度
int q_cnt = 1;
// 有效队列数量
int min_cnt = 100010;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    q[0] = arr[0]; // 先放入
    len[0] = 1; 
    bool flag = true;
    for(int i=1;i<n;i++){
        flag = true;
        // 倒序是为了照顾数量最少的队列
        for(int j=q_cnt-1;j>=0;j--){
            if(q[j]+1 == arr[i]){
                q[j] = arr[i];
                len[j]++;
                flag = false;
                break;
            }
        }
        if(flag){
            q[q_cnt] = arr[i];
            len[q_cnt] = 1;
            q_cnt++;
        }
    }
    for(int i=0;i<q_cnt;i++){
        min_cnt = min(min_cnt,len[i]);
    }
    printf("%d",min_cnt);
    return 0;
}
