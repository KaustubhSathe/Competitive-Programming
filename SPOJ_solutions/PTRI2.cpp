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
pii pos[100000000+5];
void sieve(){
	is_prime.assign(100000000,true);
	
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i*i<=100000000;i++){
		if(is_prime[i]){
			for(int j = i*i;j<=100000000;j+=i)
				is_prime[j] = false;
		}
	}
	for(int i = 0;i<=100000000;i++)
		if(is_prime[i])
			primes.pb(i);

	int itr = 0,row = 1;

	while(itr < primes.size()){
		for(int i = 0;i<row;i++){
			pos[primes[i+itr]] = mp(row,i+1);
		}
		itr += row;
		row++;
	}


}
int main(){
    fastio;
    int tc;
    cin>>tc;
    sieve();
    while(tc--){
    	cin>>n;
    	if(is_prime[n])
    		cout<<pos[n].ff<<" "<<pos[n].ss<<endl;
    	else
    		cout<<-1<<endl;
    }
        
    return 0;
    
}
