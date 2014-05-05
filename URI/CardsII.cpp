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

const int MAXN = 10005;
const Int INF = 101010100101000LL;
int N, P[MAXN];;
Int dp[MAXN][MAXN];

Int func(int l, int r) {
	if (l >= r) {
		return 0LL;
	} else {
		Int& ans = dp[l][r];

		if (ans == -1) {
			ans = -INF;

			ans = max(ans, P[l] + func(l + 1, r - 1));
			ans = max(ans, P[r] + func(l + 1, r - 1));
			ans = max(ans, P[l] + func(l + 2, r));
			ans = max(ans, P[r] + func(l, r - 2));

		}

		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			for (int j = i; j < N; j++) {
				dp[i][j] = -INF;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				
			}
		}
		
		//		memset(dp, -1LL, sizeof(dp));
		printf("%lld\n", func(0, N - 1));
	}
    return 0;
}
