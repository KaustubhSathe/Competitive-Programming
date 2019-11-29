//Don't be a lil bitch.
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
#define SIZE 10005
vector<pii> v[SIZE];
int d[SIZE];
bool visited[SIZE];

void dijkstra(int source){
    memset(d,200000,sizeof(d));
    memset(visited,false,sizeof(visited));
    d[source] = 0;
    multiset<pii> q;
    q.insert(mp(0,source));

    while(!q.empty()){
        pii top = *q.begin();
        q.erase(q.begin());
        if(visited[top.second])
            continue;
        visited[top.second] = true;
        for(int i =0;i<v[top.second].size();i++){
            if(d[top.second] + v[top.second][i].second < d[v[top.second][i].first]){
                d[v[top.second][i].first] = d[top.second] + v[top.second][i].second;
                q.insert(mp(d[v[top.second][i].first],v[top.second][i].first));
            }
        }
    }
}

int main(){
    fastio;
    int tc,n,nr,cost,r,p;
    string name,name1,name2;
    cin>>tc;
    while(tc--){
        cin>>n;
        map<string,int> city_names;
        for(int i =1;i<=n;i++){
            cin>>name;
            city_names[name] = i;
            cin>>p;
            for(int j =0;j<p;j++){
                cin>>nr>>cost;
                v[i].pb(mp(nr,cost));
            }
        }
        cin>>r;
        for(int i =0;i<r;i++){
            cin>>name1>>name2;
            dijkstra(city_names[name1]);
            cout<<d[city_names[name2]]<<endl;
        }

        for(int i =0;i<SIZE;i++){
            v[i].clear();
        }
    }
    


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
