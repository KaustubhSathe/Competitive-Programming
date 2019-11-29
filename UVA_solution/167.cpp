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

int chess[8][8];
bool col[8];
bool diag1[15],diag2[15];
int sum,ans;
void bt(int n){
	if(n == 8){
		ans = max(ans,sum);
		return;
	}

	for(int i = 0;i<8;i++){
		if(!col[i] && !diag1[n+i] && !diag2[n-i+7]){
			col[i] = true;
			diag1[n+i] = true;
			diag2[n-i+7] = true;
			sum += chess[n][i];
			bt(n+1);
			col[i] = false;
			diag1[n+i] = false;
			diag2[n-i+7] = false;
			sum -= chess[n][i];
		}
	}
}
int main(){
    fastio;
	int tc;
	cin>>tc;
	while(tc--){
		for(int i =0;i<8;i++)
			for(int j =0;j<8;j++)
				cin>>chess[i][j];

		memset(col,false,sizeof(col));
		memset(diag1,false,sizeof(diag1));
		memset(diag2,false,sizeof(diag2));
		ans = -1;
		sum = 0;
		bt(0);
		cout<<setw(5)<<setiosflags(ios::right)<<ans<<endl;
	}
	return 0;
}
