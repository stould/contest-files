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

int main(void) {
	int t = 1;

	for ( ; scanf("%d", &N) && N != 0; ) {
		Int ans = 0LL;

		for (int i = 1; ; i++) {
			if (i + (i + 1) + (i + 2) > N) {
				break;
			}
			int l = i + 1, h = N / 2, m;

			for (int p = 0; p < 30; p++) {
				m = (l + h) / 2;

				int c = i + m, r = N - c;

				if (m >= r) {
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			ans += m - i;
		}

		printf("Case %d: %lld\n", t++, ans);
	}
    return 0;
}
