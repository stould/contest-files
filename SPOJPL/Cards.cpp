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

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N;

		Int ans = 0LL;

		for (int i = 0; i < N; i++) {
			ans += (i + 1) * 3LL;
			ans %= MOD;
		}
		ans -= N;
		ans = (ans + MOD) % MOD;

		cout << ans << "\n";
	}
    return 0;
}
