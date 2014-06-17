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

const int MAXN = 510;
const int INF = INT_MAX / 3;

int A, B, T, N, E, S, M;
vector<pair<int, int> > graph[MAXN];
int dp[MAXN][2 * MAXN];

int func(int id, int t) {
	if (id == S) {
		return 0;
	} else if (t >= 2 * MAXN) {
		return INF;
	} else {
		int& ans = dp[id][t];
		
		if (ans == -1) {
			ans = INF;

			for (int i = 0; i < (int) graph[id].size(); i++) {
				int ne = graph[id][i].first;
				int tp = graph[id][i].second;

				if (t % 3 == 0) {
					if (tp == 1) {
						ans = min(ans, 1 + func(ne, t + 1));
					}
				} else {
					if (tp == 0) {
						ans = min(ans, 1 + func(ne, t + 1));
					}
				}
			}
		}

		return ans;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> E >> S >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> T;
		graph[A].push_back(make_pair(B, T));
	}
	memset(dp, -1, sizeof(dp));
	int ans = func(E, 0);
	if (ans >= INF) {
		cout << "*\n";
	} else {
		cout << ans << "\n";
	}
    return 0;
}
