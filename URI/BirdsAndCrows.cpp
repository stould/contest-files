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

int T, N;
int P[10], C[10];
int dp[10][(1 << 10)];

int func(int pos, int mask) {
	if (pos == N) return 0;
	
	int& ans = dp[pos][mask];
	
	if (ans == -1) {
		ans = INT_MAX;
		
		for (int i = 0; i < N; i++) {
			if (!(mask & (1 << i))) {
				chmin(ans, max(lcm(P[pos], C[i]), func(pos + 1, mask | (1 << i))));
			}
		}
	}
	
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> C[i];
		}

		memset(dp, -1, sizeof(dp));
		
		int ans = func(0, 0);
		
		cout << "Caso #" << t << ": " << ans <<"\n";
	}
	
    return 0;
}
