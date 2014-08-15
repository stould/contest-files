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

Int A, B;

int func(Int x) {
	Int l = 1, h = 10000000000LL, m;

	for ( ; l <= h; ) {
		m = (l + h) / 2LL;

		Int p = m * m;
		if (p > x) {
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	return l;
}

int main(void) {
    for ( ; scanf("%lld%lld", &A, &B) == 2 && A + B != 0; ) {
		Int ans = B - A + 1 - func(B) + func(A - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
