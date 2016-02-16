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

const int MAXN = 1010;
const int INF = INT_MAX / 4;

int T, N, M;
pair<int, int> P[MAXN];
int dp[MAXN][MAXN];

int dist(int a, int b) {
	if (a == 0) {
		return abs(P[b].first - P[b].second);
	} else {
		return abs(P[a].second - P[b].first) + abs(P[b].first - P[b].second);
	}
}

int func(int p1, int p2) {
	if (max(p1, p2) + 1 > M) {
		return 0;
	} else {
		int& ans = dp[p1][p2];

		if (ans == -1) {
			ans = INF;
			
			int next = max(p1, p2) + 1;

			//cout << p1 << " " << next << " " << dist(p1, next) << "\n";
			//cout << p2 << " " << next << " " << dist(p2, next) << "\n";
			
			chmin(ans, dist(p1, next) + func(next, p2));
			chmin(ans, dist(p2, next) + func(p1, next));
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 1; i <= M; i++) {
			cin >> P[i].first >> P[i].second;
		}

		memset(dp, -1, sizeof(dp));

		printf("%d\n", func(0, 0));
	}
	return 0;
}
