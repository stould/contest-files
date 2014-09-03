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

const Int INF = 1001010101010010LL;

int T, N;
char S[220];
Int dp[220];

Int func(int id) {
	if (id >= N) {
		return 0LL;
	} else {
		Int& ans = dp[id];

		if (ans == -1) {
			ans = -INF;
			
			Int curr = 0LL;

			for (int i = id; i < N; i++) {
				curr = curr * 10 + (S[i] - '0');
				
				if (curr > INT_MAX) break;

				chmax(ans, curr + func(i + 1));
			}
		}

		return ans;
	}
}

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%s", S);
		N = strlen(S);

		memset(dp, -1LL, sizeof(dp));

		printf("%lld\n", func(0));

	}
    return 0;
}
