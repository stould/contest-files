#include <bits/stdc++.h>

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

const int MAXN = 1501;

int N;
string S;
int dp[MAXN][MAXN];
vector<pair<int, int> > ans;

void rec(int l, int r) {
	if (l >= r) {
		return;
	} else {
		int best = dp[l + 1][r - r];
		int pos = l;

		for (int i = l; i < r; i++) {
			if (best < dp[l][i] + dp[i + 1][r]) {
				best = dp[l][i] + dp[i + 1][r];
				pos = i;
			}
		}

		if ((S[l] == S[r]) + dp[l + 1][r - 1] > best) {
			if (S[l] == S[r]) {
				ans.push_back(make_pair(l, r));
			}
			rec(l + 1, r - 1);
		} else {			
			rec(l, pos);
			rec(pos + 1, r);
		}
	}
}


int main() {
	freopen("cable.in", "r", stdin);
	freopen("cable.out", "w", stdout);
	
	cin >> N >> S;

	memset(dp, 0, sizeof(dp));
	
	for (int k = 1; k < N; k++) {
		for (int i = 0; i + k < N; i++) {
			dp[i][i + k] = dp[i + 1][i + k - 1];

			if (S[i] == S[i + k]) {
				dp[i][i + k] += 1;
			}
			
			for (int j = i; j <= i + k; j++) {
				chmax(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
			}
		}
	}
	
	cout << dp[0][N - 1] << endl;

	rec(0, N - 1);
	
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
  
	return 0;
}
