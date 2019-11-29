#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 1000000000
using namespace std;

int n,m;
pair<int,pair<int,int>> edges[101*101];
int parent[105],r[105];
bool flagged[101*101];

void init(){
	for(int i = 1;i<=n;i++){
		parent[i] = i;
		r[i] = 0;
	}
}

int findSet(int u){
	return (parent[u] == u) ? u : parent[u] = findSet(parent[u]);
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
int main(){
	fastio;
	int tc;
	cin>>tc;
	memset(flagged,false,sizeof(flagged));
	while(tc--){
		cin>>n>>m;
		for(int i =0;i<m;i++){
			cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
		}
		sort(edges,edges + m);
		init();

		int s1 = 0;
		vector<int> mst1;
		for(int i =0;i<m;i++){
			if(findSet(edges[i].second.first) != findSet(edges[i].second.second)){
				s1 += edges[i].first;
				mst1.push_back(i);
				merge(edges[i].second.first,edges[i].second.second);
			}
		}
		
		int s2 = INF;
		for(int i = 0;i<mst1.size();i++){
			flagged[mst1[i]] = true;
			int sum = 0;
			init();
			int cnt = 0;
			for(int j =0;j<m;j++){
				if(findSet(edges[j].second.first) != findSet(edges[j].second.second) && !flagged[j]){
					sum += edges[j].first;
					cnt++;
					merge(edges[j].second.first,edges[j].second.second);
				}
			}
			if(cnt == n-1)
				s2 = min(s2,sum);
			flagged[mst1[i]] = false;
		}

		cout<<s1<<" "<<s2<<endl;

	}
}