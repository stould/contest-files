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

const int INF = 10010100;

int T;
int X[5], Y[5];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		double lx = INF, rx = -INF;
		double ly = INF, rx = -INF;
		
		for (int i = 0; i < 4; i++) {
			scanf("%d%d", &X[i], &Y[i]);

			lx = min(lx, X[i]);
			ly = min(ly, Y[i]);
			rx = max(rx, X[i]);
			ry = max(ry, Y[i]);
		}

		lx -= 5;
		ly -= 5;
		rx += 5;
		ry += 5;

		while ((rx - lx) < (ry - ly)) {
			double df = ((ry - ly) - (rx - lx)) / 2.0;

			lx -= df;
			rx += df;
		}

		while ((rx - lx) > (ry - ly)) {
			double df = ((rx - lx) - (ry - ly)) / 2.0;
			
			ly -= df;
			ry += df;
		}

		int u = 0;
		int d = 0;
		int l = 0;
		int r = 0;

		for (int i = 0; i < 4; i++) {
			double du = fabs(Y[i] - ry);
			double dd = fabs(Y[i] - ly);
			double dl = fabs(X[i] - lx);
			double dr = fabs(Y[i] - rx);
		}
	}
    return 0;
}
