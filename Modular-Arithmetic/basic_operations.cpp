#include <bits/stdc++.h>

/* Basic operations to avoid using big numbers. */

/*
    What is (x + y) mod n? We can simplify this to:
    ((x mod n) + (y mod n)) mod n.

    How much small change will I have if given $123.45 by my mother and $94.67 by my father?
    (12345 mod 100) + (9467 mod 100) = (45 + 67) mod 100 = 12 mod 100
*/

int add(int a, int b, int n) {
    return ((a % n) + (b % n)) % n;
}

/*
    Subtraction is just addition with negative values.

    How much small change will I have after spending $52.53?
    (12 mod 100) − (53 mod 100) = −41 mod 100 = 59 mod 100

    Notice how we can convert a negative number mod n to a positive number by
    adding a multiple of n to it.
*/
int sub(int a, int b, int n) {
    return (((a % n) - (b % n)) % n + n) % n;
}

/*
    Since multiplication is just repeated addition:
    xy mod n = (x mod n)(y mod n) mod n.

    How much change will you have if you earn $17.28 per hour for 2,143 hours?
    (1728 * 2143) mod 100 = (28 mod 100) × (43 mod 100) = 4 mod 100
*/

int mult(int a, int b, int n) {
    return ((a % n) * (b % n)) % n;
}

/*  Since exponentiation is the quickest way to produce really large integers, this is
    where modular arithmetic really proves its worth. */
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
    int a, b, n; /* n = modullo */

    //scanf("%d %d %d", &a, &b, &n);
    printf("Addition: %d\n", exp_mod(1728, 2143, 100));

    return 0;
}
