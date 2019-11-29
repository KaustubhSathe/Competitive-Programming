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

bool inter1(long long a, long long b, long long c, long long d){
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

int main(){
    fastio;
    int tc;
    scanf("%d",&tc);

    while(tc--){
    	lli a,b,c,d,e,f,g,h;
    	scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g,&h);
    	

    	pt p1(a,b),p2(c,d),p3(e,f),p4(g,h),p6(g,f),p5(e,h);
    	if((a>=e && a<= g && b>=h && b<=f) || (c>=e && c<= g && d>=h && d<=f)){
    		printf("T\n");
    	}else if(check_inter(p1,p2,p3,p5) || check_inter(p1,p2,p3,p6) || check_inter(p1,p2,p6,p4) || check_inter(p1,p2,p5,p4)){
    		printf("T\n");
    	}else{
    		printf("F\n");
    	}
    }

    return 0;
}

