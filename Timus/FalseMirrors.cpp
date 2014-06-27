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

const int MAXN = 21;
const int INF = INT_MAX / 3;

int N;
int P[MAXN];
int dp[1<<20];

int func(int mask) {
	int pp = __builtin_popcount(mask);
	if (pp == N) {
		return 0;
	} else {
		int& ans = dp[mask];
		if (ans == -1) {
			ans = INF;
			for (int i = 0; i < N; i++) {
				int l = (i - 1 >= 0 ? i - 1 : N - 1);
				int c = i;
				int r = (i + 1 == N ? 0 : i + 1);

				if (mask & (1 << c)) continue;				

				
				int spent = 0;
				
				for (int i = 0; i < N; i++) {
					if (!(mask & (1 << i))) {
						if (i == l || i == c || i == r) continue;
						spent += P[i];
					}
				}
				int nmask = mask | (1 << l) | (1 << c) | (1 << r);
				ans = min(ans, spent + func(nmask));
			}
		}
		return ans;
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", func(0));
    return 0;
}
