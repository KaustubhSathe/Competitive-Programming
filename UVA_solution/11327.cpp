#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

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

lli k;
lli dp[200000+5];
void solve(){
	dp[0] = 0;
	dp[1] =2;
	for(int i = 2;i<=200000;i++){
		dp[i] = dp[i-1] + phi(i);
	}
}
int main(){
	solve();
	while(cin>>k && k != 0){
		int x = lower_bound(dp,dp+200000+1,k) - dp;

		lli cnt = k - dp[x-1];
		for(int i = 0;i<=x;i++){
			if(__gcd(x,i) == 1){
				cnt--;
			}
			if(cnt == 0){
				cout<<i<<"/"<<x<<endl;
				break;
			}
		}
	}
}