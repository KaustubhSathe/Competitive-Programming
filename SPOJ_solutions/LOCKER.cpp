#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int lli;
#define MOD 1000000007
using namespace std;

map<lli,int> dp;

lli binpow(lli x){
	if(x == 2 || x == 3)
		return x;

	if(dp[x] != 0)
		return dp[x];

	if(x%2 == 1)
		return dp[x] = ((binpow(x/2)%MOD)*(binpow(x/2 + 1)%MOD))%MOD;
	else
		return dp[x] = ((binpow(x/2)%MOD)*(binpow(x/2)%MOD))%MOD;
}

int main(){
	fastio;
	int tc;
	cin>>tc;
	lli z = binpow(5);
	while(tc--){
		lli n;
		cin>>n;
		lli z = dp[n];
		cout<<z<<endl;
	}
}