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

const int MAXN = 1004;
const int INF = INT_MAX / 4;

int N;
pair<int, int> P[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int dp[MAXN][MAXN];

int func(int id, int used) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][used];

		if (ans == -1) {
			ans = -INF;

		    chmax(ans, func(id + 1, used));
			chmax(ans, P[id].first + used * P[id].second + func(id + 1, used + 1)); 
		}

		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i].first);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i].second);
		}
		sort(P, P + N, cmp);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", func(0, 0));
	}
    return 0;
}
