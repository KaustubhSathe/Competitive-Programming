#include<bits/stdc++.h>
#define MOD 1000000
using namespace std;

int n,k;
int dp[105][105];
int solve(int n,int k){
	if(k == 1)
		return 1;
	if(dp[n][k] != -1)
		return dp[n][k];

	int ans = 0;
	for(int i = 0;i<=n;i++){
		ans = (ans%MOD + solve(n-i,k-1)%MOD)%MOD;
	}

	return dp[n][k] = ans;
}
int main(){

	while(cin>>n>>k && !(n==0&&k==0)){
		memset(dp,-1,sizeof(dp));
		cout<<solve(n,k)<<endl;
	}	
}