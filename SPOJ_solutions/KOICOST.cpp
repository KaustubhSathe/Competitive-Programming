#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int n,m;
pair<int,pair<int,int>> edges[100000+5];
long long int sum[100000+5];
int parent[100000+5],r[100000+5];
long long int sz[100000+5];
void init(){
	for(int i = 1;i<=n;i++){
		parent[i] = i;
		sz[i] = 1;
		r[i] = 0;
	}
}

int findSet(int u){
	return (parent[u] == u) ? u : parent[u] = findSet(parent[u]);
}

int main(){
	cin>>n>>m;
	for(int i =0;i<m;i++){
		cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
	}
	sort(edges,edges+m);

	init();
	for(int i = 0;i<m;i++)
		if(i == 0){
			sum[i] = edges[i].first;
		}else{
			sum[i] = edges[i].first + sum[i-1];
		}


	
	long long int ans = 0;
	for(int i = m-1;i>=0;i--){
		int x = findSet(edges[i].second.first);
		int y = findSet(edges[i].second.second);
		if(x != y){
			long long int temp = ((sz[x]%MOD)*(sz[y]%MOD))%MOD;
			long long int temp2 = ((temp%MOD)*(sum[i]%MOD))%MOD;
			ans = (ans%MOD + temp2%MOD)%MOD;
			if(r[x] > r[y]){
				parent[y] = x;
				sz[x] += sz[y];
			}else{
				parent[x] = y;
				sz[y] += sz[x];
				if(r[x] == r[y])
					r[y]++;
			}
		}
	}
	cout<<ans<<endl;
}