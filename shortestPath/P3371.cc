#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>

using namespace std;
#define ll long long
#define MAXN 10005
typedef struct edge{
	int w,to,next;
}Edge;
int n,m,s;
int dis[MAXN],head[MAXN];
bool vis[MAXN];
int tot=0;
Edge edges[500005];

void addEdge(int u,int v,int w){
	tot++;
	edges[tot].to = v;
	edges[tot].w = w;
	edges[tot].next = head[u];
	head[u] = tot;
}


void spfa(){
	queue<int> q;
	  for(int i=1; i<=n; i++) {
    	dis[i]=2147483647; 
    	vis[i]=0;
  	}
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u];i;i=edges[i].next){
			int v = edges[i].to;
			if(dis[v]> dis[u] + edges[i].w){
				dis[v] = dis[u] + edges[i].w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

// SPFA
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++){
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		addEdge(t1,t2,t3);
	}
	spfa();
	for(int i=1;i<=n;i++){
		if(i==s) printf("0 ");
		else printf("%d ",dis[i]);
	}
	return 0;
}
