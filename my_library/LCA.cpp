#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

int timer,lg;
vector<int> tin, tout;
vector<vector<int>> up;

void dfsLCA(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= lg; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfsLCA(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = lg; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int r) {
    tin.resize(n + 5);
    tout.resize(n + 5);
    timer = 0;
    lg = (int)ceil(log2(n + 0.0));
    up.assign(n + 5, vector<int>(lg + 5));
    dfsLCA(r, r);
}

int main(){

}