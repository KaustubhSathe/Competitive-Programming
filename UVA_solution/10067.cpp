#include<map>
#include<utility>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#define MAX 10000
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        map<vector<int>,int> distance;
        map<vector<int>,bool> visited;
        queue<vector<int>> q;
        vector<int> start(4),dest(4);
        for(int i =0;i<4;i++){
            cin>>start[i];
        }
        for(int i =0;i<4;i++){
            cin>>dest[i];
        }
        int n;
        cin>>n;
        vector<int> forbidden[n];
        for(int i =0;i<n;i++){
            for(int j =0;j<4;j++){
                int temp;
                cin>>temp;
                forbidden[i].push_back(temp);
            }
            visited[forbidden[i]] = true;
        }

        distance[start] = 0;
        visited[start] = true;
        q.push(start);
        bool flag = false;
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
             vector<int> child = temp;
            for(int i =0;i<4;i++){
                child[i] += 1;
                child[i] %= 10;
                if(visited[child] == false){
                    q.push(child);
                    visited[child] = true;
                    distance[child] = distance[temp] +1;
                }
                if(child == dest){
                    flag = true;
                    break;
                }
                child = temp;
            }
            if(flag){
                break;
            }
            for(int i =0;i<4;i++){
                child[i] -= 1;
                if(child[i] == -1){
                    child[i] = 9;
                }
                if(visited[child] == false){
                    q.push(child);
                    visited[child] = true;
                    distance[child] = distance[temp] +1;
                }
                if(child == dest){
                    flag = true;
                    break;
                }
                child = temp;
            }
            if(flag){
                break;
            }

        }
        if(flag){
            cout<<distance[dest]<<endl;
        }else{
            cout<<-1<<endl;

        }

       



        


    }


}