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

int N, S;
Int dp[101][500];

Int func(int pos, int sum) {
	if (pos == N && sum != S / 2) {
		return 0;
	} else if (pos == 2 * N) {
		return sum == 0;
	} else {
		Int& ans = dp[pos][sum];

		if (ans == -1LL) {
			ans = 0LL;

			for (int i = 0; i <= 9; i++) {
				if (pos < N) {
					ans += func(pos + 1, sum + i);
				} else {
					ans += func(pos + 1, sum - i);
				}
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d%d", &N, &S);
	memset(dp, -1LL, sizeof(dp));
	if (S % 2 != 0 && S / 9 > 2 * N) {
		puts("0");
	} else {
		printf("%lld\n", func(0, 0));
	}
    return 0;
}
