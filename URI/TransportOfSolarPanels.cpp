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

const int INF = INT_MAX / 3;

int t, N, T, F;
int P[105], S[105];

int dp[105][15];

int func(int id, int used) {
	if (id > N) {
		return 0;
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = INF;
			if (used + 1 <= T) {
				for (int i = id; i <= N; i++) {
					ans = min(ans, max(S[i] - S[id-1], func(i + 1, used + 1)));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for ( ; t--; ) {
		cin >> N >> T >> F;

		S[0] = 0;

		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			
			S[i] = S[i - 1] + P[i];
		}

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= T; j++) {
				dp[i][j] = -1;
			}
		}

		int ans = func(1, 0);

		cout << ans << " $" << F * ans * T << endl;

	}
    return 0;
}
