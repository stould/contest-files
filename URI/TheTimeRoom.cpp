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

int T;
Int X, Y;

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> X >> Y;

		Int ans = -1;
		
		if (Y >= X) {
			ans = 2;
		} else {
			Int l = 1, h = 100000000000000LL, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				Int ac = Y * m;

				if (ac >= X) {
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			ans = l;
		}
		cout << ans << endl;		
	}
    return 0;
}
