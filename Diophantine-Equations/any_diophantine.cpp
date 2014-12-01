#include <bits/stdc++.h>

#define MAX_VAR 5

int gcd(int a, int b, int *s, int *t) {
    int r, r1, r2, a1, a2, b1, b2, q;
    int A = a;
    int B = b;

    /* unnecessary if a, b >= 0 */
    if (a < 0) {
        r = gcd(-a, b, s, t);
        *s *= -1;
        return r;
    }

    if (b < 0) {
        r = gcd(a, -b, s, t);
        *t *= -1;
        return r;
    }

    a1 = b2 = 1;
    a2 = b1 = 0;

    while (b) {
        assert(a1*A + a2*B == a);
        q = a / b;
        r = a % b;
        r1 = a1 - q*b1;
        r2 = a2 - q*b2;
        a = b;
        a1 = b1;
        a2 = b2;
        b = r;
        b1 = r1;
        b2 = r2;
    }

    *s = a1;
    *t = a2;
    assert(a >= 0);
    return a;
}

/*
 * Given:  Coefficients in a[]
 *         number of variables in numV
 *
 * Returns:gcd of (a[0],...,a[numV-1]) as a return value
 *         specific solution in sol[]
 *         basis vectors for homogeneous solutions in bas[0],...,bas[numV-2]
 */
int gcd_solve(int a[MAX_VAR], int numV,
            int sol[MAX_VAR], int bas[MAX_VAR-1][MAX_VAR]) {
    int ret, d, v;

    if(numV == 2) {
        ret = gcd(a[0], a[1], &sol[0], &sol[1]);
        bas[0][0] = a[1]/ret;
        bas[0][1] = -a[0]/ret;
    } else if(numV > 2) {
        d = gcd_solve(a, numV-1, sol, bas);
        ret = gcd(d, a[numV-1], &v, &sol[numV-1]);

        for(int i = 0; i < numV-1; i++) {
            bas[numV-2][i] = a[numV-1]/ret * sol[i];
            sol[i] *= v;
        }

        bas[numV-2][numV-1] = -d/ret;
    } else printf("Invalid number of variables.\n");

    return ret;
}

/*
 * Solves the diophantine equation
 *   a[0]*x_0 + . . . + a[numV-1]*x_{numV-1} = c
 * provided a solution exists.
 *
 * Given:  Coefficients in a[] (all must be non-zero)
 *         number of variables in numV
 *         RHS of equation, the constant c
 *
 * Returns:1 if a solution was found, 0 otherwise.
 *         specific solution in sol[]
 *         basis vectors for homogeneous solutions in bas[0],...,bas[numV-2]
 */
int diophantine(int a[MAX_VAR], int numV, int c,
                int sol[MAX_VAR], int bas[MAX_VAR-1][MAX_VAR]) {
    int d, q;

    for(int i = 0; i < numV; i++) assert(a[i] != 0);

    for(int i = 0; i < numV-1; i++)
        for(int j = 0; j < numV; j++) bas[i][j] = 0;

    d = gcd_solve(a, numV, sol, bas);

    if(c % d == 0) {
        q = c/d;
        for(int i = 0; i < numV; i++) sol[i] *= q;
        return 1;
    } else return 0;
}


int main() {
    int a[MAX_VAR];
    int sol[MAX_VAR];
    int bas[MAX_VAR-1][MAX_VAR];
    int numV = 3; /* number of variables */
    int c; /* constant representing the result of the equation */

    //scanf("%d",&numV);

    for(int i = 0; i < numV; i++) scanf("%d", &a[i]);
    scanf("%d", &c);

    if(diophantine(a, numV, c, sol, bas)) {
        for(int i = 0; i < numV; i++) printf("%d ", sol[i]);

        printf("\n\nSum of coefficients equals to zero:\n");

        for(int j = 0; j < numV-1; j++) {
            for(int i = 0; i < numV; i++) printf("%d ", bas[j][i]);
            printf("\n");
        }
    } else printf("Solution impossible.\n");

    return 0;
}
