#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

string s;
bool isPalindrome(string& t){
    int n = t.length();
    for(int i = 0;i<n/2;i++){
        if(t[i] != t[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    fastio;
    cin>>s;
    for(int j = 0;j<26;j++){
        for(int i = 0;i<=s.length();i++){
            char c = (char)('a'+j);
            string temp = s.substr(0,i) + c + s.substr(i,s.length()-i);
            if(isPalindrome(temp)){
                cout<<temp<<endl;
                return 0;
            }
        }
    }

    cout<<"NA"<<endl;
    
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define fastio  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

string s;
bool isPalindrome(string& t){
    int n = t.length();
    for(int i = 0;i<n/2;i++){
        if(t[i] != t[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    fastio;
    cin>>s;
    for(int j = 0;j<26;j++){
        for(int i = 0;i<=s.length();i++){
            char c = (char)('a'+j);
            string temp = s.substr(0,i) + c + s.substr(i,s.length()-i);
            if(isPalindrome(temp)){
                cout<<temp<<endl;
                return 0;
            }
        }
    }

    cout<<"NA"<<endl;
    
    
    return 0;
}
