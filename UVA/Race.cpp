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
const Int MOD = 10056LL;

int T, N;
Int dp[MAXN], bin[MAXN][MAXN];

int main(void) {
	bin[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		bin[i][0] = bin[i][i] = 1;
		for (int j = 1; j <= 1000; j++) {
			bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % MOD;
		}
	}

	dp[0] = 1;

	for (int i = 1; i <= 1000; i++) {
		dp[i] = 0;
		for (int j = 1; j <= i; j++) {
			dp[i] = (dp[i] + (bin[i][j] * dp[i - j]) % MOD) % MOD;
		}
	}
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		printf("Case %d: %d\n", t, dp[N]);
	}
    return 0;
}
