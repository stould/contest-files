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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;
const int MAXN = 501;
const Int MOD = 1000000007LL;

int T, N, K, P;
Int bin[MAXN][MAXN];
Int fat[MAXN];
Int dp[MAXN][MAXN];

Int func(int pos, int last) {
	if (pos == N) {
		return 0;
	} else {
		Int& ans = dp[pos][last];

		if (ans == -1LL) {
			ans = 0LL;

			if ((P < last && pos >= K) or pos == N - 1) {
				ans += fat[N - (pos - K)];
			}

			ans %= MOD;

			for (int i = last + 1; i <= N; i++) {
				ans += func(pos + 1, i);
				ans %= MOD;
			}
		}

		ans = ((ans % MOD) + MOD) % MOD;

		return ans;
	}
}

int main(void) {
	cin >> T;
	
	bin[0][0] = 1;
	
	for (int n = 1; n < MAXN; n++) {
		bin[n][0] = 1;
		bin[n][n] = 1;

		fat[n] = n;
		
		if (n > 1) {
			fat[n] *= fat[n - 1];
			fat[n] = ((fat[n] % MOD) + MOD) % MOD;
		}
		
		for (int k = 1; k < n; k++) {
			bin[n][k] = (bin[n - 1][k] + bin[n - 1][k - 1]) % MOD;
			if (bin[n][k] >= MOD) {
				bin[n][k] -= MOD;
			}
		}
	}
	
	for (int t = 1; t <= T; t++) {
		cin >> N >> K >> P;

		memset(dp, -1LL, sizeof(dp));
		
		Int ans = func(K - 1, 0);
		
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}

