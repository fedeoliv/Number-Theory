#include <bits/stdc++.h>
#define MOD 10

/*
    What is the last digit of 2^100 ? Sure we can use infinite precision arithmetic
    and look at the last digit, but why? We can do this computation by hand.
    What we really want to know is what 2^100 mod 10 is. By doing repeated squaring,
    and taking the remainder mod 10 at each step we make progress very quickly.
*/

int exp_mod( int a, int b, int n) {
    long long x = a, y = 1;

    while(b) {
        if( b & 1 ) y = y * x % n;
        x = x * x % n;
        b >>= 1;
    }

    return y;
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("Last digit: %d\n", exp_mod(a, b, MOD));
    printf("%d^%d = %.f\n", a, b, pow(a, b) );
    return 0;
}
