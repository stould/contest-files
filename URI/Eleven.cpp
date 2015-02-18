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

const Int MOD = 1000000007;

string S;
int N;
int cnt[12];
Int dp[15][15][60][60];
Int comb[110][110];

Int func(int pos, int mod, int plus, int minus) {
	if (plus < 0 || minus < 0) {
		return 0LL;
	} else if (pos == 10) {
		return mod == 0 && plus == 0 && minus == 0;
	} else  {
		Int& ans = dp[pos][mod][plus][minus];
		
		if (ans == -1LL) {
			ans = 0LL;

			for (int i = 0; i <= cnt[pos]; i++) {
				int p = i;
				int q = cnt[pos] - i;

				int sum = (((mod + p * pos - q * pos) % 11) + 11) % 11;
			
				ans = (ans + ((comb[pos == 0 ? plus - 1 : plus][p] * comb[minus][q]) % MOD) * func(pos + 1, sum, plus - p, minus - q)) % MOD;
			}
		}

		return ans;
	}
}

int main(void) {
	comb[0][0] = 1;
	for (int i = 1; i < 110; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < 110; j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];

			if (comb[i][j] >= MOD) {
				comb[i][j] -= MOD;
			}
		}
	}
	for ( ; cin >> S; ) {
		N = (int) S.size();

		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < N; i++) {
			cnt[S[i] - '0'] += 1;
		}
		memset(dp, -1LL, sizeof(dp));
		printf("%lld\n", func(0, 0, (N + 1) / 2, N / 2));
	}
    return 0;
}
