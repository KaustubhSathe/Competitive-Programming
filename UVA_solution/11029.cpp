#include<bits/stdc++.h>
typedef int lli;
using namespace std;

lli binpow(lli a,lli b,lli m){
    if(b == 0)
        return 1;
    lli res = binpow(a,b/2,m);
    if(b%2 == 1)
        return ((((res%m)*(res%m))%m)*(a%m))%m;
    else
        return ((res%m)*(res%m))%m;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        lli n,k;
        cin>>n>>k;
        double x = k*log10(n);
        x = x - (lli)x;
        double ans = pow(10,x);
        ans = ans*100;
        lli z = binpow(n,k,1000);
        int y = ans;
        printf("%d...%03d\n",y,z);
    }
}