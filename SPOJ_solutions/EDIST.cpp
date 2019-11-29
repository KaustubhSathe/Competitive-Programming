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
string s1,s2;
int dp[2005][2005];
void edit(){
    int n = s1.length(),m= s2.length();
    for(int i =0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i - 1] == s2[j -1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        edit();
        cout<<dp[s1.length()][s2.length()]<<endl;
    }
    return 0;
}
