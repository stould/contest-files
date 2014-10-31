#include <iostream>
#include <cstring>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 110;

int N, K;
int P[MAXN];
Int dp[MAXN][MAXN];

Int func(int pos, int len) {
	if (len == K) {
		return 1;
	} else if (pos >= N) {
		return 0;
	} else {
		Int& ans = dp[pos][len];

		if (ans == -1LL) {
			ans = 0LL;
			for (int i = pos + 1; i < N; i++) {
				if (P[i] >= P[pos]) {
					ans += func(i, len + 1);
				}
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; cin >> N >> K && !(N == 0 && K == 0); ) {
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		memset(dp, -1LL, sizeof(dp));

		Int ans = 0LL;

		for (int i = 0; i < N; i++) {
			ans += func(i, 1);
		}

		cout << ans << "\n";
	}
    return 0;
}
