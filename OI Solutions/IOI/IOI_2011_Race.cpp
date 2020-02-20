#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int maxn = 200000+5; 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n,ans,is_centroid[maxn],sz[maxn],nn,cent;
lli k;
vector<pair<int,lli>> adj[maxn];
unordered_map<lli,int,custom_hash> cnt[maxn];

void dfs(int u,int p){
    sz[u] = 1;
    for(auto x : adj[u]){
        if(x.ff == p || is_centroid[x.ff])continue;
        dfs(x.ff,u);
        sz[u] += sz[x.ff];
    }
}

int get_centroid(int u,int p = -1){
    for(auto x : adj[u]){
        if(x.ff == p || is_centroid[x.ff])continue;
        if(sz[x.ff] > nn/2) return get_centroid(x.ff,u);
    }
    return u;
}
void dfs1(int u,int p,int lvl,lli w){
    if(k>=w && cnt[cent].find(k - w) != cnt[cent].end()){
        ans = min(ans,lvl + cnt[cent][k-w]);
    }
    for(auto x : adj[u]){
        if(x.ff == p || is_centroid[x.ff])continue;
        dfs1(x.ff,u,lvl+1,w + x.ss);
    }
}

void dfs2(int u,int p,int lvl,lli w){
    if(cnt[cent].find(w) == cnt[cent].end()){
        cnt[cent][w] = lvl;
    }else{
        cnt[cent][w] = min(cnt[cent][w],lvl);
    }
    for(auto x : adj[u]){
        if(x.ff == p || is_centroid[x.ff])continue;
        dfs2(x.ff,u,lvl+1,w + x.ss);
    }
}

int decompose(int u){
    dfs(u,-1);
    nn = sz[u];
    int p = get_centroid(u);
    cent = p;
    is_centroid[p] = 1;
    cnt[cent][0] = 0;
    for(auto x : adj[p]){
        if(is_centroid[x.ff])continue;
        dfs1(x.ff,p,1,x.ss);
        dfs2(x.ff,p,1,x.ss);
    }

    for(auto x : adj[p]){
        if(is_centroid[x.ff])continue;
        int q = decompose(x.ff);
    }

    return p;
}

int main(){
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        int u,v;lli w;
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    ans = 1e9 + 5;
    decompose(0);
    ans = (ans == 1e9 + 5) ? -1 : ans; 
    cout<<ans<<endl;
}
