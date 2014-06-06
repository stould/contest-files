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
int dp1[MAXN][MAXN], dp2[MAXN][MAXN], arr[MAXN][MAXN];

int main(void) {
	for ( ; scanf("%d%d%d", &N, &M, &K) == 3 && N + M + K != 0; ) {
		char buff;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				arr[i][j] = dp1[i][j] = dp2[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf(" %c", &buff);
				arr[i][j] = (buff == '.');
			}
			for (int j = 1; j <= M; j++) {
				dp2[i][j] += dp2[i - 1][j] + arr[i][j];
				dp1[i][j] += dp1[i][j - 1] + arr[i][j];
			}
		}
		int ans = INF;

		for (int i = 1; i <= M; i++) {
			for (int j = i; j <= M; j++) {
				int tmp = 0, st = 1;
				for (int k = 1; k <= N; k++) {
					tmp += dp1[k][j] - dp1[k][i - 1];
					if (tmp <= 0) {
						tmp = 0;
						st = k + 1;
					} else if (tmp >= K) {
						if (tmp < ans) {
							//							printf("%d %d %d - %d = %d\n", i, j, k, tmp, (k - st + 1) * (j - i + 1)); 
							ans = min(ans, (k - st + 1) * (j - i + 1));
						}
					}
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				int tmp = 0, st = 1;
				for (int k = 1; k <= M; k++) {
					tmp += dp2[j][k] - dp2[i - 1][k];
					if (tmp <= 0) {
						tmp = 0;
						st = k + 1;
					} else if (tmp >= K) {
						ans = min(ans, (k - st + 1) * (j - i + 1));
					}
				}
			}
		}

		printf("%d\n", ans);
	}
    return 0;
}
