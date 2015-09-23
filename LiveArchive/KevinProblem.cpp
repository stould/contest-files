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

		Int ans = 0LL;

		ans += (N - P) * fat[N - 2];
		ans %= MOD;

		for (int i = K + 2; i <= N; i++) {
			int bigger = N - P;

			cout << bigger << " " << (i - K - 1) << " " << (N - (i - K)) << endl;

			ans += bin[bigger][i - K - 1] * fat[N - (i - K)];
			ans %= MOD;
		}

		ans = ((ans % MOD) + MOD) % MOD;

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}

