#include <bits/stdc++.h>

/*
    Least common multiple arises when we want to compute the simultaneous periodicity
    of two distinct periodic events.

    When is the next year (after 2000) that the presidential election (which happens every 4 years)
    will coincide with census (which happens every 10 years)?
    The events coincide every twenty years, because lcm(4, 10) = 20.
*/

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d\n", lcm(a, b));

    /*
        For 3 numbers (a, b and c)
        lcm(a,b,c) = lcm(lcm(a,b),c)
    */

    return 0;
}
