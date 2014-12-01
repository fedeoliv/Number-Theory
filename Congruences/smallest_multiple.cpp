#include <bits/stdc++.h>
#define ull unsigned long long int

/*  Find the smallest multiple of 10 which has remainder 2 when divided
    by 3, and remainder 3 when divided by 7.

    We are looking for a number which satisfies the congruences,
    x ≡ 2 mod 3 and x ≡ 3 mod 7. Since, 2, 3, 5 and 7 are all
    relatively prime in pairs (less than 10), the Chinese Remainder Theorem
    tells us that there is a unique solution modulo 210(= 2*3*5*7).

    Input: 2 inputs, multiple of 10, 2 mod 3, 3 mod 7
    2 10
    2 3
    3 7

    Output:80
*/

int mul_inv(int a, int b ) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;

    if( b == 1 ) return 1;
    while( a > 1 ) {
        q = a / b;
        t = b;  b  = a % b; a  = t;
        t = x0; x0 = x1 - q * x0; x1 = t;
    }

    if( x1 < 0 ) x1 += b0;
    return x1;
}

int product_primes(int n) {
    /*  Using a single array, fill it with 1s,
        and then put 0s on all the numbers that are not primes. */
    int m = 1; /* modulo = product of primes*/
    int *primes;
    int z = 1;

    primes = (int*) malloc(sizeof(int)*n);

    for (ull i = 2; i < n; i++) primes[i] = 1;

    for (ull i = 2; i < n; i++)
        if (primes[i])
            for (ull j = i; i*j < n; j++) primes[i*j] = 0;

    for (ull i = 2; i < n; i++)
        //if (primes[i]) printf("%llu ", i);
        if(primes[i]) m *= i;

    return m;
}

int main(){
    freopen("input.txt", "r", stdin);

    int n, k; /* k = smallest multiple of k */
    scanf("%d %d", &n, &k);
    //scanf("%d", &n);
    int c[2*n]; /* congruences: 1 for remainder and 1 for divisor */
    int m[n]; /* values of each iteration */
    int mod = product_primes(k);
    //int mod = 1;
    int x = 0;

    for(int i = 0; i < 2*n; i+= 2) {
        scanf("%d %d", &c[i], &c[i+1]);
        //mod = mod * c[i+1];
    }

    for(int i = 0; i < 2*n; i+= 2) {
        int p = mod/c[i+1];
        printf("%d * %d * %d\n", c[i], p, mul_inv(p, c[i+1]));
        x += c[i] * p * mul_inv(p, c[i+1]);
    }

    x = x % mod;
    printf("%d\n", x);

    return 0;
}
