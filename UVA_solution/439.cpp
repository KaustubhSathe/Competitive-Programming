#include<bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;

/*---------------------------------------------------START-CODE------------------------------------------------------*/

pair<int,int> make_pii(string s){
    pair<int,int> temp;
    temp.first = abs(s[0] - 'a' + 1);
    temp.second = s[1] - 48;
    return temp;
}
bool isValid(pair<int,int> p){
    return( p.first<=8 && p.first>= 1 && p.second<=8 && p.second>=1);
}


int BFS(pii start,pii dest){
    if(start.first == dest.first && start.second == dest.second)
        return 0;
    
    queue<pii> q;
    map<pii,bool> visited;
    map<pii,int> distance;

    for(int i = 1;i<=8;i++){
        for(int j = 1;j<=8;j++){
            visited[mp(i,j)] = false;
            distance[mp(i,j)] = 1000000;
        }
    }
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        pii temp;
        temp = top;
        temp.first += 2;
        temp.second -= 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.first += 2;
        temp.second += 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.first -= 2;
        temp.second -= 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.first -= 2;
        temp.second += 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.second += 2;
        temp.first -= 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.second += 2;
        temp.first += 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.second -= 2;
        temp.first -= 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        temp = top;
        temp.second -= 2;
        temp.first += 1;
        if(!visited[temp] && isValid(temp)){
            visited[temp] = true;
            distance[temp] = distance[top] +1;
            q.push(temp);
        }
        
        

    }

    return distance[dest];
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    while(cin>>s1>>s2){
        pii start = make_pii(s1);
        pii dest = make_pii(s2);
        //cout<<start.first<<" "<<start.second<<endl;
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<BFS(start,dest)<<" knight moves."<<endl;
    }

    
    
}
