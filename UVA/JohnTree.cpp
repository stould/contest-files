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

Int T, D, V;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> D >> V;
		Int ans = (1 + (D * (V % MOD)) % MOD);
		cout << "Case " << t << ": " << ans << "\n";
	}

    return 0;
}
