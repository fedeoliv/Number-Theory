#include <bits/stdc++.h>

/*
    The Chinese Remainder theorem will determine a number n that when divided by
    some given divisors leaves given remainders.

    For example, what is the lowest number n that when divided by 3
    leaves a remainder of 2, and when divided by 5 leaves a remainder of 3?
*/

int gcd(int a, int b, int *x, int *y) {
    int x1,y1; /* previous coefficients */
    int g; /* value of gcd(p,q) */

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
    //freopen("input.txt", "r", stdin);
    int a1, m1, a2, m2, b1, b2, x, n;

    scanf("%d %d %d %d", &a1, &m1, &a2, &m2);

    gcd(m1, m2, &b1, &b2);

    x = a1*b2*m2 + a2*b1*m1;
    n = m1 * m2;

    if(x < 0) x = (x % n + n) % n;
    else x = x % n;

    printf("%d\n", x);
    return 0;
}
