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
double L, W;

double func(double x) {
	return 4.0*x*x*x + L*W*x - 2.0*x*x*L - 2.0*x*x*W;
}

int main(void) {
	for ( ; cin >> L >> W; ) {
		double a = 12.0, b = ((-4.0) * L + (-4.0) * W), c = L * W;

		double xa = ((-b) + sqrt(b*b - 4.0*a*c)) / (2.0 * a);
		double xb = ((-b) - sqrt(b*b - 4.0*a*c)) / (2.0 * a);

		double ans[3];
		
		ans[0] = xb;
		ans[1] = 0.0;
		
		double l = xb, h = xa, m = -1;

		for (int i = 0; i < 100; i++) {
			m = (l + h) / 2.0;

			double p = func(m);

			if (p < 0.0) {
				h = m;
			} else {
				l = m;
			}
		}
		ans[2] = m;

		printf("%.3lf %.3lf %.3lf\n", ans[0], ans[1], ans[2] + EPS);
	}
    return 0;
}
