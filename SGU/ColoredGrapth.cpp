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

const int MAXN = 410;
const int INF = 1010101010;
int A, B, N, M;
vector<pair<int, int> > graph[MAXN];

int vis[MAXN][10];

int bfs(void) {
	queue<pair<int, int> > q;

	q.push(make_pair(1, 0));

	memset(vis, -1, sizeof(vis));
	
	vis[1][0] = 0;

	for ( ; !q.empty(); ) {
		int now = q.front().first;
		int color = q.front().second;

		q.pop();

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_color = graph[now][i].second;

			if (color != next_color && (vis[next][next_color] == -1 || (vis[next][next_color] >= vis[now][color] + 1))) {
				vis[next][next_color] = vis[now][color] + 1;
				q.push(make_pair(next, next_color));
			}
		}
	}


	int ans = INF;
	
	for (int i = 1; i <= 3; i++) {
		if (vis[N][i] != -1) {
			ans = min(ans, vis[N][i]);
		}
	}

	return ans != INF ? ans : -1;
}

int dp[220][5];

int func(int id, int color) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][color];

		if (ans == -1) {
			ans = INF;
			for (int i = 0; i < (int) graph[id].size(); i++) {
				int nx = graph[id][i].first;
				int cl = graph[id][i].second;

				if (cl != color) {
					ans = min(ans, 1 + func(nx, cl));
				}
			}
		}
		return ans;
	}
}

int main(void) {
	N = in();
	M = in();

	int color;

	for (int i = 0; i < M; i++) {
		A = in();
		B = in();
		color = in();

		graph[A].push_back(make_pair(B, color));
	}
	//	memset(dp, -1, sizeof(dp));
	//	int ans = func(1, 0);

	//	printf("%d\n", ans == INF ? -1 : ans);
	printf("%d\n", bfs());
    return 0;
}
