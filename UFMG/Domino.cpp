#include <bits/stdc++.h>

using namespace std;

const int MAXN = 22;

int N;
int A[MAXN], B[MAXN];
int dp[1 << 21][8];

int func(int mask, int last) {
	if (mask == (1 << N) - 1) {
		return 0;
	}
 
	int& ans = dp[mask][last];

	if (ans == -1) {
		ans = 0;
   
		for (int i = 0; i < N; i++) {
			if (!(mask & (1 << i))) {
				if (A[i] == last) {
					ans = max(ans, 1 + func(mask | (1 << i), B[i]));
				}
				if (B[i] == last) {
					ans = max(ans, 1 + func(mask | (1 << i), A[i]));
				}   
			}
		}
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &A[i], &B[i]);
		}

		memset(dp, -1, sizeof(dp));
   
		int ans = 0;
   
		for (int i = 0; i < N; i++) {
			ans = max(ans, 1 + func(1 << i, A[i]));
			ans = max(ans, 1 + func(1 << i, B[i]));
		}
   
		printf("%d\n", ans);
	}
	return 0;
}
