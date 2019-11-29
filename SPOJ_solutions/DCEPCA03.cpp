#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define INF 1000000000
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int phi(int n){
	int result = n;
	for(int i = 2;i*i<=n;i++){
		if(n%i == 0){
			while(n%i == 0)
				n = n/i;

			result -= result/i;
		}
	}
	if(n > 1)
		result -= result/n;

	return result;
}

int dp[10000+5];

void init(){
	for(int i = 1;i<=10000;i++)
		dp[i] = dp[i-1] + phi(i);
}
int main(){
    fastio;
 	int tc;
 	cin>>tc;
 	init();
 	while(tc--){
 		int n;
 		cin>>n;
 		lli ans = (lli)dp[n]*dp[n];
 		cout<<ans<<endl;
 	}       
    return 0;
}
