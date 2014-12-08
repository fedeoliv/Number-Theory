#include <bits/stdc++.h>
#define LIMIT 10000000
#define ULL unsigned long long

/*
    Problem: UVa - Smith number
    The sum of the digits of that number was equal to the sum of the digits of
    the prime factors of that number. Got it? Smith’s telephone number was 493-7775. This
    number can be written as the product of its prime factors in the following way:
    4937775 = 3*5*5*65837

    The sum of all digits of the telephone number is 4 + 9 + 3 + 7 + 7 + 7 + 5 = 42, and
    the sum of the digits of its prime factors is equally 3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42.
    Wilansky named this type of number after his brother-in-law: the Smith numbers.

    As this property is true for every prime number, Wilansky excluded them from the
    definition. Other Smith numbers include 6,036 and 9,985.
    Wilansky was not able to find a Smith number which was larger than the telephone
    number of his brother-in-law.

    Input:      Output:
    1           4937775
    4937774
*/

bool is_prime(ULL n) {
    bool prime = true;

    for(ULL i = 3; i <= sqrt(n); i += 2) {
        if ((n % i) == 0) {
            prime = false;
            break;
        }
    }

    if ((n % 2 !=0 && prime && n > 2) || n == 2) return true;
    else return false;
}

/* Returns the sum of all digits of a given number. */
int sum_digits(ULL n) {
    int s = 0;

    while (n > 0) {
        s += n % 10;
        n /= 10;
    }

    return s;
}

/* Based on the prime factorization algorithm. */
bool is_smith(ULL x) {
    ULL i; /* counter */
    ULL c = x; /* remaining product to factor */
    ULL s = 0; /* sum of the prime factors */

    /* factoring by 2 */
    while ((c % 2) == 0) {
        s += 2;
        c = c / 2;
    }

    i = 3;

    while (i <= (sqrt(c) + 1)) {
        if ((c % i) == 0) {
            s += sum_digits(i);
            c = c / i;
        } else i += 2;
    }

    if (c > 1) s += sum_digits(c);
    if (s == sum_digits(x) && !is_prime(x)) return true;
    else return false;
}

int main() {
    ULL t, n;

    scanf("%llu", &t);

    while(t--) {
        scanf("%llu", &n);

        while(!is_smith(++n)){}
        printf("%llu\n", n);
    }

    return 0;
}
