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

int N;
pair<int, int> P[101000];

int dp[40005];

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		int ed = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].first, &P[i].second);
			dp[P[i].first] = dp[P[i].second] = 1;
		}

		sort(P, P + N);

		int ans = 1;

		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (P[j].first <= P[i].second) {
					break;
				}
				dp[P[j].second] = max(dp[P[j].second], dp[P[i].second] + 1);
				ans = max(ans, dp[P[j].second]);
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
