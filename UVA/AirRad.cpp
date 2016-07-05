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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 150;

int T, N, M;
vector<int> G[MAXN];
vector<int> order;
bool vis[MAXN];

void dfs_sort(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) G[x].size(); i++) {
		if (!vis[G[x][i]]) {
			dfs_sort(G[x][i]);
		}
	}
	order.push_back(x);
}

void dfs(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) G[x].size(); i++) {
		if (!vis[G[x][i]]) {
			dfs(G[x][i]);
		}
	}
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> M;

		order.clear();
		
		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
			vis[i] = false;
		}
		
		int A, B;
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			G[A].push_back(B);
		}

		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				dfs_sort(i);
			}
		}

		reverse(order.begin(), order.end());

		memset(vis, false, sizeof(vis));

		int ans = 0;

		for (int i = 0; i < N; i++) {
			int u = order[i];

			if (!vis[u]) {
				ans += 1;
				dfs(u);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
