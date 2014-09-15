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

const int MAXN = 10004;

int T, N, P[MAXN];
Int dp[MAXN];

Int func(int id) {
	if (id >= N) {
		return 0;
	} else {
		Int& ans = dp[id];

		if (ans == -1LL) {
			chmax(ans, P[id] + func(id + 2));
			chmax(ans, func(id + 1));			
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		memset(dp, -1, sizeof(dp));
		cout << "Case " << t << ": " << func(0) << endl;
	}
    return 0;
}
