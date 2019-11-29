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
bool is_prime[1000000+5];
int dp[1000000+5];

bool isValid(int p){
	if(!is_prime[p])
		return false;
	string s = to_string(p);
	for(auto itr : s){
		if(itr == '0')
			return false;
	}

	int num = 0;
	int factor = 1;
	for(int i = s.length()-1;i>=0;i--){
		num = (num + (s[i] - '0')*factor);
		factor *= 10;
		if(!is_prime[num])
			return false;
	}

	return true;
}
void sieve(){
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i*i<=1000000;i++){
		if(is_prime[i]){
			for(int j = i*i;j<=1000000;j+=i)
				is_prime[j] = false;
		}
	}
	dp[0] = 0;
	for(int i = 1;i<=1000000;i++){
		if(isValid(i)){
			dp[i] = dp[i-1] + 1;
		}else{
			dp[i] = dp[i-1];
		}
	}
	//cout<<is_prime[2]<<endl;

}

int main(){
    fastio;
    int tc;
    cin>>tc;
    sieve();
    while(tc--){
    	cin>>n;
    	cout<<dp[n]<<endl;
    }
        
    return 0;
    
}
