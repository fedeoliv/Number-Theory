#include <bits/stdc++.h>
#define LIMIT 10000000
#define ULL unsigned long long

using namespace std;

/*
    Problem: UVa - Summation of Four Primes
    Find a way to express a given integer as the sum of exactly four primes.
*/

/*  Solution:
    If N < 8 is Impossible. There are no possible way to have 4 primes that the sum is less than 8.
    if N is even answer = 2 + 2 + (N - 4). (N - 4) is even so it can be expressed as sum of 2 primes.
    if N is odd answer =  2 + 3 + (N - 5). (N - 5) is even so it can be expressed as sum of 2 primes.

    For 5 primes, for example:
    If N < 10 is Impossible. There are no possible way to have 4 primes that the sum is less than 8.
    If N is even answer = 2 + 2 + 2 + (N - 6). (N - 6) is even so it can be expressed as sum of 2 primes.
    If N is odd answer =  2 + 2 + 3 + (N - 5). (N - 7) is even so it can be expressed as sum of 2 primes.
*/

bitset<LIMIT> bs;
bool primes[LIMIT];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;

    for(ULL i = 2; i <= LIMIT + 1; i++) {
        if(bs[i]) {
            for(ULL j = i * i; j <= LIMIT + 1; j += i) bs[j] = 0;
            primes[i] = true;
        }
    }
}

void get_sum(int n) {
    if(n < 8) printf("Impossible.\n");
    else {
        int remainingSum;

        if(n % 2 == 0) {
            printf("2 2 ");
            remainingSum = n - 4;
        } else {
            printf("2 3 ");
            remainingSum = n - 5;
        }

        int i;

        for (i = 2; i < remainingSum; i++) {
            if(primes[i] && primes[remainingSum-i]) {
                printf("%d %d\n", i, remainingSum - i);
                break;
            }
        }

        if(!(primes[i] && primes[remainingSum-i]))
            printf("Impossible.\n");
    }
}

int main() {
    int n;

    sieve();

    while(scanf("%d", &n) != EOF) {
        get_sum(n);
    }
    return 0;
}
