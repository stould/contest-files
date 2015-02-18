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
const double INF = 101010101010.0;
int N, A, B, C;
int X[MAXN], Y[MAXN], R[MAXN];

double dp[MAXN][MAXN];

bool reach(int i, int j) {
	return hypot(X[i] - X[j], Y[i] - Y[j]) <= R[i] + R[j];
}

int main(void) {
	for ( ; cin >> N; ) {
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> R[i];
		}
		cin >> C;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = INF;				
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					double dij = hypot(X[i] - X[j], Y[i] - Y[j]);
					double dik = hypot(X[i] - X[k], Y[i] - Y[k]);
					double djk = hypot(X[k] - X[j], Y[k] - Y[j]);

					if (reach(i, j) && reach(i, k) && reach(k, j)) {
						dp[i][j] = min(dp[i][j], dij + djk);
					}				
				}
			}
		}
		
		for (int i = 0; i < C; i++) {
			cin >> A >> B;

			if (dp[A-1][B-1] >= INF) {
				cout << "-1\n";
			} else {
				cout << fixed << setprecision(0) << dp[A-1][B-1] << "\n";
			}
		}
	}
    return 0;
}
