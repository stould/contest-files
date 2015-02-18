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

const int MAXN = 202;

int N, Q, D, M;
int P[MAXN];

int dp[MAXN][12][22];

int func(int id, int used, int sum) {
	if (used == M) {
		return sum == 0;
	} else if (id >= N) {
		return 0;
	} else {
		int& ans = dp[id][used][sum];

		if (ans == -1) {
			ans = func(id + 1, used, sum);

			if (used + 1 <= M) {
				int s = (((sum % D) + (P[id] % D)) + D) % D;
				ans += func(id + 1, used + 1, s);
			}			
		}

		return ans;
	}
}

int main(void) {
	int test = 1;
	for ( ; scanf("%d%d", &N, &Q) == 2 && !(N == 0 && Q == 0); ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}

		printf("SET %d:\n", test++);

		for (int q = 1; q <= Q; q++) {
			scanf("%d%d", &D, &M);

			memset(dp, -1, sizeof(dp));			

			printf("QUERY %d: %d\n", q, func(0, 0, 0));
		}
	}
    return 0;
}
