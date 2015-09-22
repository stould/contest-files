#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2001;

int T, N, M, K;
string S;
int dp[MAXN][MAXN];

int func(int cake, int p) {
	if (cake == M) {
		if (S[max(0, p - 1)] == 'A') {
			return 1;
		} else {
			return 2;
		}
	} else {
		int& ans = dp[cake][p];

		if (ans == -1) {
			if (S[p] == 'A') {
				ans = 1;
			} else {
				ans = 2;
			}

			bool seen = false;
			for (int i = cake + K; i >= cake + 1; i--) {
				if (i <= M) {
					int nx = func(i, p + 1);
	  
					if (nx == ans) {
						seen = true;
						break;
					} 
				}
			}
			if (!seen) {
				if (ans == 1) {
					ans = 2;
				} else {
					ans = 1;
				}
			}
		}

		return ans;
	}
}

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K >> S;
    
		memset(dp, -1, sizeof(dp));

		int ans = func(0, 0);

		cout << "Case #" << t << ": ";

		if (ans == 1) {
			cout << "A\n";
		} else {
			cout << "B\n";
		}
	}
  
	return 0;
}
