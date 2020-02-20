## DSU on Trees

Using DSU on trees we can answer queries like: How many vertices in the subtree of vertex $V$ has some property in $O(nlogn)$ time for all queries offline.

---------------------------------------------------
### Different types of queries.
First calculate size of each subtree.
```cpp
    int sz[maxn];
    void getsz(int v, int p){
        sz[v] = 1;  // every vertex has itself in its subtree
        for(auto u : g[v])
            if(u != p){
                getsz(u, v);
                sz[v] += sz[u]; // add size of child u to its parent(v)
            }
    }
```

##### 1. How many vertices in subtree of vertex $V$ are colored with color $c$.

 - **Naive Approach $O(n^2)$**
```cpp
    int cnt[maxn];
    void add(int v, int p, int x){
        cnt[ col[v] ] += x;
        for(auto u: g[v])
            if(u != p)
                add(u, v, x)
    }
    void dfs(int v, int p){
        add(v, p, 1);
        //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
        add(v, p, -1);
        for(auto u : g[v])
            if(u != p)
                dfs(u, v);
    }
```
 - **$O(nlog^2(n))$ approach**
```cpp
    map<int, int> *cnt[maxn];
    void dfs(int v, int p){
        int mx = -1, bigChild = -1;
        for(auto u : g[v])
            if(u != p){
                dfs(u, v);
                if(sz[u] > mx)
                    mx = sz[u], bigChild = u;
            }
        
        if(bigChild != -1)
            cnt[v] = cnt[bigChild];
        else
            cnt[v] = new map<int, int> ();
        
        (*cnt[v])[ col[v] ] ++;
        for(auto u : g[v])
            if(u != p && u != bigChild){
                for(auto x : *cnt[u])
                    (*cnt[v])[x.first] += x.second;
            }
        
        //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    }
```
    
 - **$O(nlog(n))$ approach Heavy Light Decomposition Style**
```cpp
    int cnt[maxn];
    bool big[maxn];
    void add(int v, int p, int x){
        cnt[ col[v] ] += x;
        for(auto u: g[v])
            if(u != p && !big[u])
                add(u, v, x);
    }
    void dfs(int v, int p, bool keep){
        int mx = -1, bigChild = -1;
        for(auto u : g[v])
            if(u != p && sz[u] > mx)
                mx = sz[u], bigChild = u;
        
        for(auto u : g[v])
            if(u != p && u != bigChild)
                dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
        
        if(bigChild != -1)
            dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
        
        add(v, p, 1);
        //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
        if(bigChild != -1)
            big[bigChild] = 0;
        
        if(keep == 0)
            add(v, p, -1);
    }
```

-----------------------------------------------------------------------------------------------------------------------
## Problems

