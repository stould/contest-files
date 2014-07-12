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

const int MAXN = 1000090;

int T, N;
int dp[MAXN][2];
int cnt[MAXN];

int main(void) {
	scanf("%d", &T);

	for (int i = 2; i < MAXN; i++) cnt[i] = 2;
	cnt[1] = 1;

	for (int i = 2; i <= MAXN; i++) {
		for (int j = i + i; j <= MAXN; j += i) {
			cnt[j] += 1;
		} 
	}

	for (int i = 1; i < MAXN; i++) {
		int p = cnt[i];
		
		if (p > dp[i - 1][0]) {
			dp[i][0] = p;
			dp[i][1] = i;
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		}
	}
	for ( ; T--; ) {
		scanf("%d", &N);
		printf("%d\n", dp[N][1]);
	}
    return 0;
}
