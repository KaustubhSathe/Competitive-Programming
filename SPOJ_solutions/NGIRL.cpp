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

lli n,k;
unordered_map<lli,bool> not_prime;
vector<lli> desired;
unordered_map<lli,bool> isValid;
void sieve(){
	not_prime[0] = not_prime[1] = true;
	for(lli i = 2;i*i<=100000;i++){
		if(!not_prime[i]){
			for(lli j = i*i;j<=100000;j+=i)
				not_prime[j] = true;
		}
	}
	for(lli i = 2;i<=100000;i++){
		if(!not_prime[i]){
			desired.pb(i*i);
			isValid[i*i] = true;
		}
	}

}

int main(){
    fastio;
    sieve();
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		if(n < 4){
			cout<<0<<" "<<0<<endl;
		}else{
			lli ans1 = upper_bound(desired.begin(),desired.end(),n) - desired.begin();
			lli ans2 = upper_bound(desired.begin(),desired.end(),k) - desired.begin();
			ans2 = ans1 - ans2;
			if(k > n)
				ans2 = 0;
			cout<<ans1<<" "<<ans2<<endl;
		}
	}        
    return 0;
}
