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

int A, B, C;

int main(void) {
	for ( ; cin >> A >> B >> C && (A + B + C != 0); ) {
		Int a = (Int) A * B * C;
		int ans = -1;
		Int l = 0, h = 1000 * 1000 + 1, m;

		for ( ; l <= h; ) {
			Int m = (l + h) / 2;
			Int s = (Int) m * m * m;

			if (s <= a) {
				ans = m;
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
