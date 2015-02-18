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
int dp[12][12][(1 << 12)];

int new_mask(int old_mask) {
	
}

int func(int row, int col, int mask) {
	if (row >= N) {
		return 1;
	} else if (col >= M) {
		return func(row + 1, 0, mask);
	} else {
		int& ans = dp[row][col][mask];

		if (ans == -1) {
			if (mask & (1 << col)) {
				//stuck by (row - 1) stick, move on
				ans += func(row, col + 1, mask);
			} else {
				//use vertical stick
				ans += func(row, col + 1, mask);

				if (col + 1 < M && !(mask & (1 << (col + 1)))) {
					ans += func(row, col + 2, mask);
				}
			}
		}

		return ans;
	}
}


int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		memset(dp, -1, sizeof(dp));

		printf("%d\n", func(0, 0, 0, 0));
	}
    return 0;
}
