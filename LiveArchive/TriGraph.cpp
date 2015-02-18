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

const int MAXN = 100007;
const Int INF = 1010010101001000LL;

int N;
Int gr[MAXN][5], dp[MAXN][5];

int main(void) {
	int test = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 4; j++) {
				gr[i][j] = 0LL;
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%lld", &gr[i][j]);
			}
		}
		dp[0][2] = gr[0][2];
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i > 0) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + gr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + gr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + gr[i][j]);
				}
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + gr[i][j]);
			}
		}
		
		
		printf("%d. %lld\n", test++, dp[N-1][2]);
	}
	return 0;
}
