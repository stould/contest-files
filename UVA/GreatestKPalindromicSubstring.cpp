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

int T, N, K;
string S;
int dp[MAXN][MAXN];

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> S >> K;
		N = (int) S.size();

		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j + i < N; j++) {
				if (i == 0) {
					dp[j][j] = 0;
				} else if (i == 1) {
					dp[j][j + i] = (S[j] != S[j + i]) ? 1 : 0;
				} else {
					dp[j][j + i] = dp[j + 1][j + i - 1];

					if (S[j] != S[j + i]) {
						dp[j][j + i] += 1;
					}
				}
				if (dp[j][j + i] <= K) {
					chmax(ans, i + 1);
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
