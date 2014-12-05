#include <bits/stdc++.h>
#define LL long long int

/*
    From Euclid, it is known that for any positive integers A and B there exist such
    integers X and Y that AX + BY = D, where D is the greatest common divisor of A
    and B. The problem is to find the corresponding X, Y , and D for a given A and B.
*/

LL gcd(LL a, LL b, LL *x, LL *y) {
    LL x1,y1; /* previous coefficients */
    LL g; /* value of gcd(p,q) */

    if (b > a) return(gcd(b,a,y,x));

    if (b == 0) {
        *x = 1;
        *y = 0;
        return(a);
    }

    g = gcd(b, a%b, &x1, &y1);
    *x = y1;
    *y = (x1 - floor(a/b)*y1);

    return g;
}

int main() {
    LL a, b, x, y, d;

    while(scanf("%lld %lld", &a, &b) != EOF) {
        d = gcd(a, b, &x, &y);
        printf("%lld %lld %lld\n", x, y, d);
    }

    return 0;
}
