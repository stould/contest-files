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

class SmallBricks31 {
public:
	int countWays(int, int);
};

int W, H;
Int dp[11][11][1 << 11];

const Int MOD = 1000000007LL;

Int func(int r, int c, int mask) {
	if (r == H) {
		return 1;
	} else if (c == W) {
		return func(r + 1, 0, mask);
	} else {
		Int& ans = dp[r][c][mask];
		
		if (ans == -1LL) {
			ans = func(r, c + 1, mask & ~(1 << c)) % MOD;
	
			if (mask & (1 << c)) {
				ans += func(r, c + 1, mask | (1 << c)) % MOD;
			}
			if (c + 1 < W && (mask & (1 << c)) && (mask & (1 << (c + 1)))) {
				ans += func(r, c + 2, mask | (1 << c) | (1 << (c + 1))) % MOD;
			}
			if (c + 2 < W && (mask & (1 << c)) && (mask & (1 << (c + 2)))) {
				ans += func(r, c + 3, mask | (1 << c) | (1 << (c + 1)) | (1 << (c + 2))) % MOD;
			}
		}
		
		return ans % MOD;
	}
}

int SmallBricks31::countWays(int w, int h) {
	W = w;
	H = h;
	
	memset(dp, -1, sizeof(dp));
	
	return (int) func(0, 0, (1 << W) - 1);
}

//Powered by [KawigiEdit] 2.0!
