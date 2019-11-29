#include<bits/stdc++.h>
typedef long long int lli;
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
		lli a,b;
		cin>>a>>b;
		lli z = binpow(a,b,10);
		cout<<z<<endl;
	}
}