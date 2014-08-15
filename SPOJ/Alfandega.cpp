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

int N, Q, A;
int P[110];
int dp[100 * 500 + 10];

int main(void) {
	scanf("%d%d%d", &N, &Q, &A);

	int sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		sum += P[i];
	}

	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= P[i]; j--) {
			dp[j] |= dp[j - P[i]];
		}
	}

	int best = 10101010;

	for (int i = 0; i <= sum; i++) {
		if (dp[i]) {
			int p = max(0, i - Q), q = max(0, (sum - i) - Q);

			chmin(best, p + q);		
		}
	}
	printf("%d\n", best);
	double ans = A * best / 100.0;

	printf("%.2lf\n", ans);
	
	
    return 0;
}
