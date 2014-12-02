#include <bits/stdc++.h>
#define LIMIT 65000
#define ULL unsigned long long int
using namespace std;

/*
    Problem: UVa - Carmichael Numbers
    Given the equation a^n mod n = a.
    Certain composite numbers (non-primes) pass the Fermat test with every number smaller than themselves.
    These numbers are called Carmichael numbers.
    Write a program to test whether a given integer is a Carmichael number.
*/
/*
    Solution:
    Generate an array for all prime numbers and other fo
    For equation a^n mod n = a, we need to use exponential modular (exp_mod).

    Verifying carmichael numbers:
    - n must be non-prime.
    - All values <= n must solve the equation (exp_mod(i, n, n) = i).

*/
bitset<LIMIT> bs;
bool is_prime[LIMIT], is_carmichael[LIMIT];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;

    for(ULL i = 2; i <= LIMIT + 1; i++) {
        if(bs[i]) {
            for(ULL j = i * i; j <= LIMIT + 1; j += i) bs[j] = 0;
            is_prime[i] = true;
        }
    }
}

int exp_mod( int a, int b, int n) {
    long long x = a, y = 1;

    while(b) {
        if( b & 1 ) y = y * x % n;
        x = x * x % n;
        b >>= 1;
    }

    return y;
}

bool carmichael(int n) {
    if(is_prime[n]) return false;

    for(int i = 2; i < n; i++)
        if(exp_mod(i, n, n) != i) return false;
    return true;
}

void init() {
    sieve();

    for(int i = 2; i <= LIMIT; i++)
        is_carmichael[i] = carmichael(i);
}

int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    init();

    while(true) {
        scanf("%d", &n);

        if(n == 0) break;
        if(is_carmichael[n]) printf("The number %d is a Carmichael number.\n", n);
        else printf("%d is normal.\n", n);
    }
}
