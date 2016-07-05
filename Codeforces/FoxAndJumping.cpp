#include <bits/stdc++.h>

using namespace std;

const long long INF = 1010010101001010LL;
const int MAXN = 310;

int N;
int L[MAXN];
int C[MAXN];

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

map<int, long long> dp[MAXN];

long long func(int pos, int dv) { 
	if (dv == 1) {
		return 0;
	} else if (pos == N) {
		return INF;   
	} else {
		if (dp[pos][dv] == 0) {
			dp[pos][dv] = func(pos + 1, dv);
			dp[pos][dv] = min(dp[pos][dv], C[pos] + func(pos + 1, gcd(dv, L[pos])));
		}
		return dp[pos][dv];
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &L[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
	}
 
	long long ans = INF;

	for (int i = 0; i < N; i++) {
		ans = min(ans, C[i] + func(i, L[i]));
	}

	if (ans == INF) {
		ans = -1;
	}

	printf("%I64d\n", ans);

	return 0;
}
