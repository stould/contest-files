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

const int MAXN = 2002;

int T, H, F;
int test;
int best[MAXN];
int tree[MAXN][MAXN];
int dp[MAXN][MAXN];

int func(int pos, int h) {
	if (h <= 0) {
		return 0;
	} else {
		int& ans = dp[pos][h];

		if (ans == -1) {
			ans = tree[pos][h] + func(pos, h - 1);

			if (h - F <= H) {
				chmax(ans, best[h - F]);
			}

			for (int j = 0; j < T; j++) {
				if (pos != j) {
					chmax(ans, tree[pos][h] + func(j, h - F));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &test);

	for ( ; test--; ) {
		scanf("%d%d%d", &T, &H, &F);

		memset(tree, 0, sizeof(tree));

		for (int i = 0; i < T; i++) {
			int u, v;
			scanf("%d", &u);

			for (int j = 0; j < u; j++) {
				scanf("%d", &v);
				
				tree[i][v] += 1;
			}
		}

		memset(dp, 0, sizeof(dp));
		memset(best, 0, sizeof(best));

		for (int i = 0; i < T; i++) {
			dp[i][H] = tree[i][H];
			chmax(best[H], dp[i][H]);
		}

		for (int j = H - 1; j >= 0; j--) {
			for (int i = 0; i < T; i++) {
				dp[i][j] = dp[i][j + 1];
				if (j + F <= H) {
					chmax(dp[i][j], best[j + F]);
				}
				dp[i][j] += tree[i][j];

				chmax(best[j], dp[i][j]);
			}
		}

		int ans = best[0];

		printf("%d\n", ans);
	}

    return 0;
}
