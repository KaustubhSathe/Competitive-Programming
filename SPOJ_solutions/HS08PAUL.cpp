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

int n,cnt;
bool is_prime[10000000+5],represent[10000000+5];
int primes[10000000+5],dp[10000000+5];

bool isValid(int p){
	for(int y = 0;y<=57;y++){
		if(ceil(sqrt(p - y*y*y*y + 0.0)) == floor(sqrt(p - y*y*y*y + 0.0))){
			return true;
		}
	}
	return false;
}
void sieve(){
	memset(is_prime,true,sizeof(is_prime));
	cnt = 0;
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i<=10000000;i++){
		if(is_prime[i] && (long long int)i*i <= 10000000){
			for(int j = i*i;j<=10000000;j+=i)
				is_prime[j] = false;
		}
	}
	for(int i = 0;i<10000000;i++)
		if(is_prime[i])
			primes[cnt++] = i;

	for(int i = 0;i<cnt;i++){
		represent[primes[i]] = isValid(primes[i]);
	}

	dp[0] = 0;
	for(int i = 1;i<10000000;i++){
		if(is_prime[i]&&represent[i]){
			dp[i] = dp[i-1] + 1;
		}else{
			dp[i] = dp[i-1];
		}
	}
}

int main(){
    fastio;
	int tc;
	scanf("%d",&tc);
	sieve();
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}        
    return 0;
}
