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
const int MOD = 1000000007;
 
int B, G;
Int dp[MAXN][MAXN];
int F[MAXN];

Int func(int b, int g) {
	if (b <= 0 || g <= 0 || b < g) {
		return 0LL;
	} else if (b == g) {
		return F[g] % MOD;
	} else {
		Int& ans = dp[b][g];
		if (ans == -1LL) {
			ans = b - 1 + func(b - 1, g);					
		}

		return ans;
	}
}

int main(void) {
	memset(dp, -1LL, sizeof(dp));

	F[1] = 1LL;

	for (int i = 2; i < MAXN; i++) {
		F[i] = ((F[i - 1] % MOD) * i) % MOD;
	}

	for ( ; scanf("%d%d", &B, &G) == 2 && B + G != 0; ) {
		printf("%lld\n", func(B, G));
	}
    return 0;
}
