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

int T;
int N, M, K;
string S[60];
int on[60];

int dp[60][110];

int func(int l, int k) {
	if (l == N) {
		return k == 0 ? 0 : -101010101;
 	} else {
		int& ans = dp[l][k];

		if (ans == -1) {
			ans = on[l] + func(l + 1, k);

			bool s = true;
			for (int i = k - 1; i >= 0; i--) {
				if (s) {
					s = false;
					ans = max(ans, (M - on[l]) + func(l + 1, i));
				} else {
					s = true;
					ans = max(ans, on[l] + func(l + 1, i));
				}
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> M >> K;

		int ans = 0;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
			int b = 0;
			for (int j = 0; j < M; j++) {
				if (S[i][j] == '*') {
					b += 1;
				}
			}
			on[i] = b;
			ans += b;
		}
		sort(on, on + N);

		for (int i = 0; i < N; i++) {
			if (K > 0) {
				if (M - on[i] > on[i]) {
					ans -= on[i];
					ans += (M - on[i]);
					K -= 1;
				}
			}
		}
		if (K > 0 && K % 2 != 0) {
			ans += on[0];
			ans -= (M - on[0]);
		}
		//		memset(dp, -1, sizeof(dp));
		cout << ans << "\n";
	}

    return 0;
}
