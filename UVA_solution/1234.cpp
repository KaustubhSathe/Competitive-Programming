#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pii pair<int,int>
using namespace std;


int n,m;
int p[10000+5],r[10000+5];
pair<int,pii> edges[100000+5];

void init(){
	for(int i =1;i<=n;i++){
		p[i] = i;
		r[i] = 0;
	}
}

int findSet(int u){
	return (p[u] == u) ? u : p[u] = findSet(p[u]);
}

void merge(int u,int v){
	int x = findSet(u);
	int y = findSet(v);
	if(x != y){
		if(r[x] > r[y]){
			p[y] = x;
		}else{
			p[x] = y;
			if(r[x] == r[y])
				r[y]++;
		}
	}
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i =0;i<m;i++)
			cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
		
		sort(edges,edges+m);
		reverse(edges,edges+m);
		init();
		int cost = 0;
		int edge_cnt = 0;
		for(int i =0;i<m && edge_cnt <=n-1;i++){
			if(findSet(edges[i].second.first) != findSet(edges[i].second.second)){
				merge(edges[i].second.first,edges[i].second.second);
			}else{
				cost += edges[i].first;
			}
		}

		cout<<cost<<endl;
	}
	cin>>tc;
}

