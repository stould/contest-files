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

int T, N;
int P[MAXN], C[MAXN];
int dp[MAXN];

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d%d", &C[i], &P[i]);
		}
		memset(dp, 63, sizeof(dp));
		dp[0] = 0;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < i; j++) {
				int curr = 0;
				for (int k = j + 1; k <= i; k++) {
					curr += C[k];
				}
				chmin(dp[i], dp[j] + (curr + 10) * P[i]);
			}
		}
		printf("%d\n", dp[N]);
	}
    return 0;
}
