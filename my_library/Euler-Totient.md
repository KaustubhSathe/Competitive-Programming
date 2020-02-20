## Euler Totient Function
-----------------------------------------------------
#### Properties
 - 

-----------------------------------------------------
**Ways to calculate $\varphi(n)$** 

1. For single input $n$ complexity $O(\sqrt{n})\;$: 
```cpp
long long int phi(long long int n) {
    long long int result = n;
    for (long long int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
```
2. For calculating $\varphi(n)$ for each $n$ upto $1e7$ we use sieve techinque.
```cpp
const int MAXN = 1e7+5;
long long int phi[MAXN];memset(phi,0,sizeof(phi));
phi[1] = 1;
for(int i = 2;i<=MAXN;i++){
    if(phi[i] == 0){
        phi[i] = i-1;
        for(int j = 2*i;j<=MAXN;j+=i){
            if(phi[j] == 0)phi[j] = j;
            phi[j] /= i;
            phi[j] *= (i-1);
        }
    }
}
```



-----------------------------------------------------
### Problems
**1. https://codeforces.com/problemset/problem/906/D**


   