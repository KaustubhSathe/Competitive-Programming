#include<bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;



/*---------------------------------------------------START-CODE------------------------------------------------------*/
bool myfunction(pair<int,char> a,pair<int,char> b){
    if(a.first == b.first){
        return (((-1)*(int)a.second)<((-1)*(int)b.second)) ;
    }else{
        return (a.first<b.first);
    }
}

int n,m;
char plot[51][51];
bool visited[51][51];
vector<pair<int,char>> output;
int my_count;
char current_char;
void DFS(int x,int y,int n,int m){
    if(x < 0 || y < 0 || x >=n || y >= m || visited[x][y])
        return;

    if(plot[x][y] == current_char){
        my_count++;
        visited[x][y] = true;
        DFS(x+1,y,n,m);
        DFS(x-1,y,n,m);
        DFS(x,y+1,n,m);
        DFS(x,y-1,n,m);
    }
    
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int problem_number = 1;
    while((cin>>n>>m) && n != 0 && m != 0){
        memset(visited,false,sizeof(visited));
        output.clear();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>plot[i][j];
                if(plot[i][j] == '.'){
                    visited[i][j] = true;
                }
            }
                
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j]){
                    current_char = plot[i][j];
                    my_count =0;
                    DFS(i,j,n,m);
                    output.pb(mp(my_count,current_char));
                }
            }
        }
        sort(output.begin(),output.end(),myfunction);
        reverse(output.begin(),output.end());
        printf("Problem %d:\n",problem_number++);
        for(int i = 0;i<output.size();i++){
            printf("%c %d\n",output[i].second,output[i].first);
        }


            
    }
    
}
