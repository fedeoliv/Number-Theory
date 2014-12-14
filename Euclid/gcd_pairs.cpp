#include <stdio.h>
#define MAXN 100001
#define ULL unsigned long long

ULL phi[MAXN];

/* How many pairs (x,y) can be possible in range N, which gcd is greater than 1. */

void init() {
    phi[1] = 1LL;
    ULL i, j;

    for(ULL i = 2LL; i < MAXN; ++i) {
        if(phi[i] == 0LL) {
            phi[i] = i-1LL;

            for(j = i << 1; j < MAXN; j+= i) {
                if(phi[j] == 0LL) phi[j] = j;
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

    for(i = 2LL; i < MAXN;++i) phi[i] += phi[i-1];
}

inline ULL pairs(ULL n) {
    return (n * (n-1LL) / 2LL) - phi[n-1];
}

int main() {
    init();

    int cases, n;
    scanf("%d",&cases);

    for(int t = 1; t <= cases; ++t) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", t, pairs(n+1));
    }

    return 0;
}

