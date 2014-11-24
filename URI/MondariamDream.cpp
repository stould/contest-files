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

int N, M;
int dp[12][(1 << 12)];

bool match(int up, int now) {
	int i = 0; 

	for ( ; i < M; ) {
		if (up & (1 << i)) {
			if (now & (1 << i)) {
				return false;
			} else {
				i += 1;
			}
		} else {
			i += 2;
		}
	}

	return true;
}

int func(int row, int mask) {
	if (row == N) {
		return 1;
	} else {
		int& ans = dp[row][mask];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < (1 << M); i++) {
				if (match(mask, i)) {
					ans += func(row + 1, i);
				}
			}

		}

		return ans;
	}
}


int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		memset(dp, -1, sizeof(dp));

		printf("%lld\n", func(0, 0));
	}
    return 0;
}
