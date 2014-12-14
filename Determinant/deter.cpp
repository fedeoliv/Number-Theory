#include <bits/stdc++.h>
#define LL long long
#define MOD 1000003
#define MAXN 2000010
#define MAXT 5000000

using namespace std;

/*
    Calculate the determinant of an NxN matrix whose entries are given by m[i][j] = gcd(i,j).
    As the determinant D can grow very large, you have to print D%1000003.
*/

int flag[MAXN], n, m, cnt = 0;
LL prime[MAXT], phi[MAXN], maxn = 0, an[MAXT];
char buf[MAXT], *o = buf, *pt = buf;

int main() {
    freopen("a.txt", "r", stdin);
    scanf("%d", &n);

    for(LL i = 1; i <= n; i++) {
        scanf("%lld", &an[i]);
        maxn = max(maxn, an[i]);
    }

    memset(flag, 0, sizeof(flag));

    for(int i = 2; i <= maxn; i++) {
        if(!flag[i]) {
            prime[cnt++] = i;
            phi[i] = i-1;
        }

        for(int j = 0; j < cnt && prime[j]*i <= maxn; j++) {
            flag[i*prime[j]] = 1;

            if(i % prime[j] == 0) {
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            } else phi[i*prime[j]] = phi[i]*(prime[j]-1);
        }
    }

    phi[1] = 1;
    for(int i = 2; i <= maxn; i++) phi[i] = phi[i-1]*phi[i] % MOD;
    for(int i = 1; i <= n; i++) printf("%lld\n", phi[an[i]]);

    return 0;
}
