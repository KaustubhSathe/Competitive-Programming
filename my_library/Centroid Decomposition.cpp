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


/******************************************* PROBLEMS ******************************************/
/*1. https://codeforces.com/problemset/problem/321/C 
Solution : Simple application, just rank each level of centroid tree with same character. Lower level gets higher rank. 
           If number of levels > 26 then Impossible.
int n,max_level,color[1000000+5];
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
 
void dfs2(int u,int p,int lvl){
    max_level = max(max_level,lvl);
    color[u] = lvl;
    for(auto x : centroid[u]){
        if(x != p){
            dfs2(x,u,lvl + 1);
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root_centroid_tree = decompose(1);
    dfs2(root_centroid_tree,-1,0);
    if(max_level > 26){
        cout<<"Impossible"<<endl;
        return 0;
    }
 
    for(int i = 1;i<=n;i++){
        char ch = (char)(color[i] + 'A'); 
        cout<<ch<<" ";
    }
    cout<<endl;
 
 
    return 0;
}*/

/*2. https://codeforces.com/contest/342/problem/E
Solution : Let dp[i] denote the minimum distance to red node in the subtree of centroid i in the centroid tree.
           1. update query paint node x red : for all ancestors i of x do dp[i] = min(dp[i],dis(x,i));
           Now this update takes log^2(n) time, but can be reduced to log(n) by using the optimization technique of caching
           the distance between node i and all its ancestors. This distance 2d array can be constructed during the construction of 
           centroid tree.
           2. Finding nearest red node to node i : Let ans = INF, then for all ancestors x of i 
           ans = min(ans,dis(i,x) + dp[x]), this will work because if the nearest red node is in the subtree of i
           then dis(i,i) + dp[i] will give the minimum and all its ancestors will be greater than this.


           
*/