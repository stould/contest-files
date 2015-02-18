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

Int N;

bool func(Int h) {
	Int sn = h * (3 * h + 1) / 2;

	if (sn <= N && (N - sn) % 3 == 0) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	cin >> N;

	Int l = 1LL, h = 1000000000LL, m;
	Int ans = 0;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		if (func(m + 1)) {
			l = m + 1;
			ans = max(ans, m);
		} else {
			h = m - 1;
		}
	}
	
	cout << ans << "\n";

    return 0;
}
