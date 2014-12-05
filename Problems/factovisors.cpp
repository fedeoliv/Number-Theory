#include <bits/stdc++.h>

/*
    Problem: UVa - Factovisors
    Verify if m divides n!.
*/
/*
    Solution:
    We check each of the prime factors of m to see if n! Has enough prime factors of the same value.
    If so, m can divide n!, Otherwise m can not divide n!.
*/

bool is_factorial_divide (int n, int m) {
    if (m == 0) return false;
    if (n == 0 && m == 1) return true;

    int f = 2, mf = sqrt (m) + 1;

    while(m > n && f < mf) {
        int c = 0;

        while((m % f) == 0) {
            m /= f;
            c++;
        }

        int nf = f;

        while(c > 0 && nf <= n) {
            c -= n / nf;
            nf *= f;
        }

        if(c> 0) return false;
        f++;
    }

    return m <= n;

    /*
    for (int f = 2, mf = sqrt (m) + 1; m > n && f < mf; ++f) {
        int c = 0;
        for (; (m%f) == 0; m /= f, ++c) {}
        for (int nf = f; c> 0 && nf <= n; c -= n / nf, nf *= f) {}
        if (c> 0) return   false;
    }
    return m <= n;
    */
}

int main() {
    //freopen("input.txt", "r", stdin);
    int m, n;

    while(scanf("%d %d", &n, &m) != EOF) {
        if(is_factorial_divide(n, m) == true)
            printf("%d divides %d!\n", m, n);
        else printf("%d does not divide %d!\n", m, n);
    }

   return 0;
}
