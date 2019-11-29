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
pii arr[30000+5];
pair<pii,pii> queries[200000+5];
int ans[200000+5];
int st[4*30000+20];


void build(int v,int tl,int tr){
	if(tl == tr){
		st[v] = 1;
	}else{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		st[v] = st[2*v] + st[2*v+1];
	}
}
void update(int v,int tl,int tr,int pos,int new_val){
	if(tl == tr){
		st[v] = new_val;
	}else{
		int tm = (tl+tr)/2;
		if(pos <= tm)
			update(2*v,tl,tm,pos,new_val);
		else
			update(2*v+1,tm+1,tr,pos,new_val);

		st[v] = st[2*v] + st[2*v+1];
	}
}

int query(int v,int tl,int tr,int l,int r){
	if(l > r)
		return 0;

	if(l == tl && r == tr)
		return st[v];

	int tm = (tl+tr)/2;
	return query(2*v,tl,tm,l,min(r,tm))  + query(2*v+1,tm+1,tr,max(l,tm+1),r);
}
int main(){
    fastio;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
    	scanf("%d",&arr[i].ff);
    	arr[i].ss = i;
    }
    sort(arr+1,arr+n+1);
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
    	int l,r,k;
    	scanf("%d %d %d",&l,&r,&k);
    	queries[i].ff.ff = k;
    	queries[i].ff.ss = i;
    	queries[i].ss.ff = l;
    	queries[i].ss.ss = r;
    }
    sort(queries+1,queries+q+1);
    build(1,1,n);

    int pos = 1;
    for(int i = 1;i<=q;i++){
    	while(pos <= n && arr[pos].ff <= queries[i].ff.ff){
    		update(1,1,n,arr[pos].ss,0);
    		//cout<<arr[pos].ss<<endl;
    		pos++;
    	}
    	int l = queries[i].ss.ff;
    	int r = queries[i].ss.ss;
    	int temp = query(1,1,n,l,r);
    	int id = queries[i].ff.ss;
    	ans[id] = temp;
    }
    for(int i = 1;i<=q;i++)
    	printf("%d\n",ans[i]);

        
    return 0;
    
    
}
