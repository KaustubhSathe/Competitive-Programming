#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<int> adj[1000000+5],centroid[1000000+5];
bool is_centroid[1000000+5];
int sz[1000000+5],nn;
void dfs(int u,int p = -1){
    sz[u] = 1;
    for(auto x : adj[u]){
        if(x == p || is_centroid[x])continue;
        dfs(x,u);
        sz[u] += sz[x];
    }
}
int get_centroid(int u,int p = -1){
    for(auto x : adj[u]){
        if(x == p || is_centroid[x])continue;
        if(sz[x] > nn/2) return get_centroid(x,u);
    }
    return u;
}

int decompose(int u){
    dfs(u);
    nn = sz[u];
    int p = get_centroid(u);
    is_centroid[p] = true;
    for(auto x : adj[p]){
        if(is_centroid[x])continue;
        int q = decompose(x);
        centroid[p].pb(q);
        centroid[q].pb(p);
    }
    return p;
}
int main(){
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root_centroid_tree = decompose(1);


    return 0;
}