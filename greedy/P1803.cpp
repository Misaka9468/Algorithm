#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100005
int n,a,b;
int last_end,tot_count;
struct line{
    int begin;
    int end;
    bool operator < (const struct line& b) const{
        return end<b.end;
    }
} lines[MAXN];

// Greedy之区间调度
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&lines[i].begin,&lines[i].end);
    }
    sort(lines,lines+n);
    for(int i=0;i<n;i++){
        if(lines[i].begin<last_end)
            continue;
        tot_count++;
        last_end = lines[i].end;
    }
    printf("%d",tot_count);
    return 0;
}