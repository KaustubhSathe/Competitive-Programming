#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 100000000000000
#define vi vector<int>
#define vpii vector<pii>
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/*---------------------------------------------------START-CODE------------------------------------------------------*/
int n,m,k;
lli p[105][105];
lli dp[105][105];
lli kadane[105];
pair<int,lli> solve(){
    int area= -1;
    lli sum =0ll;
    int len = 0;int leftmost = 1;
    map<int,lli> cost;
    for(int i =0;i<=10000;i++)
        cost[i] = INF;
    
    
    for(int l = 1;l<=m;l++){
        for(int r = l;r<=m;r++){
            len = 0;leftmost = 1;sum = 0ll;          
            for(int i =1;i<=n;i++){
                kadane[i] = dp[i][r] - dp[i][l-1];
                //cout<<kadane[i]<<" "<<l<<" "<<r<<endl;
            }
            //cout<<l<<" "<<r<<endl;   
            for(int i = 1;i<=n;i++){
                sum += kadane[i];
                len++;
                while(sum > (lli)k){
                    sum -= kadane[leftmost];
                    len--;
                    leftmost++;
                }
                if(area <= (len)*(r-l+1)){
                    area = (len)*(r-l+1);
                    //cout<<area<<endl;
                    //cout<<l<<" "<<r<<endl;
                    cost[area] = min(cost[area],sum);
                }
            }
        }
    }
    return mp(area,cost[area]);
}
int main(){
    fastio;
    int tc;
    cin>>tc;
    for(int t = 1;t<=tc;t++){
        cin>>n>>m>>k;
        for(int i =0;i<105;i++)
            for(int j =0;j<105;j++)
                dp[i][j] = 0ll;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>p[i][j];
                dp[i][j] = p[i][j] + dp[i][j-1];
            }
        }
            

        pair<int,lli> ans = solve();
        cout<<"Case #"<<t<<": "<<ans.first<<" "<<ans.second<<endl;
    }
    


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
