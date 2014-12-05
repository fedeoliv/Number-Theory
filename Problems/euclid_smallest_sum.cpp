#include <bits/stdc++.h>
#define MAX 1000000007
#define ULL unsigned long long

/*
    Consider the famous euclid algoithm to calculate the GCD of two integers (a, b).
    For input (7, 3) the 'while' loop will run 2 times as follows: (7, 3)  => (3, 1) =>  (1, 0)
    Now given an integer N you have to find the smallest possible sum of two non-negative integers a, b (a>=b)
    such that the while loop in the above mentioned function for (a, b) will run exactly N times.

    Input:  Output:
    1       2
    1

    Explaination: (1,1) is the required pair.
*/

void multiply(ULL F[2][2], ULL M[2][2]) {
    ULL x = ((F[0][0]*M[0][0])%MAX + (F[0][1]*M[1][0])%MAX)%MAX;
    ULL y = ((F[0][0]*M[0][1])%MAX + (F[0][1]*M[1][1])%MAX)%MAX;
    ULL z = ((F[1][0]*M[0][0])%MAX + (F[1][1]*M[1][0])%MAX)%MAX;
    ULL w = ((F[1][0]*M[0][1])%MAX + (F[1][1]*M[1][1])%MAX)%MAX;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ULL F[2][2], ULL n) {
    if(n == 0 || n == 1) return;
    ULL M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if(n&1) multiply(F, M);
}

ULL fib(ULL n) {
    ULL F[2][2] = {{1,1},{1,0}};
    if(n == 0) return 0;
    power(F,n-1);
    return F[0][0];
}

int main() {
    int t;
    ULL n;

    scanf("%d",&t);

    while(t--) {
        scanf("%llu", &n);

        if(n == 0) printf("0\n");
        else if(n == 1) printf("2\n");
        else printf("%llu\n", (fib(n+3)) % MAX);
    }

    return 0;
}
