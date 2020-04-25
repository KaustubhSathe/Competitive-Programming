// Solution: Simple MST problem
#include<bits/stdc++.h>
using namespace std;


int n,m;
int parent[100000+5],sz[100000+5],rnk[100000+5],cc;

void init(){
    for(int i = 0;i<100000+5;i++){
        parent[i] = i;
        sz[i] = 1;
        rnk[i] = 0;
        cc = n;
    }
};
int findSet(int u){
    return (parent[u] == u) ? u : parent[u] = findSet(parent[u]);
}

bool merge(int u,int v){
    int x = findSet(u);
    int y = findSet(v);

    if(x != y){
        if(rnk[x] < rnk[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rnk[x] == rnk[y])
                rnk[x]++;
        }
        cc--;

        return true;
    }

    return false;
}

int main(){
    int tc;
    cin>>tc;
    for(int t = 1;t<=tc;t++){
        cin>>n>>m;
        init();
        int cost = 0;
        for(int i = 0;i<m;i++){
            int u,v;cin>>u>>v;
            if(merge(u,v)){
                cost += 1;
            }
        }
        cost += 2*(cc-1);

        printf("Case #%d: %d\n",t,cost);
    }
}