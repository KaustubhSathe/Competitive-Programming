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
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string s;

int main(){
    fastio;
    int tc;
    cin>>tc;
    while(tc--){
        cin>>s;
        vector<int> z = z_function(s);
        z[0] = s.length();
        int ret = z[0];
        for(int i = 0;i<z.size();i++){
            if(z[i] == 0)continue;
            bool flag = true;
            for(int j = i;j>=0;j -= z[i]){
                if(j - z[i] < 0 && j != 0){
                    flag = false;
                    break;
                }
                if(j - z[i] >=0 && z[j - z[i]] != z[j] + z[i]){
                    flag = false;
                    break;
                }
            }

            for(int j = i;j<z.size();j += z[i]){
                if(j + z[i] > z.size() && j != z.size()-1){
                    flag = false;
                    break;
                }

                if(j + z[i]<z.size() && z[j + z[i]] != z[j] - z[i]){
                    flag = false;
                    break;
                }
            }

            if(flag)
                ret = min(ret,z[i]);
        }
        cout<<ret<<endl;
        if(tc != 0)
            cout<<endl;
    }        
    return 0;
}
