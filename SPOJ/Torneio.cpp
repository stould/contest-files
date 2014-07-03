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

const int MOD = 1000000007;
int N, K, M;
int P[15];
int dp[15][(1 << 15)];

int func(int id, int mask) {
	if (id == K) {
		if (K == N + 1) return 1;
		int ans = 0;
		for (int i = 0; i < N - 1; i++) {
			if (!(mask & (1 << i))) {
				if (M < P[i]) {
					ans += 1;
				}
			}
		}
		return ans % MOD;
	} else {
		int& ans = dp[id][mask];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < N - 1; i++) {
				if (!(mask & (1 << i))) {
					if (M > P[i]) {
						ans = (ans + (func(id + 1, mask | (1 << i)) % MOD)) % MOD;
					}
				}
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d%d", &N, &K);
	scanf("%d", &M);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &P[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", func(0, 0));
    return 0;
}
