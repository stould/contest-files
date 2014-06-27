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

const int MOD = 1000000007;

string S;
int N;
int cnt[12];
int dp[15][15][60][60];
int comb[110][110];

int func(int pos, int mod, int plus, int minus) {
	int p = ceil(N / 2.0);
	int n = N - p;

	if (plus > p || minus > n) {
		return 0;
	} else if (pos == 10) {
		return mod == 0 && plus + minus == N;
	} else  {
		int& ans = dp[pos][mod][plus][minus];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i <= cnt[pos]; i++) {
				int p = i;
				int q = cnt[pos] - i;

				int p_mod = (((plus + i - minus) % MOD) + MOD) % MOD;
				int m_mod = (((plus - i - minus) % MOD) + MOD) % MOD;

				ans += func(pos + 1, 
			}
		}
	}
}

int main(void) {
	comb[0][0] = 1;
	for (int i = 1; i < 110; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < 1010; j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];

			if (comb[i][j] >= MOD) {
				comb[i][j] -= MOD;
			}
		}
	}
	for ( ; cin >> S; ) {
		N = (int) S.size();

		for (int i = 0; i < N; i++) {
			cnt[S[i] - '0'] += 1;
		}
		memset(dp, -1, sizeof(dp));
		
		printf("%d\n", func(0, 0, 0, 0));
	}
    return 0;
}
