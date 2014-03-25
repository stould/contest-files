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

typedef vector<vector<Int> > matrix;

const Int MOD = 1e9;

int T, K, N;
Int B[15], C[15];

matrix mul(matrix A, matrix B) {
	matrix C(K+1, vector<Int>(K+1));
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
			}
		}
	}
	return C;
}
	 
matrix pow(matrix A, int p)	{
	if (p == 1) {
		return A;
	} else if (p % 2) {
		return mul(A, pow(A, p-1));
	} else {
		matrix X = pow(A, p / 2);

		return mul(X, X);
	}
}


int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> K;

		for (int i = 0; i < K; i++) {
			cin >> B[i];

			B[i] %= MOD;
		}
		for (int i = 0; i < K; i++) {
			cin >> C[i];
		}

		cin >> N;

		matrix trans(K, vector<Int>(K, 0LL));

		for (int i = 1; i < K; i++) {
			trans[i][i - 1] = 1LL;
		}

		for (int i = 0; i < K; i++) {
			trans[0][i] = C[i];
		}
		if (N - 1 < K) {
			cout << B[N - 1] << "\n";
		} else {
			matrix res = pow(trans, N - K);

			Int ans = 0LL;

			for (int i = 0; i < K; i++) {
				ans = (ans + (res[0][i] * B[K - i - 1]) % MOD) % MOD;
			}
			
			cout << ans << "\n";
		}
	}
    return 0;
}

