#include <bits/stdc++.h>
#define LL long long
#define MAXN 200
using namespace std;

/*  Given a NxN matrix A, find the Determinant of A % P.
    The first line of every test case contains two integers, representing N (0 < N < 201) and P (0 < P < 1,000,000,001).
    The following N lines each contain N integers, the j-th number in i-th line represents A[i][j].

    Input:
    1 10
    -528261590
    2 2
    595698392 -398355861
    603279964 -232703411
    3 4
    -840419217 -895520213 -303215897
    537496093 181887787 -957451145
    -305184545 584351123 -257712188

    Output:
    0
    0
    2
*/

int N;
LL P;

LL gcd(LL a, LL b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

LL pow_bin(LL x, LL n, LL mod = 0x7fffffff) {
	LL ret = 1;

	for(; n; n >>= 1){
		if(n&1) ret = ret * x % mod;
		x = x * x % mod;
	}

	return ret;
}

LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	LL d = a;

	if(b != 0) {
		d = ext_gcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
	return d;
}

LL mod_inv(LL a, LL mod) {
	LL x, y;
	ext_gcd(a, mod, x, y);
	return (x % mod + mod) % mod;
}

pair<LL, LL> chinese_remainder(const vector<LL>& as, const vector<LL>& ms){
	LL x = 0, mod = 1;

	for(int i = 0; i < (int) as.size(); i++){
		LL a = as[i] - x, d = gcd(ms[i], mod);
		if(a % d != 0) return make_pair(0, -1);
		LL t = a / d * mod_inv(mod / d, ms[i] / d) % (ms[i] / d);
		x = x + mod * t;
		mod *= ms[i] / d;
	}

	return make_pair((x + mod) % mod, mod);
}

LL mat[MAXN][MAXN], mat_tmp[MAXN][MAXN];

LL determinant_modulo_prime(const int n, const LL p, const int e = 1){
    LL ret = 1;
    const LL mod = pow_bin(p, e);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] %= mod;
            if(mat[i][j] < 0) mat[i][j] += mod;
        }
    }

    for(int i = 0; i < n; i++){
        int pivot = -1, mini = 0xff;
        LL inv = -1;

        for(int j = i; j < n; j++){
            if(mat[j][i] != 0){
                if(e == 1){
                    pivot = j;
                    break;
                } else {
                    LL x = mat[j][i];
                    int cnt = 0;
                    for(; x%p == 0; x/=p, cnt++);
                    if(cnt < mini){
                        mini = cnt;
                        pivot = j;
                    }
                }
            }
        }

        if(pivot == -1) return 0;

        if(pivot != i) {
            ret = mod - ret;
            for(int j = i; j < n; j++)
                swap(mat[pivot][j], mat[i][j]);
        }

        if(e == 1){
            ret = ret * mat[i][i] % mod;
            inv = pow_bin(mat[i][i], mod - 2, mod);
        } else {
            LL rem = mat[i][i] / pow_bin(p, mini);
            ret = ret * rem % mod;
            inv = mod_inv(rem, mod);
        }

        for(int j = i; j < n; j++)
            mat[i][j] = mat[i][j] * inv % mod;

        for(int j = i+1; j < n; j++){
            LL mul = mat[j][i] / mat[i][i];
            for(int k = i; k < n; k++){
                mat[j][k] -= mul * mat[i][k] % mod;
                if(mat[j][k] < 0) mat[j][k] += mod;
            }
        }
    }

    for(int i = 0; i < n; i++) ret = ret * mat[i][i] % mod;
    return ret;
}

LL determinant(const int n, const LL mod) {
    if(mod == 1) return 0;

    vector<LL> ms, es, ps;
    LL m = mod;
    for(LL i = 2; i*i <= m; i++) {
        if(m % i == 0){
            ms.push_back(i);
            es.push_back(0);

            while(m % i == 0) {
                es.back()++;
                m /= i;
            }
        }
    }

    if(m != 1){
        ms.push_back(m);
        es.push_back(1);
    }

    for(int i = 0; i < (int) ms.size(); i++)
        ps.push_back(pow_bin(ms[i], es[i]));

    vector<LL> as(ms.size());

    for(int i = 0; i < (int) as.size(); i++){
        memcpy(mat_tmp, mat, sizeof(mat));
        as[i] = determinant_modulo_prime(n, ms[i], es[i]);
        memcpy(mat, mat_tmp, sizeof(mat));
    }

    return (chinese_remainder(as, ps).first + mod) % mod;
}

void init(){
    while(scanf("%d %lld", &N, &P) != EOF) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) scanf("%lld", mat[i] + j);
        printf("%d\n", (int) determinant(N, P));
    }
}

int main(){
    freopen("a.txt", "r", stdin);
    init();
	return 0;
}
