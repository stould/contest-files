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

int R, C, N, T;
int P[5][5];
int ans;

int dxS[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dyS[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

int dxL[8] = {0, 0, -2, 2, 2, 2, -2, -2};
int dyL[8] = {-2, 2, 0, 0, -2, 2, -2, 2};

int ok(int x, int y) {
	return x >= 0 && y >= 0 && x < R && y < C;
}

int pos(int x, int y) {
	return x * C + y;
}

int dp[(1 << 16)][4][4];

int func(int mask, int step) {
	if (step == N - 1) {
		return 1;
	} else {
		int& ans = dp[mask][R-1][C-1];
		
		if (ans == -1) {
			ans = 0;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (mask & (1 << pos(i, j))) {
						for (int k = 0; k < 8; k++) {
							int li = i + dxL[k];
							int lj = j + dyL[k];
							int si = i + dxS[k];
							int sj = j + dyS[k];

							if (ok(li, lj) && ok(si, sj)) {
								if (mask & (1 << pos(si, sj))) {
									if (!(mask & (1 << pos(li, lj)))) {
										ans += func(mask ^ (1 << pos(li, lj)) ^ (1 << pos(si, sj)) ^ (1 << pos(i, j)), step + 1);
									}
								}
							}
						}
					}
				}
			}
		}		
		return ans;
	}
}

void backtrack(int step) {
	if (step == N - 1) {
		ans += 1;
	} else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (P[i][j] == 1) {
					for (int k = 0; k < 8; k++) {
						int li = i + dxL[k];
						int lj = j + dyL[k];
						int si = i + dxS[k];
						int sj = j + dyS[k];

						if (ok(li, lj) && ok(si, sj)) {
							if (P[li][lj] == 0 && P[si][sj] == 1) {
								P[li][lj] = 1;
								P[si][sj] = 0;
								backtrack(step + 1);
								P[li][lj] = 0;
								P[si][sj] = 1;
							}
						}
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d", &T);

	memset(dp, -1, sizeof(dp));

	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &R, &C, &N);

		int base = 0;


		for (int i = 0; i < N; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			A--; B--;
			base |= (1 << pos(A, B));
		}
		ans = 0;

		ans = func(base, 0);
		
		printf("Case %d: %d\n", t, ans);
	}
    return 0;
}
