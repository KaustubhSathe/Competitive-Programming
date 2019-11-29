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

int a,b,len,inp[10];
int dp[10][80][80][2][2];

int dfs(int pos,int even,int odd,int isSmall,int ld){
	if(pos == len)
		return ((even - odd) == 1);

	if(dp[pos][even][odd][isSmall][ld] != -1)
		return dp[pos][even][odd][isSmall][ld];

	int ret = 0;
	for(int i = 0;i<10;i++){
		if(isSmall || i <= inp[pos]){
			if(ld || i>0){
				if((len - 1 - pos)%2 == 0){
					ret += dfs(pos+1,even,odd + i,isSmall || i < inp[pos],1);
				}else{
					ret += dfs(pos+1,even+i,odd,isSmall || i < inp[pos],1);
				}
			}else{
				ret += dfs(pos+1,even,odd,isSmall || i < inp[pos],0);
			}
		}
	} 
	return dp[pos][even][odd][isSmall][ld] = ret;
}
int solve(int num){
	len = 0;
	while(num > 0){
		inp[len++] = num%10;
		num /= 10;
	}
	reverse(inp,inp+len);
	memset(dp,-1,sizeof(dp));
	return dfs(0,0,0,0,0);
}

int main(){
    fastio;
    int tc;
    cin>>tc;
    while(tc--){
    	cin>>a>>b;
    	if(a > b)
    		swap(a,b);

    	int ans = solve(b) - solve(a-1);
    	cout<<ans<<endl;
    }

        
    return 0;
    
}
