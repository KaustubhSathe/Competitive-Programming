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

int n;
vector<bool> is_prime;
vector<int> primes;
int cnt;
void sieve(){
	n = 100000000;
	is_prime.assign(n,true);
	primes.resize(n);
	is_prime[0] = is_prime[1] = false;
	cnt = 0;
	for(int i = 2;i<=n;i++){
		if(is_prime[i] && (long long int)i*i <= n){
			for(int j = i*i;j<=n;j+=i)
				is_prime[j] = false;
		}
	}
	for(int i = 2;i<=100000000;i++){
		if(is_prime[i]){
			primes[cnt++] = i;
		}
	}


}

int main(){
    fastio;
    sieve();
    for(int i = 1;i<=cnt;i+=100){
    	cout<<primes[i-1]<<endl;
    }
        
    return 0;
    
}
