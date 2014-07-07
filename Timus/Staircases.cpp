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

int N;
Int dp[510][510]; // stairs in step j with last stair in height i

Int func(int last, int now) {
	if (now < 0) {
		return 0LL;
	} else if (now == 0) {
		return 1LL;
	} else {
		Int& ans = dp[last][now];

		if (ans == -1LL) {
			ans = 0LL;
			for (int i = last + 1; i <= now; i++) {
				ans += func(i, now - i);
			}
		}
		return ans;
	}
}

int main(void) {
	scanf("%d", &N);
	memset(dp, -1LL, sizeof(dp));
	printf("%I64d\n", func(0, N) - 1);
    return 0;
}
