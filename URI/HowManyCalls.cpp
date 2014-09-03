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

const int MAXS = 3;
Int N, M;

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
	vector<vector<Int> > res(MAXS, vector<Int>(MAXS));
	for(int i = 0; i < MAXS; i++) {
		for(int j = 0; j < MAXS; j++) {
			Int sum = 0;
			for (int k = 0; k < MAXS; k++) {
				sum = (sum % M + (a[i][k] * b[k][j]) % M) % M;
			}
			res[i][j] = sum % M;
		}
	}
	return res;
}

vector<vector<Int> > binPow(vector<vector<Int> > a, Int n) {
	if (n == 1LL) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<Int> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}

int main(void) {
	vector<vector<Int> > T(MAXS, vector<Int>(MAXS, 0));

	T[0][0] = 1;
	T[0][1] = 1;
	T[1][0] = 1;
	T[2][0] = 1;
	T[2][2] = 1;

	int test = 1;

	for ( ; scanf("%lld%lld", &N, &M) == 2 && N + M != 0LL; ) {
		printf("Case %d: %lld %lld ", test++, N, M);
		if (N <= 1) {
			printf("%d\n", 1 % M);
		} else {
			vector<vector<Int> > Ts = binPow(T, N - 1);
			
			Int ans = (Ts[0][0] % M) + (Ts[1][0] % M) + (Ts[2][0] % M);

			printf("%lld\n", ans % M);
		}
	}
    return 0;
}
