#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define vi vector<int>
#define vpii vector<pii>
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}


/*---------------------------------------------------START-CODE------------------------------------------------------*/

struct data{
    lli sum,pref,suff,ans;
};
int n,m,op,a,b;
lli arr[50000+5];
data st[4*50000+5];

data make_data(lli v){
    data res;
    res.sum = res.pref = res.suff = res.ans = v;
    return res;
}
data combine(data l,data r){
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref,l.sum+r.pref);
    res.suff = max(r.suff,r.sum+l.suff);
    res.ans = max(max(l.ans,r.ans),l.suff + r.pref);
    return res;
}
void build(int v,int tl,int tr){
    if(tl == tr){
        st[v] = make_data(arr[tl]);
    }else{
        int tm =(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v] = combine(st[2*v],st[2*v+1]);
    }
}
void update(int v,int tl,int tr,int pos,int val){
    if(tl == tr){
        st[v] = make_data(val);
    }else{  
        int tm =(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,val);
        else
            update(2*v+1,tm+1,tr,pos,val);
        st[v] = combine(st[2*v],st[2*v+1]);
    }
}

data query(int v,int tl,int tr,int l,int r){
    if(l > r)
        return make_data(-1000000000);
    if(l == tl && r == tr)
        return st[v];
    int tm = (tl+tr)/2;
    return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
}
int main(){
    fastio;
    cin>>n;
    for(int i =1;i<=n;i++)
        cin>>arr[i];

    build(1,1,n);
    cin>>m;
    while(m--){
        cin>>op>>a>>b;
        if(op == 0){
            update(1,1,n,a,b);
        }else{
            data res = query(1,1,n,a,b);
            cout<<res.ans<<endl;
        }
    }    
    


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
