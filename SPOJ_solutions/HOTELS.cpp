#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[300000+5];
int main(){
	cin>>n>>m;
	for(int i =0;i<n;i++)
		cin>>arr[i];

	int sum = 0,left = 0;
	int ans = -1000000000;
	for(int i =0;i<n;i++){
		sum += arr[i];
		if(sum <= m){
			ans = max(ans,sum);
			continue;
		}else{
			while(sum > m){
				sum -= arr[left++];
			}
			ans = max(ans,sum);
		}
	}
	cout<<ans<<endl;
}