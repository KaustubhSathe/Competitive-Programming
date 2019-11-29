#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

void multiply(lli A[3][3],lli B[3][3]){
	lli mul[3][3];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			mul[i][j] = 0;
			for(int k = 0;k<3;k++){
				mul[i][j] = (mul[i][j]%MOD + ((A[i][k]%MOD)*(B[k][j]%MOD))%MOD);
			}
		}
	}

	for(int i = 0;i<3;i++)
		for(int j = 0;j<3;j++)
			A[i][j] = mul[i][j];
}

void solve(lli F[3][3],lli n){
	if(n == 1)
		return;

	solve(F,n/2);
	lli P[3][3] = {{1,0,0},{1,0,1},{1,1,1}};
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
		lli n,m;
		cin>>n>>m;
		lli F[3][3] = {{1,0,0},{1,0,1},{1,1,1}};
		lli ans1 = 0,ans2 = m;
		if(n == 2)
			ans1 = 1;
		else if(n == 1)
			ans1 = 0;


		if(n >2){
			solve(F,n-2);
			ans1 = (F[0][0]%MOD + F[2][0]%MOD)%MOD;
			//cout<<ans1<<endl;
		}
		lli K[3][3] = {{1,0,0},{1,0,1},{1,1,1}};
		if(m > 1){
			solve(K,m-1);
			ans2 = (K[0][0]%MOD + K[2][0]%MOD)%MOD;
			//cout<<ans2<<endl;
		}
		
		lli ans3 = (ans2 - ans1 + MOD)%MOD;
		cout<<ans3<<endl;
		
	}
}