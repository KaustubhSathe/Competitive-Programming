#include <iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

void addEdge(vector<vector<int>>& adj,int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int BFS(vector<vector<int>> adj,int s,int d){
    list<int> myqueue;
    int V = adj.size();
    bool visited[V];
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    int level[V];
    memset(level,10000,sizeof(level));
    int pred[V];
    level[s] = 0;
    pred[s] = -1;
    myqueue.push_back(s);
    while(!myqueue.empty()){
        int top = myqueue.front();
        myqueue.pop_front();
        for(int i =0;i<adj[top].size();i++){
            if(!visited[adj[top][i]]){
                visited[adj[top][i]] = true;
                level[adj[top][i]] = level[top] +1;
                pred[adj[top][i]] = top;
                myqueue.push_back(adj[top][i]);
            }
        }
    }
    //int crawl = d;
    //while(pred[crawl] != -1){
    //    cout<<crawl<<"<-";
    //    crawl = pred[crawl];
    //}
    //cout<<crawl;
    //cout<<"\nLevel of "<<d<<" = "<<level[d];
    return level[d];


}
int main(){
    int testcase = 1;
    int x,j,n,i=1;
    vector<vector<int>> adj(21);
   while(scanf("%d" , &x) != EOF){
       for(int k = 0;k<x;k++){
           cin>>j;
           addEdge(adj,i,j);
       }
       i++;
       if(i==20){
        cin>>n;
        pair<int,int> arr[n];
        for(int i = 0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
        }
        cout<<"Test Set #"<<testcase++<<endl;
        for(int i =0;i<n;i++){
            if(arr[i].first/10 ==0 && arr[i].second/10 == 0){
                cout<<" "<<arr[i].first<<" to  "<<arr[i].second<<": "<<BFS(adj,arr[i].first,arr[i].second)<<endl;
            }else if(arr[i].first/10 ==0 && arr[i].second/10 > 0){
                cout<<" "<<arr[i].first<<" to "<<arr[i].second<<": "<<BFS(adj,arr[i].first,arr[i].second)<<endl;
            }else if(arr[i].first/10 >0 && arr[i].second/10 == 0){
                cout<<arr[i].first<<" to  "<<arr[i].second<<": "<<BFS(adj,arr[i].first,arr[i].second)<<endl;                
            }else{
                cout<<arr[i].first<<" to "<<arr[i].second<<": "<<BFS(adj,arr[i].first,arr[i].second)<<endl;                
            }
        
        }
        cout<<""<<endl;
        i =1;
        for (int i = 0; i < 21; ++i)

      {

        adj[i].clear();

      }
       }
   }
   
   
    

   

   

}
