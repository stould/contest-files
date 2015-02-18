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

int N, A, B, K;
Int dp[5050][5050];

Int func(int curr, int u) {
	if (u == K) {
		return 1LL;
	} else {
		Int& ans = dp[curr][u];

		if (ans == -1LL) {
			ans = 0LL;

			int dsb = abs(curr - B);

			for (int i = 1; i < dsb; i++) {
				if (curr + i <= N && curr + i != B) {
					ans = (ans % MOD) + (func(curr + i, u + 1) % MOD);
				}
				if (curr - i >= 1 && curr - i != B) {
					ans = (ans % MOD) + (func(curr - i, u + 1) % MOD);
				}
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> N >> A >> B >> K;
	memset(dp, -1, sizeof(dp));
	cout << func(A, 0) << "\n";
    return 0;
}
