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

const int MAXN = 305;
const int INF = INT_MAX / 3;

int N, M, K;
int dp[MAXN][MAXN], arr[MAXN][MAXN];

int main(void) {
	for ( ; scanf("%d%d%d", &N, &M, &K) == 3 && N + M + K != 0; ) {
		char buff;
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				arr[i][j] = dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf(" %c", &buff);
				arr[i][j] = (buff == '.');
			}
			for (int j = 1; j <= M; j++) {
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			}
		}
		int ans = INF;

		for (int i = 1; i <= M; i++) {
			for (int j = i; j <= M; j++) {
				int tmp = 0, st = 1;
				for (int k = 1; k <= N; k++) {
					tmp += dp[k][j] - dp[k][i - 1];
					if (tmp >= K) {
						while (st < k && tmp - (dp[st][j] - dp[st][i - 1]) >= K) {
							tmp -= dp[st][j] - dp[st][i - 1];
							st += 1;
						}			
						ans = min(ans, (k - st + 1) * (j - i + 1));				
					}
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
