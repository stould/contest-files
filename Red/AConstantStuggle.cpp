#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

int T, C[9], N;
Int dp[9][9][101];

Int f(int start, int end, int rhs) {
	if (rhs == 0)
		return 1;

	Int& ans = dp[start][end][rhs];
	if (ans == -1) {		
		ans = 0;
		for (int i = start; i <= end; i++) {
			if (C[i] <= rhs)
				ans += f(i, end, rhs - C[i]);
		}
	}

	return ans;
}

int main(void) {

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	cin >> T;
	for (int t = 1; T--; t++) {
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < 8; i++) {
			cin >> C[i];
		}
		cin >> N;

		cout << "Equation #" << t << ": ";
		cout << f(0, 7, N) << "\n";
	}

	return 0;
}
