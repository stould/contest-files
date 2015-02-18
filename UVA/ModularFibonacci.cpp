#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N, M;

typedef vector<vector<Int> > matrix;

matrix multiply(matrix a, matrix b, Int mod) {
	int C = (int) a.size();
	matrix res(C, vector<Int>(C));
	for(int i = 0; i < C; i++) {
		for(int j = 0; j < C; j++) {
			Int sum = 0LL;
			for (int k = 0; k < C; k++) {
				sum = sum + (((a[i][k] % mod) * (b[k][j] % mod)) % mod);
			}
			res[i][j] = sum;
		}
	}
	return res;
}

matrix binPow(matrix a, Int n, Int mod) {
	if (n <= 1LL) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1, mod), mod);
	} else {
		matrix b = binPow(a, n / 2, mod);
		return multiply(b, b, mod);
	}
}

int main(void) {
	matrix trans;

	trans.push_back(vector<Int>(2, 0LL));
	trans.push_back(vector<Int>(2, 0LL));

	trans[0][0] = 1LL;
	trans[0][1] = 1LL;
	trans[1][0] = 1LL;
	trans[1][1] = 0LL;

	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		if (N == 0) {
			printf("0\n");
			continue;
		}
		Int MOD = 1LL;
		for (int i = 0; i < M; i++) MOD *= 2LL;
		Int ans = 0LL;
		
		matrix expo = binPow(trans, N, MOD);
		
		printf("%lld\n", expo[0][1] % MOD);	
	}
    return 0;
}
