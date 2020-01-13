#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vc vector<char>
#define vs vector<string>
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*-------CONSTANTS------- */
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
const int INF = 1000000000;
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;

//Custom hash,only use when key is integer
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
/*-----------------------------MATH STUFF----------------------------- */
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mulmod(int a, int b, int c){lli res=(lli)a*b;return(res>=c?res%c:res);}
template<typename T>T power_mod(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
//Factorials upto 1e5%MOD,nCr%MOD,nPr%MOD
lli fact[100000+5],fact_modinv[100000+5];
void fact_init(){
    fact[0] = 1ll;
    fact_modinv[0] = mod_inverse(fact[0],1ll*MOD);
    for(int i = 1;i<=100000;i++){
        fact[i] = mulmod(fact[i-1],i,1ll*MOD);
        fact_modinv[i] = mod_inverse(fact[i],1ll*MOD);
    }
}
lli choose(int n,int r){
    return mulmod(fact_modinv[n-r],mulmod(fact[n],fact_modinv[r],MOD),MOD);
}
lli P(int n,int r){
    return mulmod(fact[n],fact_modinv[n-r],1ll*MOD);
}
/*-----------------------------START----------------------------- */
int n,m;

int main(){
    fastio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        lli mat[n+5][m+5];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        lli dH[n+5][m+5],dV[n+5][m+5];
        for(int row = 0;row<n;row++){
            for (int i = 0, l = 0, r = -1; i < m; i++)
            {
                int k = (i > r) ? 1 : min(dH[row][l + r - i], r - i + 1ll);
                while (0 <= i - k && i + k < m && mat[row][i - k] == mat[row][i + k])
                {
                    k++;
                }
                dH[row][i] = k--;
                if (i + k > r)
                {
                    l = i - k;
                    r = i + k;
                }
            }
        }
        for (int col = 0; col < m; col++)
        {
            for (int i = 0, l = 0, r = -1; i < n; i++)
            {
                int k = (i > r) ? 1 : min(dV[l + r - i][col], r - i + 1ll);
                while (0 <= i - k && i + k < n && mat[i - k][col] == mat[i + k][col])
                {
                    k++;
                }
                dV[i][col] = k--;
                if (i + k > r)
                {
                    l = i - k;
                    r = i + k;
                }
            }
        }
        lli sum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                sum += min(dH[i][j],dV[i][j]);
            }
        }
        cout<<sum<<endl;
        // cout<<dV[1][2]<<endl;
    }
    return 0;
}

