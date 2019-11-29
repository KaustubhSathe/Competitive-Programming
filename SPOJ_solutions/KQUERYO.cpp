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
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n,q;
int arr[30000+5],ans[2000000+5];

vector<int> st[4*30000+20];

void build(int v,int tl,int tr){
	if(tl == tr){
		st[v].pb(arr[tl]);
	}else{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		merge(st[2*v].begin(),st[2*v].end(),st[2*v+1].begin(),st[2*v+1].end(),back_inserter(st[v]));
	}
}

int query(int v,int tl,int tr,int l,int r,int k){
	if(l > r)
		return 0;

	if(l == tl && r == tr)
		return st[v].size() - (upper_bound(st[v].begin(),st[v].end(),k)-st[v].begin());

	int tm = (tl+tr)/2;
	return query(2*v,tl,tm,l,min(r,tm),k) + query(2*v+1,tm+1,tr,max(l,tm+1),r,k);
}
int main(){
    fastio;
    
    cin>>n;
    for(int i = 1;i<=n;i++)
    	cin>>arr[i];


    build(1,1,n);
   	cin>>q;
   	for(int tc = 1;tc<=q;tc++){
   		int a,b,c;
   		cin>>a>>b>>c;
   		int l,r,k;
   		l = a^ans[tc-1];
   		r = b^ans[tc-1];
   		k = c^ans[tc-1];
   		if(l < 1)l = 1;
   		if(r > n)r = n;
   		if(l > r){
   			ans[tc] = 0;
   			continue; 
   		}
   		ans[tc] = query(1,1,n,l,r,k);
   	}
   	for(int i = 1;i<=q;i++)
   		cout<<ans[i]<<endl;
    return 0;
}
