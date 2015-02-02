#include <stdio.h>

long long mul_inv(long long a, long long b) {
  if(a%b == 0) return 0;
  else if(b == 1) return 1;

  long long b0 = b, t, q;
  long long x0 = 0, x1 = 1;

  while(a > 1) {
    q = a / b;
    t = b; b = a % b; a = t;
    t = x0; x0 = x1 - q * x0; x1 = t;
  }

  if(x1 < 0) x1 += b0;
  return x1;
}

int main() {
  long long n, m;

  scanf("%lld %lld", &n, &m);
  printf("Modular Multiplicative Inverse of %lld mod %lld = %lld\n", n, m, mul_inv(n, m));

  return 0;
}
