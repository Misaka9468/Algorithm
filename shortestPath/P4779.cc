#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;
#define ll long long

typedef struct edge{
	int w,to,next;
}Edge;
Edge edges[200005];
int dis[100005],head[100005];
bool vis[100005];
int tot;
int n,m,s;

struct node{
    int dis;
    int idx;
    bool operator < (const struct node& other) const{
        return other.dis < dis;
    }
};

void addEdge(int u,int v,int w){
	tot++;
	edges[tot].to = v;
	edges[tot].w = w;
	edges[tot].next = head[u];
	head[u] = tot;
}

void dijkstra(){
    for(int i=1;i<=n;i++)
        dis[i] = 0x3f3f3f3f;
    priority_queue<node> q;
    struct node tmp;
    tmp.dis = 0; tmp.idx = s;
    q.push(tmp);
    dis[s] = 0;
    while(!q.empty()){
        struct node u = q.top();
        q.pop();
        int x = u.idx;
        int d = u.dis;
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i=head[x];i;i=edges[i].next){
            int v = edges[i].to;
            if(dis[v]>dis[x]+edges[i].w){
                dis[v] = dis[x] + edges[i].w;
                if(!vis[v]){
                    struct node tmp;
                    tmp.dis = dis[v];
                    tmp.idx = v;
                    q.push(tmp);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++){
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		addEdge(t1,t2,t3);
	}
    dijkstra();
    for(int i=1;i<=n;i++){
		if(i==s) printf("0 ");
		else printf("%d ",dis[i]);
	}
	return 0;
}
