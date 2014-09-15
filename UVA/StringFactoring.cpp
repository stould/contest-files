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

const int MAXS = 85;
const int INF = INT_MAX / 3;

char S[MAXS];
int dp[MAXS][MAXS];

int func(int l, int r) {
	if (l == r) {
		return 1;
	} else {
		int& ans = dp[l][r];

		if (ans == -1) {
			ans = INF;

			for (int i = l; i < r; i++) {
				chmin(ans, func(l, i) + func(i + 1, r));
			}

			int L = (r - l + 1);

			for (int i = 1; i <= L; i++) {
				if (L % i == 0 && l + i - 1 != r) {
					int pos = 0;
					int j = l;
					for ( ; j <= r; j++) {
						if (S[j] != S[l + pos]) {
							break;
						}
						pos = (pos + 1) % i;						
					}
					if (j == r + 1) {
						chmin(ans, func(l, l + i - 1));
					}
				}
			}
		}
		return ans;
	}
}

int main(void) {
	for ( ; scanf("%s", S) && strcmp(S, "*"); ) {
		memset(dp, -1, sizeof(dp));
		int N = strlen(S);
		printf("%d\n", func(0, N - 1));
	}
    return 0;
}
