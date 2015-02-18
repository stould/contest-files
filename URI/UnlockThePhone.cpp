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

const Int MOD = 1300031LL;

int N, P;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
	vector<vector<Int> > res(N * N, vector<Int>(N * N));

	for(int i = 0; i < N * N; i++) {
		for(int j = 0; j < N * N; j++) {
			Int sum = 0LL;
			for (int k = 0; k < N * N; k++) {
				sum = ((sum % MOD) + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
			res[i][j] = sum;
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

int f(int i, int j) {
	return N * j + i;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &P) == 2 && N + P != 0; ) {
		vector<vector<Int> > graph(N * N, vector<Int>(N * N, 0LL));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++) {
					int pi = i + dx[k];
					int pj = j + dy[k];

					if (pi >= 0 && pj >= 0 && pi < N && pj < N) {
						graph[f(i, j)][f(pi, pj)] += 1;
					}
				}
			}
		}

		vector<vector<Int> > expr = binPow(graph, (Int) P);

		Int ans = 0LL;

		for (int i = 0; i < N * N; i++) {
			for (int j = i; j < N * N; j++) {
				ans = (ans + expr[i][j]) % MOD;				
			}
		}

		printf("%lld\n", ans);
	}
    return 0;
}
