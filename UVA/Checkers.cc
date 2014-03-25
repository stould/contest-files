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

const Int MOD = 1000007LL;
const int MAXN = 105;

int dx[2] = {-1, -1};
int dy[2] = {+1, -1};

int T, N;
Int dp[MAXN][MAXN];

char board[MAXN][MAXN];

bool ok(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int func(int x, int y) {
	if (x == 0) {
		return 1LL;
	} else { 
		Int& ans = dp[x][y];

		if (ans == -1) {
			ans = 0;
			for (int i = 0; i < 2; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (ok(nx, ny)) {
					if (board[nx][ny] == '.') {
						ans = (Int) ((ans % MOD) + (func(nx, ny) % MOD) % MOD);
					} else {
						int nnx = x + 2 * dx[i];
						int nny = y + 2 * dy[i];

						if (ok(nnx, nny)) {
							if (board[nnx][nny] == '.') {
								ans = (Int) ((ans % MOD) + (func(nnx, nny) % MOD) % MOD);
							}
						}
					}
				}
			}
		}
		return ans % MOD;
	}
}

int main(void) {
	T = in();

	for (int t = 1; t <= T; t++) {
		N = in();
		int sx = -1, sy = -1;

		for (int i = 0; i < N; i++) {
			scanf("%s", board[i]);
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 'W') {
					sx = i;
					sy = j;
				}
			}
		}
		memset(dp, -1LL, sizeof(dp));
		printf("Case %d: %d\n", t, func(sx, sy));
	}
    return 0;
}
