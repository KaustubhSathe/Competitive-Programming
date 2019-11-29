#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 1000000000
using namespace std;


int s,n;
pair<int,int> outposts[505];
pair<double,pair<int,int>> edges[505*505];
int parent[505],r[505];
int numComponents;
void init(){
	for(int i =0;i<n;i++){
		parent[i] = i;
		r[i] = 0;
	}
	numComponents = n;
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
			numComponents--;
		}else{
			parent[x] = y;
			if(r[x] == r[y])
				r[y]++;
			numComponents--;
		}
	}
}

int main(){
	fastio;
	int tc;
	cin>>tc;
	while(tc--){
		cin>>s>>n;
		for(int i =0;i<n;i++)
			cin>>outposts[i].first>>outposts[i].second;
		
		int cnt =0;
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				edges[cnt++] = make_pair(hypot((double)outposts[i].first - outposts[j].first,(double)outposts[i].second-outposts[j].second),make_pair(i,j));
			}
		}
		sort(edges,edges+cnt);
		init();

		double ans = -INFINITY;
		for(int i =0;i<cnt && numComponents > s;i++){
			if(findSet(edges[i].second.first) != findSet(edges[i].second.second)){
				ans = max(ans,edges[i].first);
				merge(edges[i].second.first,edges[i].second.second);
			}
		}

		cout<<fixed<<setprecision(2)<<ans<<endl;

	}
}