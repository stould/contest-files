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

const int MAXN = 20005;
const int INF = INT_MAX / 3;

int N;
int P[MAXN];
int dp[MAXN][2];

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i < N; i++) {
			dp[i][0] = dp[i][1] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (P[i] > P[j]) {
					chmax(dp[i][0], dp[j][0] + 1);
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j > i; j--) {
				if (P[i] > P[j]) {
					chmax(dp[i][1], dp[j][1] + 1);
				}
			}
		}
		int a = -INF, b = -INF;

		for (int i = 0; i < N; i++) {
			chmax(a, dp[i][0]);
			chmax(b, dp[i][1]);
		}
		if (a == b) {
			puts("Caution. I will not intervene.");
		} else {
			puts("Don't worry. I must intervene.");
		}
	}
    return 0;
}
