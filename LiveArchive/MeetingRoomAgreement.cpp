#include <bits/stdc++.h>

using namespace std;

int T, N;
int dp[110][15];
vector<pair<int, int> > inv;

int func(int id, int ed) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][ed];

		if (ans == -1) {
			ans = func(id + 1, ed);

			if (inv[id].first >= ed) {
				ans = max(ans, 1 + func(id + 1, inv[id].second));
			}
		}

		return ans;
	}
}

int main() {
	cin >> T;

	for ( ; T--; ) {
		int A, B;

		inv.clear();

		while (cin >> A >> B && !(A == 0 && B == 0)) {
			A += 1;
			B += 1;
      
			if (B < A) swap(A, B);
			inv.push_back(make_pair(A, B));
		}

		N = (int) inv.size();
    
		sort(inv.begin(), inv.end());
    
		memset(dp, -1, sizeof(dp));

    
		int ans = func(0, 0);

		cout << ans << "\n";
	}
	return 0;
}
