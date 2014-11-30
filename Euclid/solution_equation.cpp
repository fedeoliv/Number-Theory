#include <bits/stdc++.h>

/*
    Given values of a, b and c. Verify if there is at least one solution for this equation.
    Equation: a*x + b*x = c

    If c is divisible by the common divisor of a and b, the solution is possible.
    Otherwise, the solution is impossible.
*/
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(c % gcd(a, b) == 0) printf("Solution possible.\n");
    else printf("Solution impossible");

    /*
        For equation: a*x + b*y + c*z = d

        if(d % gcd(gcd(a, b), c) == 0) printf("Solution possible.\n");
        else printf("Solution impossible");

        For equation: a*x + b*y + c*z + d*w = e

        if(e % gcd(gcd(gcd(a, b), c), d) == 0) printf("Solution possible.\n");
        else printf("Solution impossible");
    */

    return 0;
}
