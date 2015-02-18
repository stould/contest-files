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

const int MAXN = 2020;

int N;
int P[MAXN];
Int dp[MAXN][MAXN];

Int func(int l, int r, int age) {
	if (l > r) {
		return 0;
	} else if (l == r) {
		return P[l] * age;
	} else {
		Int& ans = dp[l][r];

		if (ans == -1LL) {
			chmax(ans, P[l] * age + func(l + 1, r, age + 1));
			chmax(ans, P[r] * age + func(l, r - 1, age + 1));
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", func(0, N - 1, 1));
    return 0;
}
