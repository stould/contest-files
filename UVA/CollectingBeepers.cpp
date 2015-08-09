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

const int MAXN = 11;
const int INF = INT_MAX / 3;

int T;
int N, M, R;
int X[MAXN], Y[MAXN];
int dist[MAXN][MAXN];

int dp[MAXN][(1 << MAXN)];

int func(int pos, int mask) {
	if (mask == (1 << (R + 1)) - 1) {
		return dist[pos][0];
	} else {
		int& ans = dp[pos][mask];

		if (ans == -1) {
			ans = INF;

			for (int i = 0; i <= R; i++) {
				if (!(mask & (1 << i))) {
					chmin(ans, dist[pos][i] + func(i, mask | (1 << i)));
				}
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> X[0] >> Y[0] >> R;

		for (int i = 1; i <= R; i++) {
			cin >> X[i] >> Y[i];
		}
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= R; j++) {
				dist[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
			}
		}
		
		memset(dp, -1, sizeof(dp));
		
		int ans = func(0, 1);

		cout << "The shortest path has length " << ans << endl;
	}
	return 0;
}
