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

const int MAXN = 110;
const int INF = INT_MAX / 3;
int R, C;
char S[MAXN][MAXN];

int dp[MAXN][MAXN];

bool safe(int p, int q) {
	if (p - 1 >= 0 && q + 1 < C) {
		if (S[p - 1][q + 1] == '1') {
			return false;
		}
	}
	if (p - 1 >= 0 && q - 1 >= 0) {
		if (S[p - 1][q - 1] == '1') {
			return false;
		}
	}
	return true;
}

int func(int r, int c) {
	if (r == 0 && c == C - 1) {
		return 0;
	} else {
		int& ans = dp[r][c];

		if (ans == -1) {
			ans = INF;

			if (r - 1 >= 0) {
				if (safe(r - 1, c)) {
					chmin(ans, (S[r - 1][c] == '1' ? 1 : 0) + func(r - 1, c));
				}
			}
			if (r + 1 < R) {
				if (safe(r + 1, c)) {
					chmin(ans, (S[r + 1][c] == '1' ? 1 : 0) + func(r + 1, c));
				}
			}
			if (c + 1 < C) {
				if (safe(r, c + 1)) {
					chmin(ans, (S[r][c + 1] == '1' ? 1 : 0) + func(r, c + 1));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d%d", &R, &C) == 2 && R != 0 && C != 0; ) {
		for (int i = 0; i < R; i++) {
			scanf("%s", S[i]);
		}
		memset(dp, -1, sizeof(dp));
		
		int p = func(R - 1, 0);

		printf("Case %d: ", t++);

		if (p >= INF) {
			printf("Impossible\n");
		} else {
			printf("%d\n", p);
		}
	}
    return 0;
}
