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
    double x, y;
};

struct line {
    double a, b, c;
};

const double EPS = 1e-9;

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

bool intersect(line m, line n, pt & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
        && abs(det(m.a, m.c, n.a, n.c)) < EPS
        && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}



int main(){
    fastio;
   	double x1,y1,x2,y2,x3,y3,x4,y4;
   	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
   		double X1,Y1,X2,Y2,X3,Y3;
   		if(x1 == x3 && y1 == y3){
   			X1 = x2;Y1 = y2;
   			X2 = x1;Y2 = y1;
   			X3 = x4;Y3 = y4;
   		}else if(x1 == x4 && y1 == y4){
   			X1 = x2;Y1 = y2;
   			X2 = x1;Y2 = y1;
   			X3 = x3;Y3 = y3;
   		}else if(x2 == x3 && y2 == y3){
   			X1 = x1;Y1 = y1;
   			X2 = x2;Y2 = y2;
   			X3 = x4;Y3 = y4;
   		}else if(x2 == x4 && y2 == y4){
   			X1 = x1;Y1 = y1;
   			X2 = x2;Y2 = y2;
   			X3 = x3;Y3 = y3;
   		}

   		line l1,l2;
   		l1.a = Y2-Y1;
   		l1.b = X1-X2;
   		l1.c = Y3*(X2-X1) - X3*(Y2-Y1);
   		l2.a = Y3-Y2;
   		l2.b = X2-X3;
   		l2.c = Y1*(X3-X2) - X1*(Y3-Y2);
   		pt ptr;
   		bool ans = intersect(l1,l2,ptr);
   		//cout<<ans<<endl;
   		cout.precision(3);
   		cout<<fixed;
   		cout<<ptr.x<<" "<<ptr.y<<endl;
   	}

    return 0;
}
