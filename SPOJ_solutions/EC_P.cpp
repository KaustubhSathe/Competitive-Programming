#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;


int n,m;
vector<int> adj[705];
int tin[705],low[705];
bool visited[705];
int timer;
set<pair<int,int>> cut_edges;


void dfs(int v,int parent = -1){
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for(auto to : adj[v]){
		if(to == parent)continue;
		if(visited[to]){
			low[v] =min(low[v],tin[to]);
		}else{	
			dfs(to,v);
			low[v] = min(low[v],low[to]);
			if(low[to] > tin[v])
				cut_edges.insert(mp(min(v,to),max(v,to)));
		}
	}
}

int main(){
	fastio;
	int tc;
	cin>>tc;

	for(int tt = 1;tt<=tc;tt++){
		memset(tin,-1,sizeof(tin));
		memset(low,-1,sizeof(low));
		memset(visited,false,sizeof(visited));
		timer = 0;
		cut_edges.clear();
		for(int i =0;i<705;i++)
			adj[i].clear();
		cin>>n>>m;
		for(int i =0;i<m;i++){
			int x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for(int i =1;i<=n;i++)
			if(!visited[i])
				dfs(i);


		cout<<"Caso #"<<tt<<endl;
		if(cut_edges.size() == 0){
			cout<<"Sin bloqueos"<<endl;
		}else{
			cout<<cut_edges.size()<<endl;
			for(auto x : cut_edges)
				cout<<min(x.first,x.second)<<" "<<max(x.first,x.second)<<endl;
		}

	}
}
