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

Int MOD = 1000007LL;
int N, T;
Int dp[1000001];
int main(void) {
	cin >> T;

	dp[1] = 3;
	
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + i - 1;
		dp[i] += i * 2;
		dp[i] %= MOD;
	}

	for ( ; T--; ) {
		cin >> N;

		Int ans = (dp[N] - 1 + MOD) % MOD;
		
		cout << ans << "\n";
	}
    return 0;
}
