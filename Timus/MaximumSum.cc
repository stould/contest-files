#include <iostream>
#include <climits>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 105;

int N;

int M[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(void) {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> M[i][j];
		}
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + M[i][j];
		}
	}

	int ans = -INT_MAX / 3;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int sum = 0;
			for (int k = 1; k <= N; k++) {
				sum += dp[k][j] - dp[k][i - 1];
				chmax(ans, sum);
				if (sum < 0) sum = 0;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
