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

const double EPS = 1e-7;
int T, N;

int main(void) {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int ans = 0, x, y;

		for (int i = 0; i < N; i++) {
			cin >> x >> y;

			double dst = hypot(x, y);

			for (int j = 10; j >= 1; j--) {
				if (dst <= 20. * (11. - j)) {
					ans += j;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
