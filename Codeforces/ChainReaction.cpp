#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int N;
pair<int, int> P[MAXN];
int B[MAXN];
int dp[MAXN];

int main() {
	cin >> N;
  
	for (int i = 0; i < N; i++) {
		dp[i] = -1;
    
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N);

	B[0] = -1;
  
	for (int i = 1; i < N; i++) {
		int best = i - 1;
    
		int l = 0, h = i - 1, m;

		while (l <= h) {
			m = (l + h) / 2;

			if (P[i].first - P[i].second <= P[m].first) {
				best = m - 1;
				h = m - 1;
			} else {
				l = m + 1;
			}
		}
		B[i] = best;
		//cout << "deb " << i << " " << B[i] << "\n";
	}

  
  
	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		int p = i;

		while (p >= 0) {
			p = B[p];
			if (p < 0 || dp[p] != -1) break;
		}
		if (p >= 0) {
			dp[i] += dp[p];
		}
	}
  
	int ans = N - dp[N - 1];

	for (int i = N - 1; i >= 0; i--) {
		ans = min(ans, (N - i - 1) + (i + 1 - dp[i]));
	}
  
	cout << ans << "\n";
  
	return 0;
}
