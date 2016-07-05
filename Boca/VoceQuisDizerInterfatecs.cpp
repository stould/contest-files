#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int N, M;
string S[MAXN], Q[MAXN];

int dist(string a, string b) {
	int la = (int) a.size();
	int lb = (int) b.size();
  
	int dp[la + 1][lb + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= la; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= lb; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
	}
	return dp[la][lb];
}

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> Q[i];

			int best = 100101001;
			int id = -1;
      
			for (int j = 0; j < N; j++) {
				int now = dist(Q[i], S[j]);

				if (best > now || (best == now && S[j] < S[id])) {
					best = now;
					id = j;
				}
			}
			assert(id != -1);
			cout << "voce quis dizer " << S[id] << " " << best << "\n";
		}
	}
	return 0;
}
