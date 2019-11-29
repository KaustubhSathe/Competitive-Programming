#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 1000000000
using namespace std;

int n,m,q;
pair<int,pair<int,int>> edges[1000+5];
vector<pair<int,int>> adj[105];
int dist[105];
int parent[105],r[105];
void init(){
	for(int i =1;i<=n;i++){
		parent[i] = i;
		r[i] = 0;
	}
	for(int i = 0;i<105;i++)
		adj[i].clear();
}

int findSet(int u){
	return (parent[u] == u) ? u : parent[u] =findSet(parent[u]);
}

void merge(int u,int v){
	int x = findSet(u);
	int y = findSet(v);
	if(x != y){
		if(r[x] > r[y]){
			parent[y] = x;
		}else{
			parent[x] = y;
			if(r[x] == r[y])
				r[y]++;
		}
	}
}

void dfs(int u,int p,int cost){
	dist[u] = max(dist[u],cost);
	for(auto to : adj[u]){
		if(to.first == p)continue;
		dfs(to.first,u,max(cost,to.second));
	}
}
int main(){
	int tc = 1;
	while(cin>>n>>m>>q &&  !(n==0&&m==0&&q==0)){
		for(int i =0;i<m;i++)
			cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
		
		sort(edges,edges + m);
		init();
		for(int i =0;i<m;i++){
			if(findSet(edges[i].second.first) != findSet(edges[i].second.second)){
				adj[edges[i].second.first].push_back(make_pair(edges[i].second.second,edges[i].first));
				adj[edges[i].second.second].push_back(make_pair(edges[i].second.first,edges[i].first));
				merge(edges[i].second.first,edges[i].second.second);
			}
		}
		if(tc != 1)
			cout<<endl;
		cout<<"Case #"<<tc++<<endl;
		
		while(q--){
			int c1,c2;
			cin>>c1>>c2;
			memset(dist,-1,sizeof(dist));
			dist[c1] = 0;
			dfs(c1,-1,-INF);
			if(dist[c2] != -1)
				cout<<dist[c2]<<endl;
			else
				cout<<"no path"<<endl;
		}


	}
}