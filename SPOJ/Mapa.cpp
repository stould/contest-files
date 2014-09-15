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

const int MAXN = 100005;

int N;
vector<pair<int, int> > tree[MAXN];
bool vis[MAXN];

int dfs(int x) {
	vis[x] = true;

	int ans = 0;

	for (int i = 0; i < (int) tree[x].size(); i++) {
		int y = tree[x][i].first;

		if (!vis[y]) {
			ans += dfs(y);
		}
	}

	return 1 + ans;
}
int main(void) {
	scanf("%d", &N);

	int A, B, C;
	
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &A, &B, &C);
		if (C == 0) {
			tree[A].push_back(make_pair(B, C));
			tree[B].push_back(make_pair(A, C));
		}
	}

	Int ans = 0LL, S = N;
	memset(vis, false, sizeof(vis));
	
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			int t = dfs(i);
			ans += (Int) t * (S - t);
			S -= t;
		}
	}

	printf("%lld\n", ans);

    return 0;
}
