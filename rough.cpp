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

void printState(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
    }
}
void init(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            board[i][j] = (j%3 + 1) + (i%3);
        }
    }
}

int main(){
    init();
    cout<<"-------------------------------Tic-Tac-Toe-------------------------------"<<endl;cout<<endl;

    // while(true){
    //     printState();
    // }
    printState();


    
    return 0;
}

