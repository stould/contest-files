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

const int MAXN = 20020;

int T, N;
bool vis[MAXN];
Int sum[MAXN];
Int dp[MAXN];
vector<int> tree[MAXN];

Int dfs(int x, int parent, int height) {
	vis[x] = true;

	Int pat = 0LL;
	int child = 0;

	sum[x] = 0LL;

	vector<int> cnt;
	
	for (int i = 0; i < (int) tree[x].size(); i++) {
		int u = tree[x][i];

		if (u == parent || vis[u]) continue;
		
		Int sp = dfs(u, x, height + 1);
		sum[x] += sp;
		cnt.push_back(sp);
		child += 1;
	}

	if (child == 0) {
		dp[x] = 0LL;
	} else {
		for (int i = 0; i < child; i++) {
			for (int j = i + 1; j < child; j++) {
				pat += (Int) cnt[i] * cnt[j];
			}
		}
		dp[x] = (N - sum[x] - 1) * (Int) sum[x] + pat;

		if (child == 1) {
			dp[x] -= pat;
		}
	}

	return sum[x] + 1;
}

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N;

		int A, B;

		for (int i = 0; i < MAXN; i++) {
			tree[i].clear();
			dp[i] = sum[i] = 0LL;
			vis[i] = false;
		}
		
		for (int i = 0; i < N - 1; i++) {
			cin >> A >> B;

			tree[A].push_back(B);
			tree[B].push_back(A);
		}

		dfs(1, -1, 0);

		Int ans = 0LL;

		for (int i = 1; i <= N; i++) {
			chmax(ans, dp[i]);
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}
