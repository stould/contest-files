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
int dp[60];

int main(void) {
	dp[1] = dp[2] = 1;

	for (int i = 3; i <= 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for ( ; cin >> N && N != 0; ) {
		cout << dp[N + 1] << "\n";
	}
    return 0;
}
