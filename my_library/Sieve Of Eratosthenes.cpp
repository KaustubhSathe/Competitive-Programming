#include<bits/stdc++.h>
using namespace std;
//O(NlnN)
// std::vector <int> prime;
// bool is_composite[MAXN];

// void sieve (int n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	for (int i = 2; i < n; ++i) {
// 		if (!is_composite[i]) prime.push_back (i);
// 		for (int j = 2; i * j < n; ++j)
// 			is_composite[i * j] = true;
// 	}
// }

// Can use linear sieve but O(NlnlnN) sieve also works fine upto n<=1e6 and also easier to code. 

//O(n) sieve
// std::vector <int> prime;
// bool is_composite[MAXN];
// void sieve (int n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	for (int i = 2; i < n; ++i) {
// 		if (!is_composite[i]) prime.push_back (i);
// 		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
// 			is_composite[i * prime[j]] = true;
// 			if (i % prime[j] == 0) break;
// 		}
// 	}
// }


// Multiplicative functions and linear sieve
// By definition, A function f(x) defined on all positive integers is multiplicative if it satisfies the following condition:
// For every co-prime pair of integers p and q, f(pq) = f(p)f(q).
// It can be shown that f(n) = f(n)f(1). Thus, unless for every integer n we have f(n) = 0, f(1) must be 1. 
// Moreover, two multiplicative functions f(n) and g(n) are identical if and only if for every prime p and non-negative 
// integer k, f(pk) = g(pk) holds true. It can then be implied that for a multiplicative function f(n), it will suffice to
// know about its representation in f(pk).

// It is interesting that the linear sieve can also be used to find out all the values of a multiplicative function f(x) 
// in a given range [1, n]. To do so, we have take a closer look in the code of the linear sieve. As we can see, every 
// integer x will be picked out only once, and we must know one of the following property:

//  - x is prime. In this case, we can determine the value of f(x) directly.
//  - x = ip and p does not divide i. In this case, we know that f(x) = f(i)f(p). Since both f(i) and f(p) are already known before, we can simply multiply them together.
//  - x = ip and p divides i. This is a more complicated case where we have to figure out a relationship between f(i) and f(ip). Fortunately, in most situations, a simple relationship between them exists. For example, in the Euler's totient function, we can easily infer that φ(ip) = pφ(i).

// std::vector <int> prime;
// bool is_composite[MAXN];
// int phi[MAXN];

// void sieve (int n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	phi[1] = 1;
// 	for (int i = 2; i < n; ++i) {
// 		if (!is_composite[i]) {
// 			prime.push_back (i);
// 			phi[i] = i - 1;					//i is prime
// 		}
// 		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
// 			is_composite[i * prime[j]] = true;
// 			if (i % prime[j] == 0) {
// 				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
// 				break;
// 			} else {
// 				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
// 			}
// 		}
// 	}
// }


