#include <bits/stdc++.h>

/*
    A prime number is an integer p > 1 which is only divisible by 1 and itself.
    The first ten prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23, and 27.
    Prime numbers are important because of the fundamental theorem of arithmetic,
    which every integer can be expressed in only one way as the product of primes.
*/

void prime_factorization(long x) {
    long i; /* counter */
    long c; /* remaining product to factor */

    c = x;

    while ((c % 2) == 0) {
        printf("%ld ", 2L);
        c = c / 2;
    }

    i = 3;

    while (i <= (sqrt(c)+1)) {
        if ((c % i) == 0) {
            printf("%ld ",i);
            c = c / i;
        } else i = i + 2;
    }

    if (c > 1) printf("%ld ",c);
}

int main() {
    prime_factorization(105);
    return 0;
}
