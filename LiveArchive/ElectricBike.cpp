#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 6;
const int MAXN = 1010;

int T, N, K, E;
int A[5], S[MAXN];
int dp[MAXN][15][5][60];

int func(int id, int k, int curr_assist, int curr_energy) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][k][curr_assist][curr_energy];

		if (ans == -1) {
			ans = INF;

			if (curr_energy - curr_assist >= 0) {
				ans = min(ans, max(0, S[id] - A[curr_assist]) + func(id + 1, k, curr_assist, curr_energy - curr_assist));
			} else {
				ans = min(ans, S[id] + func(id + 1, k, 0, 0));
			}
			for (int i = 0; i < 4; i++) {
				if (k > 0 && curr_energy >= i) {
					ans = min(ans, max(0, S[id] - A[i]) + func(id + 1, k - 1, i, curr_energy - i));
				}
			}
		}
    
		return ans;
	}
}

int main() {
	cin >> T;

	A[0] = 0;
	A[1] = 4;
	A[2] = 8;
	A[3] = 11;
  
	for (int t = 1; t <= T; t++) {
		cin >> N >> K >> E;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
    
		memset(dp, -1, sizeof(dp));

		int ans = func(0, K, 0, E);

		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
