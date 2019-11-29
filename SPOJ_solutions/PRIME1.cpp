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
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

lli m,n;

bool isPrime(lli x){
    if(x == 1)
        return false;
    for(lli i = 2;i*i<=x;i++){
        if(x%i == 0)
            return false;
    }

    return true;
}

int main(){
    fastio;
    int tc;
    cin>>tc;
    while(tc--){
        cin>>m>>n;
        for(lli i = m;i<=n;i++)
            if(isPrime(i))
                cout<<i<<endl;


        cout<<endl;
    }

        
    return 0;
    
}
