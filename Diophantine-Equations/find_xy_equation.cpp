#include <bits/stdc++.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

bool is_valid(int a, int b, int c) {
    /* Verifying if the equation is possible to be solved. */
    if(c % gcd(a, b) == 0) return true;
    return false;
}

void solve_xy(int a, int b, int c, int& x, int& y) {
    /*
        Solves ax + by = c, with x and y integers.
        Assumes equation solvable and both a and b non-zero
    */
    int x_up = c / a;  /* start value for upward search */
    int y_up = (c - a * x_up) / b;
    int x_down = x_up - 1;  /* start value for downward search */
    int y_down = (c - a * x_down) / b;

    while (true) {
        if ((a * x_up) + (b * y_up) == c) {
            x = x_up;
            y = y_up;
            break; /* found an up solution */
        }

        ++x_up;  /* x_up is incremented through the upper half the search space */
        y_up = (c - a * x_up) / b;

        if ((a * x_down) + (b * y_down) == c) {
            x = x_down;
            y = y_down;
            break;   /* found a down solution */
        }

        --x_down; /* x_down is decremented through the lower half the search space */
        y_down = (c - a * x_down) / b;
    }

    return;
}

int main() {
    int a, b, c, x, y;

    scanf("%d %d %d", &a, &b, &c);

    if(is_valid(a, b, c)) {
        solve_xy(a, b, c, x, y);
        printf("x = %d, y = %d", x, y);
    } else printf("Solution impossible.\n");

    return 0;
}
