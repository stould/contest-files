#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1501;

int N;
string S;
int dp[MAXN][MAXN];
vector<pair<int, int> > ans;
vector<int> cnt[MAXN];

int func(int l, int r) {
	if (l >= r) {
		return 0;
	} else {
		int& ans = dp[l][r];

		if (ans == -1) {
			ans = 0;

			if (S[l] == S[r]) {
				ans = 1 + func(l + 1, r - 1);
			}

			ans = max(ans, func(l + 1, r));
			ans = max(ans, func(l, r - 1));
      
			int pos = lower_bound(cnt[S[l]].begin(), cnt[S[l]].end(), l) - cnt[S[l]].begin();
			int fin = lower_bound(cnt[S[l]].begin(), cnt[S[l]].end(), r) - cnt[S[l]].begin();
	
			for (int i = pos, ct = 0; i < fin && ct < 100; i++, ct++) {
				int curr = cnt[S[l]][i];
				ans = max(ans, func(l, curr) + func(curr + 1, r));
			}
			for (int i = fin - 1, ct = 0; i >= pos && ct < 100; i--, ct++) {
				int curr = cnt[S[l]][i];
				ans = max(ans, func(l, curr) + func(curr + 1, r));
			}
		}
    
		return ans;
	}
}

void rec(int l, int r) {
	if (l >= r) {
		return;
	} else {
		int uA = -1;
		int uB = -1;
		int uC = -1;
		int uD = -1;
    
		int sp = 0;
    
		if (S[l] == S[r]) {
			uA = 1 + func(l + 1, r - 1);
		}
    
		uB = func(l + 1, r);
		uC = func(l, r - 1);
    
		int pos = lower_bound(cnt[S[l]].begin(), cnt[S[l]].end(), l) - cnt[S[l]].begin();
		int fin = lower_bound(cnt[S[l]].begin(), cnt[S[l]].end(), r) - cnt[S[l]].begin();

		for (int i = pos, ct = 0; i < fin && ct < 100; i++, ct++) {
			int curr = cnt[S[l]][i];
			int val = func(l, curr) + func(curr + 1, r);

			if (uD < val) {
				uD = val;
				sp = curr;
			}
		}
		for (int i = fin - 1, ct = 0; i >= pos && ct < 100; i--, ct++) {
			int curr = cnt[S[l]][i];
			int val = func(l, curr) + func(curr + 1, r);

			if (uD < val) {
				uD = val;
				sp = curr;
			}
		}
    
		for (int i = pos; i < (int) cnt[S[l]].size(); i++) {
			int curr = cnt[S[l]][i];
      
			if (curr > r) break;

			if (uD < func(l, curr) + func(curr + 1, r)) {
				uD = func(l, curr) + func(curr + 1, r);
				sp = curr;
			}
		}

		if (uA >= max(uB, max(uC, uD))) {
			ans.push_back(make_pair(l, r));
			rec(l + 1, r - 1);
		} else if (uB >= max(uA, max(uC, uD))) {
			rec(l + 1, r);
		} else if (uC >= max(uA, max(uB, uD))) {
			rec(l, r - 1);
		} else {
			rec(l, sp);
			rec(sp + 1, r);
		}
	}
}


int main() {
	freopen("cable.in", "r", stdin);
	freopen("cable.out", "w", stdout);
  
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cnt[S[i]].push_back(i);    
	}
  
	memset(dp, -1, sizeof(dp));
  
	cout << func(0, N - 1) << "\n";
  
	rec(0, N - 1);
  
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
  
	return 0;
}
