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

const Int MOD = 1000000007LL;

int N, K, D;
Int dp[1010][2];

Int func(int w, int seen) {
	if (w == N) {
		return seen == 1;
	} else if (w > N) {
		return 0LL;
	} else {
		Int& ans = dp[w][seen];
		
		if (ans == -1LL) {
			ans = 0;

			for (int i = 1; i <= K; i++) {
				int ns = seen;
				if (i >= D) ns = 1;
				ans = ((ans % MOD) + (func(w + i, ns) % MOD)) % MOD;
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d%d%d", &N, &K, &D);

	memset(dp, -1, sizeof(dp));

	printf("%I64d\n", func(0, 0));
    return 0;
}
