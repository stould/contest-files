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

const int MOD = 10000;

int N, L, S, T, C;

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
	vector<vector<Int> > res(N, vector<Int>(N));

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum = (sum % MOD) + (a[i][k] * b[k][j]) % MOD;
			}
			res[i][j] = sum;
		}
	}
	return res;
}

vector<vector<Int> > binPow(vector<vector<Int> > a, Int n) {
	if (n == 0LL) {
		return vector<vector<Int> >(a.size(), vector<Int>(a.size(), 0LL));
	} else if (n == 1LL) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<Int> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}

int main(void) {
	for ( ; scanf("%d%d", &N, &L) == 2; ) {
		scanf("%d%d", &S, &T);

		S -= 1;
		T -= 1;

		vector<vector<Int> > mat(N, vector<Int>(N, 0LL));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &C);
				C -= 1;

				mat[i][C] += 1LL;
			}
		}
		
		vector<vector<Int> > ans = binPow(mat, L);					

		if (L == 0LL) {
			printf("%lld\n", S == T ? 1LL : 0LL);
		} else {
			printf("%lld\n", ((ans[S][T] % MOD) + MOD) % MOD);		
		}
	}
    return 0;
}
