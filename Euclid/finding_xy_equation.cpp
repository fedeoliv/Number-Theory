#include <bits/stdc++.h>

/*
    Find the values of x and y, given the values of a and b.
    a*x + b*y = gcd(a, b)

    Example:
    Given a = 34398, b = 2132. So we have:

    34398*x + 2132*y = gcd(34398, 2132)
    34398*x + 2132*y = 26
    34398*15 + 2132*(−242) = 26
*/

long gcd(long a, long b, long *x, long *y) {
    long x1,y1; /* previous coefficients */
    long g; /* value of gcd(p,q) */

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
    long a, x, b, y, result;

    scanf("%ld %ld", &a, &b);
    result = gcd(a, b, &x, &y);

    printf("x = %ld, y = %ld\n", x, y);
    printf("Equation: %ld * %ld + %ld * %ld = %ld\n", a, x, b, y, result);
    return 0;
}
