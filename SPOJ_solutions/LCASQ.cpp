#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define INF 1000000000
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)



int n,l;
vector<vector<int>> adj;
int timer;
vector<int> tin,tout;
vector<vector<int>> up;

void dfs(int v,int p){
	tin[v] = ++timer;
	up[v][0] = p;
	for(int i = 1;i<=l;i++)
		up[v][i] = up[up[v][i-1]][i-1];

	for(auto u : adj[v]){
		if(u != p){
			dfs(u,v);
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
	timer = 0;
	l = ceil(log2(n+0.0));
	up.assign(n,vector<int>(l+1));
	dfs(root,root);
}



int main(){
    fastio;
    cin>>n;
    adj.resize(n+5);
    for(int i = 0;i<n;i++){
    	int m;
    	cin>>m;
    	for(int j = 0;j<m;j++){
    		int x;
    		cin>>x;
    		adj[i].pb(x);
    	}
    }
    preprocess(0);
    int q;
    cin>>q;
    while(q--){
    	int a,b;
    	cin>>a>>b;
    	cout<<lca(a,b)<<endl;
    }   

    return 0;
}
