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
string A, B;

int dp[2020][2020];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for ( ; T--; ) {
		cin >> A >> B;
		int N = (int) A.size();
		int M = (int) B.size();

		//		memset(dp, 33, sizeof(dp));

		dp[0][0] = 0;

		for (int i = 1; i <= N; i++) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= M; i++) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				chmin(dp[i][j], dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1));
			}
		}
		cout << dp[N][M] << "\n";
	}
    return 0;
}
