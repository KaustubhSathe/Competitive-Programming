#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define vi vector<int>
#define vpii vector<pii>
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}


/*---------------------------------------------------START-CODE------------------------------------------------------*/
vector<int> adj[100000+5],costs[100000+5],indexx[100000+5];
int baseArray[100000+5],ptr;
int chainNo,chainInd[100000+5],chainHead[100000+5],posInBase[100000+5];
int depth[100000+5],pa[17][100000+5],otherEnd[100000+5],subsize[100000+5];
pair<int,int> st[4*100000+20];
pair<int,int> combine(pii a,pii b){
    return mp(min(a.first,b.first),max(a.second,b.second));
}

void build(int v,int tl,int tr){
    if(tl == tr){
        st[v] = mp(baseArray[tl],baseArray[tl]);
    }else{
        int tm =(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v] = combine(st[2*v],st[2*v+1]);
    }
}

void dfs(int source,int parent,int _depth){
    subsize[source] = 1;
    pa[0][source] = parent;
    depth[source] = _depth;
    for(int i =0;i<adj[source].size();i++){
        if(adj[source][i] != parent){
            otherEnd[indexx[source][i]] = adj[source][i];
            dfs(adj[source][i],source,_depth+1);
            subsize[source] += subsize[adj[source][i]];
        }
    }
    
}

void HLD(int curNode,int cost,int parent){
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = curNode;
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;
    baseArray[ptr++] = cost;
    int sc = -1,ncost;
    for(int i =0;i<adj[curNode].size();i++){
        if(adj[curNode][i] != parent){
            if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]){
                sc = adj[curNode][i];
                ncost = costs[curNode][i];
            }
        }
    }
    if(sc != -1){
        HLD(sc,ncost,curNode);
    }

    for(int i =0;i<adj[curNode].size();i++){
        if(adj[curNode][i] != parent && sc != adj[curNode][i]){
            chainNo++;
            HLD(adj[curNode][i],costs[curNode][i],curNode);
        }
    }
}
void update_tree(int v,int tl,int tr,int pos,int new_value){
    if(tl == tr){
        st[v] = mp(new_value,new_value);
    }else{
        int tm = (tl+tr)/2;
        if(pos <= tm)
            update_tree(2*v,tl,tm,pos,new_value);
        else
            update_tree(2*v+1,tm+1,tr,pos,new_value);
        st[v] = combine(st[2*v],st[2*v+1]);
    }
}

pair<int,int> query_tree(int v,int tl,int tr,int l,int r){
    if(l>r)
        return mp(INF,-INF);
    if(l==tl && r==tr){
        return st[v];
    }
    int tm = (tl+tr)/2;
    return combine(query_tree(2*v,tl,tm,l,min(r,tm)),query_tree(2*v+1,tm+1,tr,max(l,tm+1),r));
}
pair<int,int> query_up(int u,int v){
    if(u==v)
        return mp(INF,-INF);
    int uchain,vchain = chainInd[v];
    pii ans = mp(INF,-INF);
    while(1){
        uchain = chainInd[u];
        //cout<<"uchain"<<uchain<<endl;
        //cout<<"vchain"<<vchain<<endl;
        if(uchain == vchain){
            if(u==v)
                break;
            ans = combine(ans,query_tree(1,0,ptr-1,posInBase[v] +1,posInBase[u]));
            break;
        }
        ans = combine(ans,query_tree(1,0,ptr-1,posInBase[chainHead[uchain]],posInBase[u]));
        u = chainHead[uchain];
        u = pa[0][u];
    }
    return ans;
}
int LCA(int u,int v){
    if(depth[u] < depth[v])
        swap(u,v);
    
    int diff = depth[u] - depth[v];
    for(int i =0;i<17;i++){
        if(diff&(1<<i)){
            u = pa[i][u];
        }
    }
    if(u==v)
        return u;
    
    for(int i = 16;i>=0;i--){
        if(pa[i][u] != pa[i][v]){
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

void query(int u,int v){
    int lca = LCA(u,v);
    pii ans = query_up(u,lca);
    pii temp = query_up(v,lca);
    ans = combine(temp,ans);
    cout<<ans.second<<endl;
}
void change(int i,int new_value){
    int u = otherEnd[i];
    update_tree(1,0,ptr-1,posInBase[u],new_value);
}
int main(){
    fastio;
    int tc;
    cin>>tc;
    while(tc--){
        ptr = 0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            for(int j =0;j<17;j++)
                pa[j][i] = -1;
        }
        for(int i = 1;i<n;i++){
            int u,v,c;
            cin>>u>>v>>c;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
            costs[u].pb(c);
            costs[v].pb(c);
            indexx[u].pb(i-1);
            indexx[v].pb(i-1);
        }
        chainNo = 0;
        dfs(0,-1,0);
        HLD(0,-1,-1);
        build(1,0,ptr-1);

        for(int i =1;i<17;i++){
            for(int j =0;j<n;j++){
                if(pa[i-1][j] != -1){
                    pa[i][j] = pa[i-1][pa[i-1][j]];
                }
            }
        }
        //cout<<LCA(2-1,3-1)<<endl;
        //cout<<query_up(2-1,13).second<<endl;
        //cout<<posInBase[2-1]<<endl;
        while(1){
            string s;
            cin>>s;
            if(s[0] == 'D')
                break;
            
            int a,b;
            cin>>a>>b;
            if(s[0] == 'Q'){
                query(a-1,b-1);
            }else{  
                change(a-1,b);
            }
        }
    }
    


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
