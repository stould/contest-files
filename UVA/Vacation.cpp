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

const int MAXN = 101;

string A, B;
int dp[MAXN][MAXN];

int main(void) {
	int test = 1;
	for ( ; getline(cin, A) && A != "#"; ) {
		getline(cin, B);
		
		int N = (int) A.size();
		int M = (int) B.size();


		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
				} else {
					chmax(dp[i][j], dp[i - 1][j]);
					chmax(dp[i][j], dp[i][j - 1]);
				}
			}
		}
		cout << "Case #" << test++ << ": you can visit at most " << dp[N][M] << " cities.\n";

	}
    return 0;
}
