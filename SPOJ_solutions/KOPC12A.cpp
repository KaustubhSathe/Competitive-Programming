#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
lli h[10000+5],c[10000+5];

lli f(lli x){
    lli ans = 0;
    for(int i =0;i<n;i++)
        ans += c[i]*abs(x - h[i]);

    return ans;
}



lli ternary_search(lli l,lli r){
    while(r - l >= 3){
        lli m1 = l + (r-l)/3;
        lli m2 = r - (r-l)/3;
        lli f1 = f(m1);
        lli f2 = f(m2);
        if(f1 < f2)
            r = m2;
        else
            l = m1;
    }
    return min(min(f(l),f(l+1)),f(l+2));
}


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i =0;i<n;i++)
            cin>>h[i];
        for(int i =0;i<n;i++)
            cin>>c[i];

        lli cost = ternary_search(0,10000);
        cout<<cost<<endl;
    }
}