#include<bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;



/*---------------------------------------------------START-CODE------------------------------------------------------*/
char plot[101][101];
bool visited[101][101];
int r,c;
int number_of_stars;
bool isValid(int x,int y,int r,int c){
    return (x>=0 && x <r && y>=0 && y<c);
}
bool eight_directions_clear(int x,int y,int r,int c){
    if(isValid(x,y+1,r,c) && plot[x][y+1] == '*'){
        return false;
    }
    if(isValid(x,y-1,r,c) && plot[x][y-1] == '*'){
        return false;
    }
    if(isValid(x+1,y,r,c) && plot[x+1][y] == '*'){
        return false;
    }
    if(isValid(x-1,y,r,c) && plot[x-1][y] == '*'){
        return false;
    }
    if(isValid(x+1,y+1,r,c) && plot[x+1][y+1] == '*'){
        return false;
    }
    if(isValid(x+1,y-1,r,c) && plot[x+1][y-1] == '*'){
        return false;
    }
    if(isValid(x-1,y+1,r,c) && plot[x-1][y+1] == '*'){
        return false;
    }
    if(isValid(x-1,y-1,r,c) && plot[x-1][y-1] == '*'){
        return false;
    }

    return true;
}
void DFS(int x,int y,int r,int c){
    if(x < 0 || x >= r || y<0 || y>=c || visited[x][y]){
        return;
    }
    if(eight_directions_clear(x,y,r,c)){
        number_of_stars += 1;
        visited[x][y] = true;
    }else{
        visited[x][y] = true;
        DFS(x,y+1,r,c);
        DFS(x,y-1,r,c);
        DFS(x+1,y,r,c);
        DFS(x-1,y,r,c);
        DFS(x+1,y+1,r,c);
        DFS(x+1,y-1,r,c);
        DFS(x-1,y+1,r,c);
        DFS(x-1,y-1,r,c);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while((cin>>r>>c) && r != 0 && c != 0){
        memset(visited,false,sizeof(visited));
        number_of_stars = 0;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                cin>>plot[i][j];
                if(plot[i][j] == '.'){
                    visited[i][j] = true;
                }
            }
        }

        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(!visited[i][j]){
                    DFS(i,j,r,c);
                }
            }
        }

        cout<<number_of_stars<<endl;





    }
    
}
