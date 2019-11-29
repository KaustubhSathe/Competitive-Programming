#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define INF 1000000000
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
vector<int> adj[10000+5];
int maxd,itr;
void dfs1(int u,int p,int depth){
    if(maxd < depth){
        maxd = depth;
        itr = u;
    }

    for(auto itr : adj[u]){
        if(itr != p){
            dfs1(itr,u,depth+1);
        }
    }
}

int mex;
void dfs2(int u,int p,int depth){
    mex = max(mex,depth);
    for(auto itr : adj[u]){
        if(itr != p){
            dfs2(itr,u,depth+1);
        }
    }
}
int main(){
    fastio;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    maxd = itr = -1;
    dfs1(1,-1,0);
    mex = -1;
    dfs2(itr,-1,0);
    cout<<mex<<endl;

        
    return 0;
    
}
