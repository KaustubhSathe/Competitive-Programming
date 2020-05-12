#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
long long int l,r;
vector<long long int> primes;
unordered_map<long long int,long long int> all;
unordered_map<lli,lli> aaoaa;
bool isPrime(long long int n){
    for(lli i = 2;i*i<=n;i++)
        if(n%i == 0)return false;

    return true;
}
void init(){
    for(lli i = 2;i*i<=1000000000;i++)
        if(isPrime(i))primes.push_back(i);
}
int main(){
    int tc;cin>>tc;
    init();
    for(int test = 1;test<=tc;test++){
        cin>>l>>r;
        // all.clear();
        for(lli i = l;i<=r;i++)all[i] = 1;
        
        for(lli i = l;i<=r;i++)aaoaa[i] = i;

        for(auto x : primes){
            for(lli i = x*(l/x);i<=r;i += x){
                if(i >= l){
                    lli temp = 0;
                    while(aaoaa[i]%x == 0){
                        aaoaa[i] /= x;
                        temp++; 
                    }
                    all[i] *= (temp + 1);
                }
            }
        }
        lli cnt = 0;

        for(lli i = l;i<=r;i++){
            if(aaoaa[i] > 1)all[i] *= 2;
            // cout<<all[i]<<endl;
            // if(all[i] == 1) all[i] = 2;
            lli twos = 0,itr = i;
            while(itr%2 == 0){
                itr /= 2;
                twos++;
            }

            lli even = (all[i]/(twos + 1))*twos;

            cnt += (abs(all[i] - 2*even) <= 2);
        }

        cout<<"Case #"<<test<<": "<<cnt<<endl;

    }
}

