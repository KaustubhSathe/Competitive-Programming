#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

using namespace std;

int n,m;
vector<int> adj[10000+5];
bool visited[10000+5];
int tin[10000+5],fup[10000+5];
int timer;
set<int> cutpoints;



void dfs(int v,int parent = -1){
	visited[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;

	for(auto to : adj[v]){
		if(to == parent)continue;
		if(visited[to]){
			fup[v] = min(fup[v],tin[to]);
		}else{
			dfs(to,v);
			fup[v] = min(fup[v],fup[to]);
			if(fup[to] >= tin[v] && parent != -1)
				cutpoints.insert(v);

			children++;
		}
	}

	if(parent == -1 && children>1)
		cutpoints.insert(v);
}
int main(){
	fastio;
	while(cin>>n>>m && !(n==0 && m==0)){
		for(int i =0;i<10000+5;i++)
			adj[i].clear();
		memset(visited,false,sizeof(visited));
		memset(tin,-1,sizeof(tin));
		memset(fup,-1,sizeof(fup));
		timer = 0;
		cutpoints.clear();

		for(int i =0;i<m;i++){
			int u,v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		for(int i = 1;i<=n;i++)
			if(!visited[i])
				dfs(i);

		cout<<cutpoints.size()<<endl;
	}


}