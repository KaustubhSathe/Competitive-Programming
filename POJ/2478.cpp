#include<iostream>

using namespace std;
typedef long long int lli;

lli n;
lli phi[1000000+5],not_prime[1000000+5],dp[1000000+5];
void sieve(){
	for(int i = 1;i<=1000000;i++){
		phi[i] = i;
	}
	not_prime[0] = not_prime[1] = true;
	for(lli i = 2;i<=1000000;i++){
		if(!not_prime[i]){
			for(lli j = i*i;j<=1000000;j+=i){
				not_prime[j] = true;
			}
		}
	}
	for(lli i = 2;i<=1000000;i++){
		if(!not_prime[i]){
			for(lli j = i;j<=1000000;j+=i){
				phi[j] *= (i-1);
				phi[j] /= i;
			}
		}
	}
	for(int i = 1;i<=1000000;i++){
		dp[i] = dp[i-1] + phi[i];
	}
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	sieve();
	// cout<<dp[2]<<endl;
	while(cin>>n && n != 0){
		cout<<1+dp[n] - 2<<endl;
	}
	
	
	return 0;
}

