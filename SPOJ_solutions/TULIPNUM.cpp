#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define vi vector<int>
#define vpii vector<pii>
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)



/*---------------------------------------------------START-CODE------------------------------------------------------*/
int n,q,a,b;
int arr[100000+5];
int bit[100000+5];
int main(){
    fastio;
    int tc;
    scanf("%d",&tc);
    int number = 1;
    while(tc--){
        scanf("%d %d",&n,&q);
        for(int i =1;i<=n;i++)
            scanf("%d",&arr[i]);

        bit[1] = 1;
        for(int i =2;i<=n;i++){
            if(arr[i] == arr[i-1]){
                bit[i] = bit[i-1];
            }else{
                bit[i] = bit[i-1] + 1;
            }
        }
        printf("Case %d:\n",number++);
        while(q--){
            scanf("%d %d",&a,&b);
            printf("%d\n",bit[b] - bit[a]+1);
        }
    }
    


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
