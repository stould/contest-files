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

const int MAXN = 110;
const int INF = INT_MAX / 3;

int B, N;
int F[MAXN];
int C[MAXN];

pair<int, int> dp[MAXN][510];

pair<int, int> func(int pos, int cost) {
	if (cost > B) {
		return make_pair(-INF, -INF);
	} else if (pos >= N) {
		return make_pair(0, 0);
	} else {
		pair<int, int>& ans = dp[pos][cost];
		
		if (ans == make_pair(-1, -1)) {
			ans = func(pos + 1, cost + C[pos]);
			ans.first += F[pos];
			ans.second += C[pos];

			pair<int, int> not_use = func(pos + 1, cost);

			if (not_use.first > ans.first || (not_use.first == ans.first && not_use.second < ans.second)) {
				ans = not_use;
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d%d", &B, &N) && !(B == 0 && N == 0); ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &C[i], &F[i]);
		}

		for (int i = 0; i <= N; i++) {
			fill(dp[i], dp[i] + 500, make_pair(-1, -1));
		}

		pair<int, int> ans = func(0, 0);

		printf("%d %d\n", ans.second, ans.first);
	}
    return 0;
}
