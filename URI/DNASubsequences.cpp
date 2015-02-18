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

int K, N, M;
int dp[1001][1001];
char A[1001];
char B[1001];

int func(int ia, int ib) {
	if (ia >= N || ib >= M) {
		return 0;
	} else {
		int& ans = dp[ia][ib];

		if (ans == -1) {
			ans = max(func(ia + 1, ib), func(ia, ib + 1));
			int i = 0;
			for (i = 0; i + ia < N && i + ib < M; i++) {
				if (A[ia + i] != B[ib + i]) {
					break;
				}
				if (i + 1 >= K) {
					chmax(ans, i + 1 + func(ia + i + 1, ib + i + 1));
				}
			}
		}
		return ans;
	}
}

int main(void) {
	char ch;
	for ( ; scanf("%d", &K) && K != 0; ) {
		ch = getchar_unlocked();
		N = M = 0;
		for ( ; ; ) {
			ch = getchar_unlocked();
			if (ch == '\n') {
				A[N++] = '\0';
				break;
			}
			A[N++] = ch;
		}
		for ( ; ; ) {
			ch = getchar_unlocked();
			if (ch == '\n') {
				B[M++] = '\0';
				break;
			}
			B[M++] = ch;
		}
		N--;
		M--;
		memset(dp, 0, sizeof(dp));
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
					if (A[i - k] != B[j - k]) break;
					if (k >= K) {
						chmax(dp[i][j], k + dp[i - k][j - k]);
					}
				}
			}
		}
		
		printf("%d\n", dp[N][M]);
	}
    return 0;
}
