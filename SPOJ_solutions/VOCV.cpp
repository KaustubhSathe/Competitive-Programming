#include<bits/stdc++.h>
#define pb push_back
#define MOD 10007
#define mp make_pair
using namespace std;

int n;
vector<int> adj[100000+10+5];
int dp[100000+10+5][2],ways[100000+10+5][2];

void dfs(int x,int parent){
	dp[x][0] = 0;
	dp[x][1] = 1;
	ways[x][0] = ways[x][1] = 1;

	for(auto v : adj[x]){
		if(v == parent)continue;
		dfs(v,x);
		dp[x][0] += dp[v][1];
		ways[x][0] = ((ways[x][0]%MOD)*(ways[v][1]%MOD))%MOD;
		dp[x][1] += min(dp[v][0],dp[v][1]);

		int val = ways[v][0] + ways[v][1];
		if(dp[v][0] < dp[v][1])
			val = ways[v][0];
		else if(dp[v][0] > dp[v][1])
			val = ways[v][1];

		ways[x][1] = ((ways[x][1]%MOD)*(val%MOD))%MOD;
	}
}

int main(){
	int tc;
	cin>>tc;

	while(tc--){
		cin>>n;
		for(int i = 0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		dfs(1,-1);
		if(dp[1][0] < dp[1][1])
			cout<<dp[1][0]<<" "<<ways[1][0]<<endl;
		else if(dp[1][0] > dp[1][1])
			cout<<dp[1][1]<<" "<<ways[1][1]<<endl;
		else
			cout<<dp[1][1]<<" "<<(ways[1][0]%MOD+ways[1][1]%MOD)%MOD<<endl;

		for(int i = 1;i<n+1;i++)
			adj[i].clear();
	}
}