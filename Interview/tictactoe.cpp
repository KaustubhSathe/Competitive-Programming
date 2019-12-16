#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vc vector<char>
#define vs vector<string>

char board[3][3];
int player,pos;
pii position[15];
void printState(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(board[i][j] != '-'){
                cout<<board[i][j]<<"|";
            }else{
                cout<<(j%3 + 1) + (i%3) + 2*i<<"|";
            }
        }
        cout<<endl;
        for(int j = 0;j<3;j++){
            cout<<"--";
        }
        cout<<endl;
    }
}

void init(){
    position[1] = mp(0,0);
    position[2] = mp(0,1);
    position[3] = mp(0,2);
    position[4] = mp(1,0);
    position[5] = mp(1,1);
    position[6] = mp(1,2);
    position[7] = mp(2,0);
    position[8] = mp(2,1);
    position[9] = mp(2,2);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            board[i][j] = '-';
        }
    }
}

bool ok(){
    for(int i = 0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '-')
            return true;
    }
    for(int i = 0;i<3;i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != '-')
            return true;
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '-')
        return true;
    
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != '-')
        return true;

    
    return false;
}

int main(){
    init();
    cout<<"-------------------------------Tic-Tac-Toe-------------------------------"<<endl;
    while(true){
        cout<<"Player "<<player<<" play your turn : "<<endl;
        printState();
        cin>>pos;
        board[position[pos].ff][position[pos].ss] = (player == 0) ? 'O' : 'X';
        if(ok()){
            printState();
            cout<<"Player "<<player<<" wins"<<endl;
            cout<<"New Game ?? : Yes/No : ";
            string s;cin>>s;
            if(s == "Yes"){
                init();
                cout<<"-------------------------------Tic-Tac-Toe-------------------------------"<<endl;
            }else{
                break;
            }
        }
        player = 1- player;
    }
    


    return 0;
}

