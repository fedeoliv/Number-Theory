#include <bits/stdc++.h>
#define MAXN 100

/*
    A user of RSA creates and then publishes a public key based on the two large prime numbers,
    along with an auxiliary value. The prime numbers must be kept secret.
    Anyone can use the public key to encrypt a message, but with currently published methods,
    if the public key is large enough, only someone with knowledge of the prime numbers can
    feasibly decode the message.

    n = modulus.
    e = public exponent or encryption exponent or just the exponent.
    d = secret exponent or decryption exponent.
*/

long int p,q,n,t,flag,e[MAXN],d[MAXN],temp[MAXN],j,m[MAXN],en[MAXN];
char msg[MAXN];

int is_prime(long int pr) {
    int i;
    j = sqrt(pr);

    for(i = 2; i <= j; i++) {
        if(pr % i == 0) return 0;
    }

    return 1;
}

long int compute_d(long int x) {
    long int k = 1;

    while(1) {
        k = k+t;
        if(k % x == 0) return (k/x);
    }
}

void compute_secret_exp() {
    /* Computing the secret exponent d, 1 < d < phi, such that ed ≡ 1 (mod phi) */

    int k = 0;
    for(int i = 2; i < t; i++) {
        if(t % i == 0) continue;
        flag = is_prime(i);

        if(flag == 1 && i != p && i != q) {
            e[k] = i;
            flag = compute_d(e[k]);

            if(flag > 0) {
                d[k] = flag;
                k++;
            }

            if(k == 99) break;
        }
    }
}

int mult_mod(long int a, long int b, long int n) {
    return ((a % n) * (b % n)) % n;
}

void encrypt() {
    long int pt, ct, key = e[0], k, len;
    int i = 0;
    len = strlen(msg);

    while(i != len) {
        pt = m[i];
        pt = pt-96;
        k = 1;

        for(j = 0;j < key; j++) {
            //k=k*pt;
            //k=k%n;
            k = mult_mod(k, pt, n);
        }

        temp[i] = k;
        ct = k+96;
        en[i] = ct;
        i++;
    }

    en[i] = -1;

    printf("\n\nEncrypted message: ");
    for(i = 0; en[i] != -1; i++) printf("%c", (char) en[i]);
}

void decrypt() {
    long int pt, ct, key = d[0], k;
    int i = 0;

    while(en[i] != -1) {
        ct = temp[i];
        k = 1;

        for(j = 0; j < key; j++) {
            //k=k*ct;
            //k=k%n;
            k = mult_mod(k, ct, n);
        }

        pt = k+96;
        m[i] = pt;
        i++;
    }

    m[i] = -1;

    printf("\nDecrypted message: ");
    for(i = 0;m[i] !=-1; i++) printf("%c", (char) m[i]);
    printf("\n");
}

int main() {
    /* Considering the user will enter only prime numbers. */
    scanf("%ld %ld", &p, &q);
    //scanf("%s", msg);
    scanf(" %[^\n]s", msg);

    //sieve();
    n = p*q;
    t = (p-1)*(q-1);
    for(int i = 0; msg[i] != 0; i++) m[i] = msg[i];

    compute_secret_exp();
    printf("\nPossible values of 'e' and 'd' are:\n");
    for(int i = 0; i < j-1; i++) printf("\n%ld \t%ld", e[i], d[i]);

    encrypt();
    decrypt();

    return 0;
}
