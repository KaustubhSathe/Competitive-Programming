#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llong;
 
const llong MOD = 1000000007LL;
 
llong FastPow(llong k, llong p)
{
    if (p == 0)
        return 1LL;
 
    llong P = FastPow(k, p/2LL);
    P = (P * P) % MOD;
 
    if (p % 2 == 1)
        P = (P * k) % MOD;
 
    return P;
}
 
llong Inv(llong x)
{
    return FastPow(x, MOD-2);
}
 
llong facts[100111];
llong invFacts[100111];
 
int t;
int n;
int x[200111];
vector<int> reps;
 
int main()
{
    int test;
    int i,j;
 
    facts[0] = 1LL;
    invFacts[0] = 1LL;
    for (i=1;i<=100000;i++)
    {
        facts[i] = (facts[i-1] * i) % MOD;
        invFacts[i] = Inv(facts[i]);
    }
 
    scanf("%d",&t);
 
    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);
 
        for (i=1;i<=2*n;i++)
        {
            scanf("%d",&x[i]);
        }
 
        x[2*n+1] = 0;
        x[2*n+2] = 0;
 
        sort(x+1,x+1+2*n+2);
 
        llong ans = facts[n-1];
        pair<int,int> cur;
        int skip0s = 2;
        bool first = true;
        llong swappableCoef = 1;
        reps.clear();
 
        int sum = x[1] + x[2*n+2];
        for (i=1;i<=n+1;i++)
        {
            int num1 = x[i];
            int num2 = x[2*n+3-i];
 
            if (num1 + num2 != sum)
                ans = 0;
 
            if (num1 == 0 || num2 == 0)
            {
                if (skip0s > 0)
                {
                    skip0s--;
                    continue;
                }
            }
 
            if (first)
                cur = make_pair(num1, num2);
 
            if (first || make_pair(num1, num2) != cur)
            {
                cur = make_pair(num1, num2);
                reps.push_back(1);
            }
            else
            {
                reps.back()++;
            }
 
            if (first)
                first = false;
 
            if (num1 != num2)
            {
                swappableCoef *= 2LL;
                swappableCoef %= MOD;
            }
        }
 
        if (skip0s > 0)
            ans = 0;
 
        for (i=0;i<reps.size();i++)
        {
            ans *= invFacts[ reps[i] ];
            if (ans >= MOD)
                ans %= MOD;
        }
 
        ans *= swappableCoef;
        ans %= MOD;
 
        printf("%lld\n",ans);
    }
 
    return 0;
}