#include<bits/stdc++.h>
using namespace std;

int phi(int n){
	int result = n;
	for(int i = 2;i*i<=n;i++){
		if(n%i == 0){
			while(n%i == 0)
				n = n/i;

			result -= result/i;
		}
	}
	if(n > 1)
		result -= result/n;

	return result;
}

int main(){
	int n;
	while(cin>>n && n!=0){
		cout<<phi(n)<<endl;
	}
}