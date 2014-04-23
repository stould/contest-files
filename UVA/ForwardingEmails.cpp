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

const int MAXN = 50003;

int T, N;
int graph[MAXN];
int dp[MAXN];
bool vis[MAXN];

int dfs(int x) {
	if (vis[x]) {
		return 0;
	} else {
		int ans = 0;
		vis[x] = true;

		ans += 1 + dfs(graph[x]);
	
		vis[x] = false;
		return dp[x] = ans;
	}	
}

int main(void) {
	T = in();

	int u, v;

	for (int t = 1; t <= T; t++) {
		N = in();

		int best = 0, id = 0;

		for (int i = 1; i <= N; i++) {
			vis[i] = false;
			dp[i] = 0;

			u = in(), v = in();
			graph[u] = v;
		}

		for (int i = 1; i <= N; i++) {			
			if (dp[i] == 0) dfs(i);

			if (dp[i] > best) {
				best = dp[i];
				id = i;
			}
		}
		printf("Case %d: %d\n", t, id);
	}
    return 0;
}
