#include<bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;

/*---------------------------------------------------START-CODE------------------------------------------------------*/

bool isPrime(vector<int> v){
    int n = v[0]*1000 + v[1]*100 + v[2]*10 + v[3]*1;
    for(int i =2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

vector<int> vectorize(int n){
    vector<int> ans;
    while(n>0){
        ans.pb(n%10);
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int BFS(int s,int d){
    if(s == d)
        return 0;

    vector<int> start = vectorize(s);
    vector<int> dest  = vectorize(d);

    queue<vector<int>> q;
    map<vector<int>,bool> visited;
    map<vector<int>,int> distance;

    for(int i = 1000;i<=9999;i++){
        visited[vectorize(i)] = false;
        distance[vectorize(i)] = 10000;
    }
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()){
        vector<int> top = q.front();
        q.pop();
        vector<int> temp;
        
        for(int i = 3;i>0;i--){
            temp = top;
            for(int j = 0;j<10;j++){
                temp[i] = j;
                if(isPrime(temp) && !visited[temp]){
                    visited[temp] = true;
                    distance[temp] = distance[top] + 1;
                    q.push(temp);
                }
            }
        }

        temp = top;
        for(int j = 1;j<10;j++){
            temp[0] = j;
            if(isPrime(temp) && !visited[temp]){
                visited[temp] = true;
                distance[temp] = distance[top] + 1;
                q.push(temp);
            }
        }

    }
    

    return distance[dest];
    
    

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,s,d;
    cin>>t;
    while(t--){
        cin>>s>>d;
        int ans = BFS(s,d);
        cout<<ans<<endl;
    }
    
    
}
