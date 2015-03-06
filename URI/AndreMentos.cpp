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
int P[1010];
Int dp[1010][1010];

Int func(int l, int r) {
	if (l > r) {
		return 0;
	} else if (l == r) {
		return 1;
	} else {
		Int& ans = dp[l][r];
		
		if (ans == -1) {
			ans = INT_MAX;

			if (P[l] == P[r]) {
				ans = 1 + func(l + 1, r - 1);
			} else {
				ans = min(ans, 1 + func(l + 1, r));
				ans = min(ans, 1 + func(l, r - 1));
			}
		}
		
		return ans;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		memset(dp, -1, sizeof(dp));

		int ans = func(0, N - 1);
		
		cout << "Caso #" << t << ": " <<  ans << "\n";
	}
	
    return 0;
}
