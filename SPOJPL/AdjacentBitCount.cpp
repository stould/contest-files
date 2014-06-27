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

int P, N, K, T;
int dp[MAXN][MAXN][2];

int func(int pos, int sum, int last) {
	if (sum > K) {
		return 0;
	} else if (pos == N) {
		return sum == K;
	} else {
		int& ans = dp[pos][sum][last];

		if (ans == -1) {
			ans = 0;

			ans += func(pos + 1, sum, 0);
			if (last == 1) {
				ans += func(pos + 1, sum + 1, 1);
			} else {
				ans += func(pos + 1, sum, 1);
			}
		}

		return ans;
	}
}

int main(void) {
	P = in();

	for (int t = 1; t <= P; t++) {
		T = in();
		N = in();
		K = in();

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				for (int k = 0; k < 2; k++) {
					if (i > 0) {
						dp[i][j][k] += dp[i - 1][j][0];
						if (k == 1) {
							if (j > 0) {
								dp[i][j][k] += dp[i - 1][j - 1][k];
							}
						} else {
							dp[i][j][k] += dp[i - 1][j][1];						
						}
					}					
				}
			}
		}

		printf("%d %d\n", T, dp[N][K][0] + dp[N][K][1]);
	}
    return 0;
}
