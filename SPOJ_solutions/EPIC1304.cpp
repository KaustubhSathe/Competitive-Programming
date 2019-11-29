#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> adj[30];
int color[30];
set<char> ans;

void dfs(int u,string s){
	color[u] = 1;
	for(auto to : adj[u]){
		if(color[to] == 0){
			string temp = s;
			temp += (char)(to + 'A');
			dfs(to,temp);
		}else if(color[to] == 1){
			int itr = s.length()-1;
			while(s[itr] != (char)(to+'A')){
				ans.insert(s[itr]);
				itr--;
			}
			ans.insert(s[itr]);
		}
	}
	color[u] = 2;
}
int main(){
	while(cin>>s){
		adj[s[0]-'A'].push_back(s[2] - 'A');
	}
	memset(color,0,sizeof(color));
	for(int i =0;i<26;i++){
		if(color[i] == 0){
			string str = ""; 
			str += (char)(i + 'A');
			dfs(i,str);
		}
	}
	for(auto itr : ans)
		cout<<itr;


}