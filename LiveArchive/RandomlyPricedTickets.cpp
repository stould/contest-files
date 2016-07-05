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

int T, N, R, C;
int dist[MAXN][MAXN];
string S[MAXN];
double dp[MAXN][10010];

double func(int len, int money) {
	if (len == 0) {
		return 1;
	} else {
		double& ans = dp[len][money];

		if (ans < 0.0) {
			ans = 0;
			
			for (int i = 1; i <= R; i++) {
				if (money - i >= 0) {
					ans += (1 / (double) R) * func(len - 1, money - i);
				}
			}			
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> R;

		memset(dist, 63, sizeof(dist));
		
		for (int i = 0; i < N; i++) {			
			cin >> S[i];

			for (int j = 0; j < N; j++) {
				if (S[i][j] == 'Y') {
					dist[i][j] = 1;
				}
			}

			for (int j = 0; j <= 10000; j++) {
				dp[i][j] = -1.0;
			}
		}

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					chmin(dist[i][j], dist[i][k] + dist[k][j]);					
				}
			}
		}

		cin >> C;
		
		cout << "Case " << t << endl;

		for (int c = 0; c < C; c++) {
			int A, B, M;
			cin >> A >> B >> M;
			
			int curr_d = dist[A-1][B-1];

			cout << fixed << setprecision(6) << func(curr_d, M) << endl;
		}
		cout << endl;
	}
	return 0;
}
