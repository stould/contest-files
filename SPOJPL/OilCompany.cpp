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

const int MAXN = 20;

int T, N, M;
int P[MAXN][MAXN];
int dp[MAXN][MAXN][(1 << MAXN)];

int func(int i, int j, int mask) {
	if (j >= M) {
		return func(i + 1, 0, mask);
	} else if (i >= N) {
		return 0;
	} else {
		int& ans = dp[i][j][mask];

		if (ans == -1) {
			ans = func(i, j + 1, (mask & ~(1 << j)));

			if (!(mask & (1 << j))) {
				chmax(ans, P[i][j] + func(i, j + 2, mask | (1 << j)));
			}			
		}
		
		return ans;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> P[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));

		cout << "Case " << t << ": " << func(0, 0, 0) << endl;
	}
	return 0;
}
