#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;

int n,m;
map<string,int> city;
map<int,string> names;
vector<int> adj[105];
bool visited[105];
int tin[105],fup[105];
set<string> cutpoints;
int timer;
void dfs(int v,int parent = -1){
	visited[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for(auto to : adj[v]){
		if(to == parent)
			continue;
		if(visited[to]){
			fup[v] = min(fup[v],tin[to]);
		}else{
			dfs(to,v);
			fup[v] = min(fup[v],fup[to]);
			if(fup[to] >= tin[v] && parent != -1)
				cutpoints.insert(names[v]);
			children++;
		}
	}

	if(parent == -1 && children > 1)
		cutpoints.insert(names[v]);
}
int main(){
	int tc = 1;
	while(cin>>n && n != 0){
		if(tc != 1)
			cout<<endl;
		for(int i =0;i<105;i++)
			adj[i].clear();
		memset(visited,false,sizeof(visited));
		memset(tin,-1,sizeof(tin));
		memset(fup,-1,sizeof(fup));
		cutpoints.clear();
		city.clear();
		names.clear();
		for(int i =0;i<n;i++){
			string s;
			cin>>s;
			city[s] = i;
			names[i] = s;
		}
		cin>>m;
		for(int i =0;i<m;i++){
			string s1,s2;
			cin>>s1>>s2;
			adj[city[s1]].pb(city[s2]);
			adj[city[s2]].pb(city[s1]);
		}
		timer = 0;
		for(int i =0;i<n;i++)
			if(!visited[i])
				dfs(i);


		cout<<"City map #"<<tc++<<": "<<cutpoints.size()<<" camera(s) found"<<endl;
		for(auto x : cutpoints)
			cout<<x<<endl;



	}
}
