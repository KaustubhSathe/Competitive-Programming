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

int dp[15][1000000+5];
int nfactorful[1000000+5];

void sieve(){
	for(int i = 2;i<=1000000;i++){
		if(nfactorful[i] == 0){
			for(int j = i;j<=1000000;j+=i)
				nfactorful[j]++;
		}
	}	
	for(int i = 0;i<=10;i++){
		for(int j = 1;j<=1000000;j++){
			if(nfactorful[j] == i){
				dp[i][j] = dp[i][j-1] + 1;
			}else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
}

int main(){
    fastio;
    sieve();
    int tc;
    cin>>tc;
    while(tc--){
    	int a,b,n;
    	cin>>a>>b>>n;
    	cout<<dp[n][b] - dp[n][a-1]<<endl;
    }    
    return 0;
    
}
