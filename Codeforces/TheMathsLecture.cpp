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

int N, K;
Int M;
Int dp[1010][110][2];

Int modPow(int a, int n, int mod) {
	Int res = 1LL;
	while (n > 0) {
		if (n & 1) {
			res = (res * a) % mod;
		}
		a = (a * 1LL *a)%mod;
		n >>= 1;
	}
	return res;
}


Int func(int pos, int mod, int zero) {
	if (pos == N) {
		return mod == 0 && zero;
	} else if (mod == 0 && pos > 0 && zero) {
		if (pos == N - 1) {
			return 9LL;
		} else {
			return (9LL * modPow(10, N - pos - 1, M)) % M;
		}
	} else {
		Int& ans = dp[pos][mod][zero];

		if (ans == -1LL) {
			ans = 0LL;
			
			for (int i = 0; i <= 9; i++) {
				if (pos == N - 1 && i == 0) continue;
				if (N == 1 && i == 0) continue;
				
				int next_mod = (mod + (i * modPow(10, pos, K))) % K;
				int next_zero = zero;
				
				if (i != 0) {
					next_zero = 1;
				}

				ans = ((ans % M) + (func(pos + 1, next_mod, next_zero) % M)) % M;
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> K >> M;

	memset(dp, -1LL, sizeof(dp));

	cout << func(0, 0, 0) << endl;
	
    return 0;
}
