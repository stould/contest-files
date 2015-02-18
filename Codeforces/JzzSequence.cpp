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

const Int MOD = 1000000007;
Int X, Y, N;
Int dp[1010];

int main(void) {
	cin >> X >> Y >> N;
	dp[0] = X;
	dp[1] = Y;

	for (int i = 1; i <= 20; i++) {
		dp[i + 1] = dp[i] - dp[i - 1];
	}
	N--;
	if (N <= 1) {
		cout << ((dp[N] % MOD) + MOD) % MOD << endl;
	} else {
		cout << ((dp[(N % 6)] % MOD) + MOD) % MOD << endl;
	}
    return 0;
}