**1. https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/the-grass-type/**
The naive approach would be to consider all pairs of vertices and calculate their $LCA$ in $O(1)$ or $O(logn)$ time
and the resulting time complexity will be $O(n^2)$ or $O(n^2logn)$. But this will easily give TLE verdict.

Faster approach would be to use DSU in tree as follows : Suppose we are at node $u$ and it has $k$ children $v_1,v_2..v_k$ then $u$ will be the $lca$ when we take pair $(a,b)$ such that $a\in v_i\;subtree$ and $b\in v_j\;subtree$ and $i\;!=j$. Now maintain a map<int,int> val[maxn] for each node which stores the count of each label in the subtree of that node.
Now there are two cases, 1st when in pair $(a,b)$ both $a$ and $b$ belong to subtree of different children of $u$ and 2nd when $a = u$ and $b$ belong to one the subtree of children of $u$.
Let's first handle the 1st case. To do this we find the child of $u$ which has the biggest size of map and denote it as the heavy child of u. And then iterate upon the map of light child of $u$ and add it to our answer, and also keep inserting the corresponding values from light child map into heavy child map.
Now after this step we get all the values in heavy child map, to solve the second case we see the fact that $A_u = A_u*A_j => A_j = 1$ so just add the count of 1 in the heavy child map to our answer.

```cpp
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define ff first
    #define ss second
    typedef long long int lli;

    vector<int> adj[100000+5];
    int n;
    lli A[100000+5],ans;
    map<lli,lli>* cnt[100000+5];

    void dfs(int u,int p){
        int heavyChild = -1,mx = -1;
        
        for(auto x : adj[u]){
            if(x != p){
                dfs(x,u);
                if((int)cnt[x]->size() > mx){
                    mx = (int)cnt[x]->size();
                    heavyChild = x;
                }
            }
        }
        if(heavyChild != -1)
            cnt[u] = cnt[heavyChild];
        else
            cnt[u] = new map<lli,lli>();
            
        for(auto x: adj[u]){
            if(x != p && x != heavyChild){
                for(auto it : *cnt[x]){
                    if(A[u]%it.ff == 0 && cnt[heavyChild]->find(A[u]/it.ff) != cnt[heavyChild]->end()){
                        ans += 1ll*it.ss*((*cnt[heavyChild])[A[u]/it.ff]);
                    }
                }
                for(auto it : *cnt[x]){
                    (*cnt[heavyChild])[it.ff] += it.ss;
                }
            }
        }
        if(cnt[u]->find(1) != cnt[u]->end())    
            ans += (*cnt[u])[1];   
        
        (*cnt[u])[A[u]]++;
    }
    int main(){
        cin>>n;
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 1;i<=n;i++){
            cin>>A[i];
        }
        
        ans = 0ll;
        dfs(1,-1);
        cout<<ans<<endl;
    }
```

**2. https://vjudge.net/problem/SGU-507**
To solve this problem keep multiset<int>* cnt[maxn] for each node, and then do additions from light child to heavy child and get the answer.
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back

    int n,m;
    vector<int> adj[50000+5];
    int val[50000+5],ans[50000+5];
    multiset<int>* cnt[50000+5];

    void dfs(int u,int p){
        int heavy = -1,mx = -1;
        for(auto x : adj[u]){
            if(x != p){
                dfs(x,u);
                ans[u] = min(ans[u],ans[x]);
                if(mx < (int)cnt[x]->size()){
                    mx = (int)cnt[x]->size();
                    heavy = x;
                }
            }
        }

        if(heavy != -1){
            cnt[u] = cnt[heavy];
        }else{
            cnt[u] = new multiset<int>();
        }
            
        for(auto x : adj[u]){
            if(x != p && x != heavy){
                for(auto it : *cnt[x]){
                    auto now = (*cnt[heavy]).insert(it);
                    auto nxt = now;
                    if(now != cnt[heavy]->end()){
                        nxt++;
                        if(nxt != cnt[heavy]->end())
                            ans[u] = min(ans[u],abs(*now-*nxt));
                    }
                        
                    auto prev = now;
                    if(now != cnt[heavy]->begin()){
                        prev--;
                        ans[u] = min(ans[u],abs(*now-*prev));
                    }
                }
            }
        }

        if(adj[u].size() == 1){
            cnt[u]->insert(val[u]);
        }    
    }

    int main(){
        cin>>n>>m;
        for(int i = 2;i<=n;i++){
            int p;cin>>p;
            adj[i].pb(p);
            adj[p].pb(i);
        }
        for(int i = n-m+1;i<=n;i++){
            int x;cin>>x;
            val[i] = x;
        }
        for(int i = 0;i<50000+5;i++){
            ans[i] = INT32_MAX;
        }
        dfs(1,-1);
        
        for(int i = 1;i<=n-m;i++){
            cout<<ans[i]<<" ";
        }

    }
```

**3. https://codeforces.com/contest/570/problem/D**
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int lli;
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define pii pair<int,int>
    int n,m;
    vector<int> adj[500000+5];
    string s;
    vector<pii> query[500000+5];
    int big[500000+5],ans[500000+5],cnt[30][500000+5],cnt2[500000+5],sz[500000+5],lvl[500000+5];

    void getSZ(int u,int p){
        lvl[u] = 1 + lvl[p];
        sz[u] = 1;
        for(auto x : adj[u]){
            if(x != p){
                getSZ(x,u);
                sz[u] += sz[x];
            }
        }
    }
    void add(int u,int p,int val){
        cnt2[lvl[u]] -= cnt[s[u-1]-'a'][lvl[u]]%2;
        cnt[s[u-1]-'a'][lvl[u]] += val;
        cnt2[lvl[u]] += cnt[s[u-1]-'a'][lvl[u]]%2;
        
        for(auto x : adj[u]){
            if(x != p && !big[x]){
                add(x,u,val);
            }
        }
    }
    void dfs(int u,int p,int keep){
        int mx = -1,bigChild = -1;
        for(auto x : adj[u]){
            if(x != p && sz[x] > mx){
                mx = sz[x];
                bigChild = x;
            }
        }

        for(auto x : adj[u])
            if(x != p && x != bigChild)
                dfs(x, u, 0);

        if(bigChild != -1)
            dfs(bigChild,u,1),big[bigChild] = 1;

        add(u,p,1);
        
        for(auto x : query[u]){
            ans[x.ss] = (int)(cnt2[x.ff] <= 1);
        }
        
        if(bigChild != -1)
            big[bigChild] = 0;

        if(keep == 0)
            add(u,p,-1);
    }


    int main(){
        ios::sync_with_stdio(0), cin.tie(0);
        cin>>n>>m;
        for(int i = 2;i<=n;i++){
            int p;
            cin>>p;
            adj[p].pb(i);
            adj[i].pb(p);
        }
        cin>>s;
        for(int i = 1;i<=m;i++){
            int v,h;
            cin>>v>>h;
            query[v].pb(mp(h,i));
        }
        lvl[0] = 0;
        getSZ(1,0);
        dfs(1,-1,1);
        for(int i = 1;i<=m;i++){
            if(ans[i])
                cout<<"Yes"<<'\n';
            else
                cout<<"No"<<'\n';
        }
    }
```

**4. https://codeforces.com/contest/246/problem/E**
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    typedef long long int lli;
    #define mp make_pair
    #define ff first
    #define ss second
    #define pii pair<int,int>

    int n,m,ans[100000+5],sz[100000+5],lvl[100000+5],big[100000+5],unq[100000+5];
    vector<int> root;
    unordered_map<string,int> cnt[100000+5];
    string s[100000+5];
    vector<int> adj[100000+5];
    vector<pii> query[100000+5];

    void getSz(int u,int p){
        lvl[u] = lvl[p] + 1;
        sz[u] = 1;
        for(auto x : adj[u]){
            if(x != p){
                getSz(x,u);
                sz[u] += sz[x];
            }
        }
    }

    void add(int u,int p,int val){
        cnt[lvl[u]][s[u]] += val;
        if(cnt[lvl[u]][s[u]] == 0){
            unq[lvl[u]]--;
        }else if(cnt[lvl[u]][s[u]] == 1 && cnt[lvl[u]][s[u]] - val == 0){
            unq[lvl[u]]++;
        }
        
        for(auto x : adj[u])
            if(x != p && !big[x])
                add(x,u,val);

    }

    void dfs(int u,int p,int keep){
        int mx = -1,bigChild = -1;
        for(auto x : adj[u])
            if(x != p && sz[x] > mx)
                mx = sz[x],bigChild = x;

        for(auto x : adj[u])
            if(x != p && x != bigChild)
                dfs(x,u,0);

        if(bigChild != -1)
            dfs(bigChild,u,1),big[bigChild] = 1;

        add(u,p,1);
        for(auto x : query[u]){
            ans[x.ss] = unq[x.ff + lvl[u]];
        }
        if(bigChild != -1)
            big[bigChild] = 0;
        
        if(keep == 0)
            add(u,p,-1);
    }

    int main(){
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>s[i];
            int p;cin>>p;
            if(p == 0){
                root.pb(i);
            }else{
                adj[p].pb(i);
                adj[i].pb(p);
            }
        }
        cin>>m;
        for(int i = 1;i<=m;i++){
            int v,k;cin>>v>>k;
            query[v].pb(mp(k,i));
        }
        lvl[0] = -1;

        for(auto x : root){
            getSz(x,0);
            dfs(x,-1,0);
        }
        for(int i = 1;i<=m;i++){
            cout<<ans[i]<<endl;
        }

    }
```

**5. https://codeforces.com/contest/600/problem/E**
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int lli;
    #define pb push_back

    int n,sz[100000+5],big[100000+5];
    lli c[100000+5],ans[100000+5],cnt[100000+5],maxx,sum;
    vector<int> adj[100000+5];

    void getSz(int u,int p){
        sz[u] = 1;
        for(auto x : adj[u]){
            if(x != p){
                getSz(x,u);
                sz[u] += sz[x];
            }
        }
    }

    void add(int u,int p,int val){
        cnt[c[u]] += val;
        if(val == 1){
            if(maxx < cnt[c[u]]){
                maxx = cnt[c[u]];
                sum = c[u];
            }else if(maxx == cnt[c[u]]){
                sum += c[u];
            }
        }
        for(auto x : adj[u])
            if(x != p && !big[x])
                add(x,u,val);
    }

    void dfs(int u,int p,int keep){
        int mx =  -1,bigChild = -1;
        for(auto x : adj[u]){
            if(x != p && sz[x] > mx){
                mx = sz[x];
                bigChild = x;
            }
        }
        for(auto x : adj[u])
            if(x != p && x != bigChild)
                dfs(x,u,0);
        
        if(bigChild != -1)
            dfs(bigChild,u,1),big[bigChild] = 1;

        add(u,p,1);
        ans[u] = sum;
        if(bigChild != -1)
            big[bigChild] = 0;
        
        if(keep == 0)
            add(u,p,-1),maxx=sum=0;
    }
    int main(){
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>c[i];
        }
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        getSz(1,-1);
        dfs(1,-1,0);
        for(int i = 1;i<=n;i++){
            cout<<ans[i]<<" ";
        }

    }
```

**6. https://codeforces.com/contest/208/problem/E**
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define ss second 
    #define ff first
    #define pii pair<int,int>
    typedef long long int lli;


    int n,sz[100000+5],m,up[100000+5][20],big[100000+5],ans[100000+5],lvl[100000+5],cnt[100000+5];
    vector<int> adj[100000+5],root;
    vector<pii> queries[100000+5];

    void getSz(int u,int p){
        lvl[u] = 1 + lvl[p];
        sz[u] = 1;
        for(auto x : adj[u]){
            if(x != p){
                getSz(x,u);
                sz[u] += sz[x];
            }
        }
    }
    void add(int u,int p,int val){
        cnt[lvl[u]] += val;
        for(auto x : adj[u]){
            if(x != p && !big[x]){
                add(x,u,val);
            }
        }
    }

    void dfs(int u,int p,int keep){
        int mx = -1,bigChild = -1;
        for(auto x : adj[u]){
            if(x != p && sz[x] > mx){
                mx = sz[x];
                bigChild = x;
            }
        }

        for(auto x : adj[u]){
            if(x != p && x != bigChild){
                dfs(x,u,0);
            }
        }

        if(bigChild != -1)
            dfs(bigChild,u,1),big[bigChild]=1;

        add(u,p,1);
        for(auto x : queries[u]){
            ans[x.ss] = cnt[x.ff + lvl[u]];
        }

        if(bigChild != -1)
            big[bigChild] = 0;

        if(keep == 0)
            add(u,p,-1);
    }
    int main(){
        cin>>n;
        for(int i = 1;i<=n;i++){
            int r;cin>>r;
            if(r == 0){
                root.pb(i);
            }else{
                up[i][0] = r;
                adj[i].pb(r);
                adj[r].pb(i);
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=17;j++){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        cin>>m;
        for(int i = 1;i<=m;i++){
            int v,p;
            cin>>v>>p;
            int V = v;
            for(int i = 0;i<=20;i++){
                if((1<<i)&p){
                    v = up[v][i];
                }
            }
            queries[v].pb(mp(p,i));
        }
        lvl[0] = -1;
        for(auto x : root){
            getSz(x,0);
            dfs(x,0,0);
        }

        for(int i = 1;i<=m;i++){
            ans[i] = (ans[i] == 0) ? 0 : ans[i] - 1;
            cout<<ans[i]<<" ";
        }
    }
```

**7. https://contest.yandex.com/ioi/contest/571/problems/B/**
Solution based on centroid decomposition.
```cpp

```

**8. https://codeforces.com/contest/291/problem/E**

**9. https://codeforces.com/contest/1009/problem/F**
```cpp
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define pii pair<int,int>
    typedef long long int lli;
    const int maxn = 1e6 + 5;

    int n,big[maxn],lvl[maxn],sz[maxn],maxx,level,ans[maxn],cnt[maxn];
    vector<int> adj[maxn];
    set<pii> pq;
    void getSz(int u,int p){
        lvl[u] = 1 + lvl[p];
        sz[u] = 1;
        for(auto x : adj[u]){
            if(x != p){
                getSz(x,u);
                sz[u] += sz[x];
            }
        }
    }

    void add(int u,int p,int val){
        if(val == 1){
            pq.erase(mp(-cnt[lvl[u]],lvl[u]));
            cnt[lvl[u]] += val;
            pq.insert(mp(-cnt[lvl[u]],lvl[u]));
        }else{
            cnt[lvl[u]] = 0;
        }
        
        for(auto x : adj[u]){
            if(x != p && !big[x]){
                add(x,u,val);
            }
        }   
    }

    void dfs(int u,int p,int keep){
        int mx = -1,bigChild = -1;
        for(auto x : adj[u]){
            if(x != p && sz[x] > mx){
                mx = sz[x];
                bigChild = x;
            }
        }
        for(auto x : adj[u]){
            if(x != p && x != bigChild){
                dfs(x,u,0);
            }
        }

        if(bigChild != -1)
            dfs(bigChild,u,1),big[bigChild] = 1;

        add(u,p,1);
        ans[u] = pq.begin()->second - lvl[u];

        if(bigChild != -1)
            big[bigChild] = 0;
        
        if(keep == 0){
            add(u,p,0);
            pq.clear();
        }
            
    }
    int main(){
        cin>>n;
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        getSz(1,0);
        dfs(1,0,0);
        for(int i = 1;i<=n;i++)
            cout<<ans[i]<<endl;
    }
```

**10.  https://wcipeg.com/problem/ioi1112**
Centroid decomposition based solution.
```cpp
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
```




