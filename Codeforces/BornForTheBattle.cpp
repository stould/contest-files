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
typedef unsigned uint;

const int MAXN = 100005;

int N, M;
vector<pair<int, int> > graph[MAXN];
int dp[MAXN][3];

int func(int node, int higher, int limit) {
	if (higher >= 2) {
		return 0;
	} else if (node == N) {
		return 1;
	} else {
		int& ans = dp[node][higher];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < (int) graph[node].size(); i++) {
				int u = graph[node][i].first;
				int c = graph[node][i].second;

				ans |= func(u, higher + (c > limit ? 1 : 0), limit);
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	int l = 0, h = 1000000000, m;
	int best = 1000000000;
	
	while (l <= h) {
		m = (l + h) / 2;
		
		memset(dp, -1, sizeof(dp));
		int now = func(1, 0, m);

		if (now) {
			chmin(best, m);
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (best >= 1000000000) {
		best = -1;
	}
	cout << best << endl;
	
	return 0;
}
