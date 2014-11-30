#include <bits/stdc++.h>

/*
    For example, suppose I know that 4x ≡ 7(mod 9) and 3x ≡ 3(mod 9).
    Then 4x − 3x ≡ 7 − 3(mod 9), so:

    x ≡ 4(mod 9)
*/

int add(int x1, int x2, int y1, int y2, int mod1, int mod2) {
    int x, y;

    x = abs(x1+x2);

    if(mod1 == mod2) y = abs(y1+y2) % mod1;
    else y = abs((y1 % mod1) + (y2 % mod2));

    return y/x;
}

int sub(int x1, int x2, int y1, int y2, int mod1, int mod2) {
    int x, y;

    x = abs(x1-x2);

    if(mod1 == mod2) y = abs(y1-y2) % mod1;
    else y = abs((y1 % mod1) - (y2 % mod2));

    return y/x;
}

int mult(int x1, int x2, int y1, int y2, int mod1, int mod2) {
    int y;

    if(mod1 == mod2) y = (y1*y2) % mod1;
    else y = (y1 % mod1) * (y2 % mod2);

    return y/(x1*x2);
}

int main() {
    int x1, x2, y1, y2, mod1, mod2;

    scanf("%d %d %d %d %d %d", &x1, &y1, &mod1, &x2, &y2, &mod2);

    printf("Addition: %d\n", add(x1, x2, y1, y2, mod1, mod2));
    printf("Subtraction: %d\n", sub(x1, x2, y1, y2, mod1, mod2));
    printf("Multiplication: %d\n", mult(x1, x2, y1, y2, mod1, mod2));

    return 0;
}
