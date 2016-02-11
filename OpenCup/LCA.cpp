#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef long long Int;

int N;
vector<int> tree[MAXN];
Int ans[MAXN], sub[MAXN];

Int dfs(int n, int p) {
	ans[n] = sub[n] = 0LL;

	Int all = 0LL;

	vector<Int> buff(tree[n].size(), 0LL);
 
	for (int i = 0; i < (int) tree[n].size(); i++) {
		int u = tree[n][i];

		if (u != p) {
			buff[i] = dfs(u, n);
     
			sub[n] += buff[i];
			ans[n] += buff[i];
     
			all += buff[i];
		}
	}
 
	for (int i = 0; i < (int) tree[n].size(); i++) {
		if (tree[n][i] != p) {
			ans[n] += (buff[i] * (all - buff[i]));
			all -= buff[i];
		}
	}
 
	return sub[n] + 1;
}

int main() {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
 
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;

		tree[A].push_back(B);
		tree[B].push_back(A);
	}

	dfs(1, -1);
 
	Int best = *max_element(ans, ans + N + 1);
 
	vector<int> cnt;

	for (int i = 1; i <= N; i++) {
		if (ans[i] == best) {
			cnt.push_back(i);
		}
	}
 
	cout << cnt.size() << "\n";
 
	for (int i = 0; i < (int) cnt.size(); i++) {
		cout << cnt[i] << " ";
	}

	cout << "\n";
 
	return 0;
}
