#include <bits/stdc++.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    return 0;
}
