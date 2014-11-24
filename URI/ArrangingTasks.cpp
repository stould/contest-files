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

const int MAXN = 1003;

int N, H;
pair<int, int> P[MAXN];
int dp[MAXN][MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for ( ; cin >> N >> H; ) {
		int sum = 0LL;

		for (int i = 0; i < N; i++) {			
			cin >> P[i].second >> P[i].first;
			sum += P[i].second;
		}

		sort(P, P + N);

		int ans = 0;
		
		for (int i = 0; i <= N; i++) {
			dp[i][H] = dp[N][i] = 0;
		}		

		for (int i = N - 1; i >= 0; i--) {
			for (int j = H - 1; j >= 0; j--) {
				dp[i][j] = dp[i + 1][j];

				if (P[i].first > j) {
					dp[i][j] = max(dp[i][j], P[i].second + dp[i + 1][j + 1]);
				}
			}

		}
				
		cout << sum - dp[0][0] << "\n";
	}
    return 0;
}
