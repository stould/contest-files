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

const int MAXN = 1010;

int N, M, K;
int SX, SY;
int X[MAXN], Y[MAXN], T[MAXN];

int dp[MAXN];

int d[21][21][21][21];

int dst(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);

	int ans = min(dx, dy) + (max(dx, dy) - min(dx, dy));

	return ans;
}

void build(void) {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				for (int l = 1; l <= 20; l++) {
					d[i][j][k][l] = dst(i, j, k, l);
				}
			}
		}
	}
}

int func(int pos) {
	if (pos > K) {
		return 0;
	} else {
		int& ans = dp[pos];

		if (ans == -1) {
			ans = 0;
			for (int i = pos + 1; i <= K; i++) {
				int dist = d[X[pos]][Y[pos]][X[i]][Y[i]];

				if (T[pos] + dist <= T[i]) {
					ans = max(ans, 1 + func(i));
				}
			}
		}
		return ans;
	}
}

int main(void) {
	build();
	for ( ; scanf("%d%d%d", &N, &M, &K) == 3 && (N + M + K) != 0; ) {
		for (int i = 1; i <= K; i++) {
			scanf("%d%d%d", &X[i], &Y[i], &T[i]);
		}

		scanf("%d%d", &X[0], &Y[0]);

		T[0] = 0;

		memset(dp, -1, sizeof(dp));

		int ans = func(0);

		printf("%d\n", ans);
	}
    return 0;
}
