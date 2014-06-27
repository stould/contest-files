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

int T, N;
char str[50];

int dp[50][50];

int func(int pos, int used) {
	if (used > N) return 0;
	if (used == N) {
		return 1;
	} else {
		int& ans = dp[pos][used];

		if (ans == -1) {
			ans = 0;
			int r = 0;
			for (int i = 0, cnt = 1; cnt + used <= N; i++, cnt++) {
				int p = (pos + i) % N;
				if (str[p] == 'R') r += 1;
				if (r > 1) break;
				if (cnt >= 3) {
					printf("%d %d %d\n", pos, p, used);
					ans += func((p + 1) % N, used + cnt);
				}
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%s", &N, str);
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			ans += func(i, 0);
		}
		printf("Case %d: %d\n", t, ans);
	}
    return 0;
}
