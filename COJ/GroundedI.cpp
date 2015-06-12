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

const Int MOD = 1000000007;

int N, K;
Int dp[40][(1 << 12)];

Int func(int pos, int val) {
	if (pos == N) {
		return __builtin_popcount(val) == K;
	} else {
		Int& ans = dp[pos][val];

		if (ans == -1) {
			ans = func(pos + 1, val);
			ans += func(pos + 1, val ^ pos);
			ans %= MOD;
		}
		
		return ans;
	}
}

int main(void) {
	for ( ; scanf("%d%d", &N, &K) == 2; ) {
		N = (1 << N);
		memset(dp, -1, sizeof(dp));
		Int ans = func(0, 0);
		printf("%lld\n", ans % MOD);	
	}
	return 0;
}
