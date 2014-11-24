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

const double EPS = 1e-5;

int R, H, W;

double torad(double x) {
	return x * acos(-1.0) / 180.0;
}
int main(void) {
	int t = 1;
	for ( ; cin >> R && R != 0; ) {
		cin >> H >> W;

		if (W < H) {
			swap(H, W);
		}

		double l = 0.0, h = 90.0, m;
		bool ok = false;

		for (int x = 0; x < 100; x++) {
			m = (l + h) / 2.0;
			
			double base = 2.0 * (R * sin(torad(m)));

			if (base + EPS< H) {
				l = m;
			} else {
				double lado = 2.0 * (R * cos(torad(m)));

				if (lado >= W) {
					ok = true;
					break;
				} else {
					h = m;
				}
			}
		}

		if (ok) {
			cout << "Pizza " << t++ << " fits on the table.\n";
		} else {
			cout << "Pizza " << t++ << " does not fit on the table.\n";
		}
	}
    return 0;
}
