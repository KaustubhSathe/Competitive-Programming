#include<bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;



/*---------------------------------------------------START-CODE------------------------------------------------------*/
vector<int> parent, my_rank;

void make_set(int v) {
    parent[v] = v;
    my_rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (my_rank[a] < my_rank[b])
            swap(a, b);
        parent[b] = a;
        if (my_rank[a] == my_rank[b])
            my_rank[a]++;
    }
}


int t,n,m,x,y;
vector<vector<int>> graph;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>t;
    while(t--){
        cin>>n>>m;
        graph.resize(n+1);
        parent.resize(n+1);
        my_rank.resize(n+1);
        for(int i =0;i<m;i++){
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        for(int i =1;i<=n;i++)
            make_set(i);

        for(int i =1;i<=n;i++){
            for(int j = 0;j <graph[i].size();j++){
                union_sets(i,graph[i][j]);
            }
        }
        set<int> output;
        for(int i =1;i<=n;i++){
            output.insert(parent[i]);
        }
        cout<<output.size()<<endl;
    

    
        
        

    }
        

    }    

