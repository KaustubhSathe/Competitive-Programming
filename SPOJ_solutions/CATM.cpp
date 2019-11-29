#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
int k;
cin>>k;
while(k--){
    int mousei,mousej,cat1i,cat1j,cat2i,cat2j;
    cin>>mousei>>mousej>>cat1i>>cat1j>>cat2i>>cat2j;
    int d1,d2,d3;
    int flag =0;
    for(int i = 1;i<=m;i++){
        d1 = abs(mousei - 1) + abs(mousej-i);
        d2 = abs(cat1i - 1) + abs(cat1j-i);
        d3 = abs(cat2i - 1) + abs(cat2j-i);
        if(d1<d2 && d1 < d3){
            cout<<"YES"<<endl;
            flag =1;
            break;
        }
    }
    if(flag == 1)
        continue;

    for(int i = 1;i<=m;i++){
        d1 = abs(mousei - n) + abs(mousej-i);
        d2 = abs(cat1i - n) + abs(cat1j-i);
        d3 = abs(cat2i - n) + abs(cat2j-i);
        if(d1<d2 && d1 < d3){
            cout<<"YES"<<endl;
            flag =1;
            break;
        }
    }
    if(flag == 1)
        continue;
    for(int i = 1;i<=n;i++){
        d1 = abs(mousei - i) + abs(mousej-1);
        d2 = abs(cat1i - i) + abs(cat1j-1);
        d3 = abs(cat2i - i) + abs(cat2j-1);
        if(d1<d2 && d1 < d3){
            cout<<"YES"<<endl;
            flag =1;
            break;
        }
    }
    if(flag == 1)
        continue;
    for(int i = 1;i<=n;i++){
        d1 = abs(mousei - i) + abs(mousej-m);
        d2 = abs(cat1i - i) + abs(cat1j-m);
        d3 = abs(cat2i - i) + abs(cat2j-m);
        if(d1<d2 && d1 < d3){
            cout<<"YES"<<endl;
            flag =1;
            break;
        }
    }
    cout<<"NO"<<endl;


}


}
