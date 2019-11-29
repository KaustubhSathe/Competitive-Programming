#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

void multiply(lli A[2][2],lli B[2][2]){
	lli mul[2][2];
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			mul[i][j] = 0;
			for(int k = 0;k<2;k++){
				mul[i][j] = (mul[i][j]%MOD + ((A[i][k])*(B[k][j]))%MOD)%MOD;
			}
		}
	}

	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
			A[i][j] = mul[i][j];
}
void solve(lli F[2][2],lli n){
	if(n == 1)
		return;
	solve(F,n/2);
	lli P[2][2] = {{0,1},{1,1}};
	if(n%2 == 1){
		multiply(F,F);
		multiply(F,P);
	}else{
		multiply(F,F);
	}
}

int main(){
	int tc;
	cin>>tc;

	while(tc--){
		lli n;
		cin>>n;
		if(n == 0){
			cout<<0<<endl;
		}else if(n == 1){
			cout<<2<<endl;
		}else{
			lli F[2][2] = {{0,1},{1,1}};
			solve(F,n+1);
			cout<<(F[1][0]%MOD + F[1][1])%MOD<<endl;
		}
		
	}
}