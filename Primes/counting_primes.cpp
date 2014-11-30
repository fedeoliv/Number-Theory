#include <bits/stdc++.h>
#define LIMIT 1000000
#define LL long long
using namespace std;

LL primes[LIMIT];

void sieve() {
    for (LL p = 2; p < LIMIT; p++) {
        if(primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime

        // mark all multiples of prime selected above as non primes
        LL c = 2;
        LL mul = p * c;

        for(; mul < LIMIT;) {
            primes[mul] = -1;
            c++;
            mul = p*c;
        }
    }
}

int count_primes(int n) {
    int c = 0;

    printf("Prime numbers: ");

    for(int i = 0; i < n; i++) {
        if(primes[i] == 1) {
            printf("%d ", i);
            c++;
        }
    }

    printf("\n");
    return c;
}

int main() {
    LL n;
    sieve();

    scanf("%lld", &n);
    printf("Quantity: %d\n", count_primes(n));

    return 0;
}
