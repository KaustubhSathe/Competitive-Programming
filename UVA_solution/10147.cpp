#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

pair<int,int> town[760];
int n,m;
pair<double,pair<int,int>> edges[750*750];

int parent[760],r[760];
void init(){
	for(int i =1;i<=n;i++){
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
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i = 1;i<=n;i++)
			cin>>town[i].first>>town[i].second;

		int cnt = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				edges[cnt++] = make_pair(hypot((double)town[i].first - town[j].first,(double)town[i].second-town[j].second),make_pair(i,j));
			}
		}
		sort(edges,edges+cnt);
		//cout<<cnt<<endl;
		//cout<<edges[0].first<<" "<<edges[0].second.first<<" "<<edges[0].second.second<<endl;
		init();
		
		cin>>m;
		for(int i = 0;i<m;i++){
			int x,y;
			cin>>x>>y;
			merge(x,y);
			//cout<<findSet(x)<<" "<<findSet(y)<<endl;
		}
		//cout<<findSet(5)<<endl;
		vector<pair<int,int>> newedges;
		for(int i =0;i<cnt;i++){
			if(findSet(edges[i].second.first) != findSet(edges[i].second.second)){
				//cout<<"hello "<<endl;
				newedges.push_back(make_pair(edges[i].second.first,edges[i].second.second));
				merge(edges[i].second.first,edges[i].second.second);
			}
		}
		if(newedges.size() == 0)
			cout<<"No new highways need"<<endl;
		else{
			for(auto itr : newedges)
				cout<<itr.first<<" "<<itr.second<<endl;
		}

		if(tc != 0)
			cout<<endl;
	}
}

