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

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int n;
int segment[105][4];

int main(){
    fastio;
    int tc;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(int i = 0;i<n;i++){
    		cin>>segment[i][0]>>segment[i][1]>>segment[i][2]>>segment[i][3];
    	}
    	int cnt = 0;
    	for(int i = 0;i<n;i++){
    		bool flag = false;
    		for(int j = 0;j<n;j++){
    			if(j != i)
    				flag |= check_inter(pt(segment[i][0],segment[i][1]),pt(segment[i][2],segment[i][3]),pt(segment[j][0],segment[j][1]),pt(segment[j][2],segment[j][3]));
    		}
    		if(!flag)
    			cnt++;
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}
