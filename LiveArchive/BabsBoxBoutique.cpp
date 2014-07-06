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
int dp[11][3][3][3][(1 << 10)];
int Q[11][3];

int A[11], B[11], C[11];

int func(int id, int a, int b, int c, int mask) {
	//ending when it's not possible to stack more boxes
	//	printf("%d %d %d %d\n", id, a, b, c);
	if (__builtin_popcount(mask) == N) return 0;
	int& ans = dp[id][a][b][c][mask];

	if (ans == -1) {
		ans = 0;
		
		for (int i = 0; i < N; i++) {
			if (mask == 0) {
				ans = max(ans, 1 + func(i, 0, 1, 2, mask | (1 << i)));
				ans = max(ans, 1 + func(i, 0, 2, 1, mask | (1 << i)));
				ans = max(ans, 1 + func(i, 1, 0, 2, mask | (1 << i)));
				ans = max(ans, 1 + func(i, 1, 2, 0, mask | (1 << i)));
				ans = max(ans, 1 + func(i, 2, 0, 1, mask | (1 << i)));
				ans = max(ans, 1 + func(i, 2, 1, 0, mask | (1 << i)));
			} else {
				if (!(mask & (1 << i))) {
					//a = 0, b = 1, c = 2
					//1 = altura, 
					if (Q[i][1] <= Q[id][b] && Q[i][2] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 0, 1, 2, mask | (1 << i)));
					}
					if (Q[i][2] <= Q[id][b] && Q[i][1] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 0, 2, 1, mask | (1 << i)));
					}
					if (Q[i][0] <= Q[id][b] && Q[i][1] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 2, 0, 1, mask | (1 << i)));
					}
					if (Q[i][0] <= Q[id][b] && Q[i][2] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 1, 0, 2, mask | (1 << i)));
					}
					if (Q[i][1] <= Q[id][b] && Q[i][0] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 2, 1, 0, mask | (1 << i)));
					}
					if (Q[i][2] <= Q[id][b] && Q[i][0] <= Q[id][c]) {
						ans = max(ans, 1 + func(i, 1, 2, 0, mask | (1 << i)));
					}
				}
			}
		}
	}
	return ans;
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &Q[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		int ans = func(0, 0, 0, 0, 0);
		printf("Case %d: %d\n", t++, ans);
	}
    return 0;
}
