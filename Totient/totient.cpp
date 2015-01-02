#include <stdio.h>

/*
    Totient of a positive integer n is defined to be the number of positive integers
    less than or equal to n that are coprime to n.
*/

int phi(int n) {
    int result = n;

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;
    }

    if (n > 1) result -= result / n;
    return result;
}

int main() {
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        printf("%d\n", phi(n));
    }
    return 0;
}
