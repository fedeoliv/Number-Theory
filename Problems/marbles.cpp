#include <bits/stdc++.h>

/*
    Problem: UVa - Marbles
    Type 1: each such box costs c1 dollars and can hold exactly n1 marbles.
    Type 2: each such box costs c2 dollars and can hold exactly n2 marbles.
    Find the minimum cost solution.
*/

/*
    Solution:
    We want to find m1 and m2 that satisfy the equation  n1 * m1 + n2 * m2 = n,
    and give us the minimum cost where cost = c1 * m1 + c2 * m2.

    Using extended Euclid to find gcd(n1,n2) and get m1' and m2', where n1 * m1' + n2 * m2' = gcd(n1,n2)
    to get m1 and m2 multiply both sides by (n/gcd)*m1' = m1*(n/gcd) , m2' = m2'*(n/gcd).

    Now m1 = m1 + (n2/g) * t  and m2 = m2 - (n1/g) * t, where any integer t satisfy the desired equation.
    Now, if gcd can not divide n, then there's no valid solution. Otherwise:

    We want to minimize the cost c = c1 * m1 + c2 * m2. So:

    c = c1 * (m1 + (n2/g) * t) + c2 * (m2 - (n1/g) * t)
    c = c1 * m1 + c2 * m2 + t * (c1 * (n2/g) - c2 * (n1/g)).

    Since c1*m1 + c2*m2 is constant, we want to minimize t * (c1 * (n2/g) - c2 * (n1/g)).
    Remembering that m1 = m1 + (n2/g) * t  and m2 = m2 - (n1/g) * t:

    m1 = m1 + (n2/g) * t ---> (n2/g) * t >= -m1 ---> t >= - m1 * (g/n2)
    m2 = m2 - (n1/g) * t ---> (n1/g) * t >= -m2 ---> t >= -m2 * (g/n1)

    So we have ceil(-m1*g/n2) <= t <= floor(m2*g/n1).
    We can choose the one that has the cheaper cost: ceil(-m1*g/n2) or floor(m2*g/n1).
*/

long x, y;

void ex_gcd(long a, long b, long &d, long &x, long &y) {
    if (b == 0) {
        x = 1, y = 0, d = a;
        return;
    }

    long x1, y1;
    ex_gcd(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

bool is_min_cost(long c1, long n1, long c2, long n2, long n) {
    long gcd, m1, m2;
    ex_gcd(n1, n2, gcd, m1, m2);

    if(n % gcd != 0) return false;

    m1 *= n / gcd, m2 *= n / gcd;
    n2 /= gcd, n1 /= gcd;

    long c = ceil(-(double) m1 / n2), f = floor((double) m2 / n1);

    if (c > f) return false;
    long cost = c1 * n2 - c2 * n1;

    if (cost * c < cost * f) {
        x = m1 + n2 * c;
        y = m2 - n1 * c;
    }
    else {
        x = m1 + n2 * f;
        y = m2 - n1 * f;
    }

    return true;
}

int main() {
    long c1, n1, c2, n2, n;

    while(scanf("%ld", &n) != EOF && n != 0) {
        scanf("%ld %ld %ld %ld", &c1, &n1, &c2, &n2);

        if (is_min_cost(c1, n1, c2, n2, n)) printf("%ld %ld\n", x, y);
        else printf("failed\n");
    }
    return 0;
}
