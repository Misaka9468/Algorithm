#include<utility>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 70
int n,sum=0,max_num=0,min_num=0x3f3f3f3f;
int tot_completed;
int a[MAXN];
int nxt[MAXN];
bool visited[MAXN];

bool cmp(int a,int b){return a>b;}

// dfs1(0,max_num,)  tot_completed = sum / max_num;
bool dfs1(int completed,int lef,int idx){
    if(lef==0){
        completed++;
        if(completed==tot_completed-1) {
            printf("%d",max_num);
            exit(0);
            return true;
        }
        lef = max_num;
        idx = 1;
    }
    // cut2: i = idx
    for(int i=idx+1;i<=n;i++){
        if(visited[i])  continue;
        // cut1 : a[i] > lef
        if(a[i]>lef)    { i = nxt[i]-1;continue;}
        if(lef-a[i]<min_num&&lef!=a[i]) { i = nxt[i]-1;continue;}
        visited[i] = 1;
        bool flag = dfs1(completed,lef-a[i],i);
        if(flag) return true;
        else{
            visited[i] = 0;
            if(lef==a[i]) return false;
            if(lef==max_num) return false;
            i = nxt[i]-1;
        }
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        max_num = max(max_num,a[i]);
        min_num = min(min_num,a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        nxt[i] = upper_bound(a+1,a+n+1,a[i],cmp)-a;
    while(max_num<sum){
        if(sum%max_num){
            max_num++;continue;
        }
        //memset(visited,0,sizeof(visited));
        tot_completed = sum / max_num;
        visited[1]=1;
        if(dfs1(0,max_num-a[1],1))    break;
        else max_num++;
    }
    printf("%d",max_num);
    return 0;
}