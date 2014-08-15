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

int N;
Int P[1000005];

int main(void) {
	cin >> N;

	Int ans = 0LL;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			ans = P[i];
		} else {
			if (i % 2 != 0) {
				ans = (ans + (P[i / 2] % MOD)) % MOD;
			} else {
				ans = (ans + (P[(i + 1) / 2] % MOD)) % MOD;
			}
		}
		ans %= MOD;
	}
	cout << ans << "\n";
    return 0;
}
