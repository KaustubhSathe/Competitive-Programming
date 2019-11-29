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
//Point is basic building block of higher dimensional geometry objects.
const double EPS = 1e-9;
#define PI acos(-1.0)
struct point_i{ //whenever possible work with point_i
	int x,y;
	point_i(){x = y = 0;}
	point_i(int _x,int _y) : x(_x),y(_y){}
	bool operator<(const point_i& other) const{
		return make_pair(x,y) < make_pair(other.x,other.y);
	}
	bool operator==(const point_i& other) const{
		return make_pair(x,y) == make_pair(other.x,other.y);
	}
};

struct point{ // only used if more precision is needed
	double x,y;
	point(){x = y = 0.0;}
	point(double _x,double _y) : x(_x),y(_y){}

	bool operator<(const point& other) const{
		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}

	bool operator==(const point& other) const{
		return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
	}
};

double dist(point& p1,point& p2){
	return hypot(p1.x-p2.x,p1.y-p2.y);
}

point rotate(point p, double theta){
	double rad = theta*PI/180.0; // multiply theta with PI/180.0
	return point(p.x*cos(rad) - p.y*sin(rad),p.x*sin(rad) + p.y*cos(rad));
}

struct line{ // we always use b = 1.0 here
	double a,b,c;
};

void pointsToLine(point p1,point p2,line& l){
	if(fabs(p1.x - p2.x) < EPS){
		l.a = 1.0;l.b = 0.0;l.c = -p1.x; // vertical line case
	}else{
		l.a = -(double)(p1.y - p2.y)/(p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a*p1.x) - p1.y;
	}
}

bool areParallel(line& l1,line& l2){
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line& l1,line& l2){
	return areParallel(l1,l2) && fabs(l1.c-l2.c) < EPS;
}

bool areIntersect(line& l1,line& l2,point& p){
	if(areParallel(l1,l2)) return false; // no intersection if lines are parallel
	p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b); 
	//special case : test for vertical line to avoid division by zero
	if(fabs(l1.b) > EPS)
		p.y = -(l1.a*p.x + l1.c);
	else
		p.y = -(l2.a*p.x + l2.c);

	return true; 
}

struct vec{
	double x,y;
	vec(double _x,double _y) : x(_x),y(_y){}
};

vec toVec(point& a,point& b){ // vector from a-->b
	return vec(b.x - a.x,b.y-a.y);
}

vec scale(vec v,double s){
	return vec(v.x*s,v.y*s);
}

point translate(point p,vec v){ // translate p according to v
	return point(v.x + p.x,v.y + p.y);
}

double dot(vec a,vec b){
	return (a.x*b.x + a.y*b.y);
}

double norm_sq(vec v){
	return v.x*v.x + v.y*v.y;
}

double distToLine(point p,point a,point b,point& c){ 
// returns the distance from p to the line defined by two points a and b(a and b must be different)
//the closest point is stored in the 4th parameter 
//formula c = a + u*ab
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	double u = dot(ap,ab)/norm_sq(ab);
	c = translate(a,scale(ab,u));
	return dist(p,c);
}

double distToLineSegment(point p,point a,point b,point& c){
	vec ap = toVec(a,p),ab = toVec(a,b);
	double u = dot(ap,ab)/norm_sq(ab);
	if(u < 0.0){// closer to a
		c = point(a.x,a.y);
		return dist(p,a);
	}
	if(u > 1.0){ //closer to b
		c = point(b.x,b.y);
		return dist(p,b);
	}
	return distToLine(p,a,b,c);
}

double angle(point a,point o,point b){
	vec oa = toVec(o,a),ob = toVec(o,b);
	return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double cross(vec a,vec b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p,point q,point r){ // returns true if point r is on the left side of line pq
	return cross(toVec(p,q),toVec(p,r)) > 0.0;
}

bool collinear(point p,point q,point r){ // returns true is point r is on the same line as pq
	return fabs(cross(toVec(p,q),toVec(p,r))) < EPS;
}



int main(){
    fastio;
	double xm,ym,x1,y1,x2,y2;
	int n;
	cout.precision(4);
	cout<<fixed;
	while(cin>>xm){
		cin>>ym;
		cin>>n;
		point ans,temp;
		double mn = INFINITY;
		for(int i = 1;i<=(2*n+2)/2;i++){
			if(i == 1){
				cin>>x1>>y1;
			}else{
				cin>>x2>>y2;
				if(distToLineSegment(point(xm,ym),point(x1,y1),point(x2,y2),temp) < mn){
					mn = distToLineSegment(point(xm,ym),point(x1,y1),point(x2,y2),temp);
					ans.x = temp.x;
					ans.y = temp.y;
				}
				swap(x1,x2);swap(y1,y2);
			}
		}
		cout<<ans.x<<endl;
		cout<<ans.y<<endl;

	}        
    return 0;
}
