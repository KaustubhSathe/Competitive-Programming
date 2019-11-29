#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
string s;
cin>>s;

while(s[0] != '0'){
    long long int dp[s.length()+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i<s.length()+1;i++){
        dp[i] = 0;
        char c1 = s[i-2] - '0';
        char c2 = s[i-1] - '0';
        if(c1 == 1 || (c1==2 && c2 <= 6)){
            dp[i] += dp[i-2];
        }
        if(c2 != 0){
            dp[i] += dp[i-1];
        }
    }

    cout<<dp[s.length()]<<endl;






    cin>>s;
}










return 0;

}
