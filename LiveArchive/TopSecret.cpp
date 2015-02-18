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

int T;
int N, L, R, X;
Int S, P[1010], exP[1010];

Int modPow(Int value, Int power, Int MOD) {
	if (power == 0LL) {
		return 1LL;
	}
	Int ans = value;	

	for ( ; power > 1; ) {
		if (power % 2 == 1LL) {
			ans = ((ans % MOD) * (value % MOD)) % MOD;
		}
		power /= 2;
		ans = (ans * ans) % MOD;
	}

	return ans;
}

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d%lld%d%d%d", &N, &S, &L, &R, &X);
		
		const Int MOD = (Int) pow(10.0, X);

		for (int i = 0; i < N; i++) {
			scanf("%lld", &P[i]);
			exP[i] = modPow(P[i], S, MOD);
		}

		Int ans[N];

		for (int i = 0; i < N; i++) {
			int l = (i == 0 ? N - 1 : i - 1);
			int r = (i == N - 1 ? 0 : i + 1);

			if (S > 0LL) {
				ans[i] = ((exP[i] % MOD) + ((L * exP[l]) % MOD) + ((R * exP[r]) % MOD)) % MOD;
			} else {
				ans[i] = P[i] % MOD;
			}

			if (i) {
				printf(" ");
			}

			printf("%lld", ans[i]);			
		}
		printf("\n");
	}

    return 0;
}
