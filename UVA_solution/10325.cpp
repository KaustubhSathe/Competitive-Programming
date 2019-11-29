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

lli n,m;
lli M[20];

lli __lcm(lli a,lli b){
	return (a/__gcd(a,b))*b;
}
int main(){
    fastio;
    while(cin>>n>>m){
    	for(lli i = 0;i<m;i++)
    		cin>>M[i];

    	lli ans = 0;
    	for(lli i = 1;i<(1<<m);i++){
    		lli bits = 0,lcm = 1;
    		for(int j = 0;j<m;j++){
    			if(i & (1<<j)){
    				bits++;
    				lcm = __lcm(lcm,M[j]);
    			}
    		}

    		lli cur = n/lcm;
    		if(bits%2 == 1)
    			ans += cur;
    		else
    			ans -= cur;
    	}
    	cout<<n-ans<<endl;
    }
        
    return 0;
    
}
