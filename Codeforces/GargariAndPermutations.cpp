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

int N, K;
int P[6][1010], pos[6][1010];
int dp[1010];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
			pos[i][P[i][j]] = j;
		}
	}

	int ans = 1;
	
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			int pR = P[0][j], pL = P[0][i];
			
			bool all = true;

			for (int k = 1; k < K; k++) {
				if (pos[k][pR] > pos[k][pL]) {
					all = false;
				}
			}

			if (all) {
				dp[i] = max(dp[i], dp[j] + 1);
				chmax(ans, dp[i]);
			}
		}
	}

	cout << ans << "\n";

    return 0;
}
