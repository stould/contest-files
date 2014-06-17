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

int N;
int P[15];
int dp[1 << 15];

int func(int mask) {
	int cnt = __builtin_popcount(mask);

	if (N - cnt < 3) {
		return 0;
	} else {
		int& ans = dp[mask];

		if (ans == -1) {
			ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						if (!(mask & 1 << i) && !(mask & 1 << j) && !(mask & 1 << k)) {
							int sum = P[i] + P[j] + P[k];

							ans = max(ans, (sum >= 20) + func(mask | (1 << i) | (1 << j) | (1 << k)));
						}
					}					
				}
			}
		}
		return ans;
	}
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		printf("Case %d: ", t++);
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		if (N < 3) {
			printf("0\n");
		} else {
			memset(dp, -1, sizeof(dp));
			printf("%d\n", func(0));
		}
	}
    return 0;
}
