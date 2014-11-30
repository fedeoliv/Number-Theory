#include <bits/stdc++.h>
#define YEAR 2014

int main() {
    int m, n, day = 0; /* m = day of the week, n = number of years */
    int leap = 366 % 7;
    int noleap = 365 % 7;

    scanf("%d %d", &m, &n);

    for(int i = 1; i <= n; i++) {
        if(((YEAR + i) % 4) == 0) day += leap;
        else day += noleap;
    }

    printf("%d\n", day + m);
    return 0;
}
