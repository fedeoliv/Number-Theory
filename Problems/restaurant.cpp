#include <bits/stdc++.h>

/*
    Martha is interviewing at Subway. One of the rounds of the interview requires her to cut a bread
    of size lxb into smaller identical pieces such that each piece is a square having maximum possible
    side length with no left over piece of bread. Return an integer that denotes the number of squares of maximum size.
*/

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t, l, b, g;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &l, &b);

        g = gcd(l, b);
        printf("%d\n", (l/g) * (b/g));
    }

    return 0;
}
