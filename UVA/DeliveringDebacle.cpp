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

int T, N, P;
Int dp[50];

int main(void) {
	cin >> T;

	dp[0] = dp[1] = 1;
	dp[2] = 5;

	for (int i = 3; i <= 40; i++) {
		dp[i] = (Int) dp[i - 1] + 4LL * dp[i - 2] + 2LL * dp[i - 3];
	}

	for ( ; T--; ) {
		cin >> P;
		cout << dp[P] << "\n";
	}

    return 0;
}
