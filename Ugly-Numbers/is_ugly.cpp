#include <bits/stdc++.h>

/*  Check if a number is an ugly number.
    We can check only using prime factorization. */

int prime_factorization(long x) {
    long i; /* counter */
    long c; /* remaining product to factor */

    c = x;

    while ((c % 2) == 0) {
        c = c / 2;
    }

    i = 3;

    while (i <= (sqrt(c)+1)) {
        if ((c % i) == 0) {
            if(i != 2 && i != 3 && i != 5) return 0;
            c = c / i;
        } else i = i + 2;
    }

    if (c > 1)
        if(c != 2 && c != 3 && c != 5) return 0;
    return 1;
}

int main() {
    if(prime_factorization(25)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
