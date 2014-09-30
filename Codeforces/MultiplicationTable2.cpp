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

Int N, M;
Int K;

int main(void) {
	cin >> N >> M >> K;
	Int l = 1LL, h = (Int) (N * M), m;
	Int ans = -1;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		Int bound = 0LL;

		for (int i = 1; i <= N; i++) {
			bound += min((Int) M, (Int) ((m - 1) / (Int) i));
		}
		if (bound < K) {
			chmax(ans, m);
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
