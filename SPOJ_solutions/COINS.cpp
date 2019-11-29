#include <iostream>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

map <int,long long>state;

long long int f(int n){
if(n == 0)
    return 0;

if(state[n] != 0)
    return state[n];


long long temp = f(n/2) + f(n/3) + f(n/4);

if(temp>n)
    state[n] = temp;
else
    state[n] = n;




return state[n];
}

int main() {
	// your code goes here
	int n;
	
	while(scanf("%d",&n)==1) printf("%lld\n",f(n));
	return 0;
}
