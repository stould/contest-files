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

int T, P, Q, N;
int Oi[MAXN], Ni[MAXN], Wi[MAXN];

int dp[MAXN][30][90];

int func(int id, int o, int n) {
	if (id == N) {
		return (o <= 0 && n <= 0 ? 0 : INF);
	} else {
		o = max(o, 0);
		n = max(n, 0);

		int& ans = dp[id][o][n];

		if (ans == -1) {
			ans = INF;

			chmin(ans, Wi[id] + func(id + 1, o - Oi[id], n - Ni[id]));
			chmin(ans, func(id + 1, o, n));
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &P, &Q, &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &Oi[i], &Ni[i], &Wi[i]);
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", func(0, P, Q));
	}
	
    return 0;
}
