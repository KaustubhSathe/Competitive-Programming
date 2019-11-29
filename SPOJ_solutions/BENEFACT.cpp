#include <iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<cstring>
using namespace std;


long long int BFS(vector<vector<pair<int,int>>>& graph,int s){
    list<int> myqueue;
    bool visited[graph.size()];
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    long long int level[graph.size()];
    memset(level,-1,sizeof(level));
    level[s] = 0;
    myqueue.push_back(s);
    while(!myqueue.empty()){
        int top = myqueue.front();
        myqueue.pop_front();
        for(int i =0;i<graph[top].size();i++){
            if(!visited[graph[top][i].first]){
                visited[graph[top][i].first] = true;
                level[graph[top][i].first] = level[top] + graph[top][i].second;
                
                myqueue.push_back(graph[top][i].first);
            }
        }
    }
    return *max_element(level,level+graph.size());


}
 int BFS2(vector<vector<pair<int,int>>>& graph,int s){
    list<int> myqueue;
    bool visited[graph.size()];
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    long long int level[graph.size()];
    memset(level,-1,sizeof(level));
    level[s] = 0;
    myqueue.push_back(s);
    while(!myqueue.empty()){
        int top = myqueue.front();
        myqueue.pop_front();
        for(int i =0;i<graph[top].size();i++){
            if(!visited[graph[top][i].first]){
                visited[graph[top][i].first] = true;
                level[graph[top][i].first] = level[top] + graph[top][i].second;
                
                myqueue.push_back(graph[top][i].first);
            }
        }
    }
    int position = distance(level,find(level,level+graph.size(),*max_element(level,level+graph.size())));
    return position;

}
int main()
{
    
    int t,n,a,b,w;
    cin>>t;
    
    while(t--){
        cin>>n;
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i =0;i<n-1;i++){
            cin>>a>>b>>w;
            graph[a].push_back(make_pair(b,w));
            graph[b].push_back(make_pair(a,w));
        }
        int position = BFS2(graph,1);
        long long int diameter = BFS(graph,position);
        cout<<diameter<<endl;
    }

}
