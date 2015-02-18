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

const int MAXN = 1010;
const int INF = INT_MAX / 3;

int T;
int N, M, K;

vector<pair<int, int> > graph[MAXN];

int dp[MAXN][MAXN];

int func(int id, int used) {
	if (used > K) {
		return INF;
	} else if (id == N - 1) {
		return 0;
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = INF;

			for (int i = 0; i < (int) graph[id].size(); i++) {
				int u = graph[id][i].first;
				int c = graph[id][i].second;

				chmin(ans, c + func(u, used + 1));
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d%d%d", &N, &M, &K);

		for (int i = 0; i < N; i++) {
			graph[i].clear();
		}

		memset(dp, -1, sizeof(dp));

		int A, B, C;

		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &A, &B, &C);

			graph[A].push_back(make_pair(B, C));
		}

		int ans = func(0, 1);

		printf("%d\n", ans < INF ? ans : -1);
	}

    return 0;
}
