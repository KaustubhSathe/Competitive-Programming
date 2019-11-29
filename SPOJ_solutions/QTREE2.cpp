#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;

int n,l;
vector<vector<pii>> adj;


int timer;
vector<int> tin,tout,depth,dist;
vector<vector<int>> up;

void dfs(int v,int cost,int p){
	tin[v] = ++timer;
	up[v][0] = p;
	dist[v] = cost;
	for(int i = 1;i<=l;i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}

	for(auto u : adj[v]){
		if(u.first != p){
			depth[u.first] = depth[v] + 1;
			dfs(u.first,cost + u.second,v);
		}
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u,int v){ // checks whether u is ancestor of v
	return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;

	for(int i = l;i>=0;i--){
		if(!is_ancestor(up[u][i],v))
			u = up[u][i];
	}

	return up[u][0];
}

void preprocess(int root){
	tin.resize(n);
	tout.resize(n);
	depth.assign(n,0);
	dist.resize(n);
	timer = 0;
	l = ceil(log2(n+0.0));
	up.assign(n,vector<int>(l+1));
	dfs(root,0,root);
}

void init(){
	for(int i = 0;i<n;i++){
		adj[i].clear();
		up[i].clear();
	}
	tin.clear();
	tout.clear();
	depth.clear();
	dist.clear();
}


int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n;
		adj.resize(n);
		for(int i = 0;i<n-1;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		preprocess(0);
		string s;
		while(cin>>s && s != "DONE"){
			if(s == "DIST"){
				int a,b;
				cin>>a>>b;
				a--;b--;
				int lc = lca(a,b);
				cout<<dist[a] + dist[b] - 2*dist[lc]<<endl;
			}else{
				int a,b,k;
				cin>>a>>b>>k;
				a--;b--;
				int lc = lca(a,b);
				//cout<<lc<<endl;
				if(k <= depth[a] - depth[lc] + 1){
					int kth = a;
					k--;
					for(int i = l;i>=0;i--){
						if(k&(1<<i)){
							kth = up[kth][i];
						}
					}
					cout<<kth+1<<endl;
				}else{
					k = (depth[a] - depth[lc] + 1) +(depth[b] - depth[lc]) - k;
					int kth = b;
					for(int i = l;i>=0;i--){
						if(k&(1<<i)){
							kth = up[kth][i];
						}
					}
					cout<<kth+1<<endl;		
				}
			}
		}
		init();
	}
}