// https://www.codechef.com/JAN19A/problems/DPAIRS
#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second

int main() {
	int n, m;
	cin>>n>>m;
	vector<pair<int,int>> t(n);
	for(int i=0;i<n;++i) {
		cin>>t[i].xx;
		t[i].yy=i;
	}
	
	vector<pair<int,int>> k(m);
	for(int j=0;j<m;++j) {
		cin>>k[j].xx;
		k[j].yy=j;
	}
	
	sort(t.begin(), t.end());
	sort(k.begin(), k.end());
	
	for(int j=0;j<m;++j) {
		cout<<t[0].yy<<" "<<k[j].yy<<"\n";
	}
	
	for(int i=1;i<n;++i) {
		cout<<t[i].yy<<" "<<k[m-1].yy<<"\n";
	}
	return 0;
}