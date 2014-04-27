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

const double PI = acos(-1.0);
int T;
double N, L;
double b, B, H;

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> L >> b >> B >> H;
		double v = (double) L / (double) N;
		double l = 0.0, h = H, m;


		for (int i = 0; i < 50; i++) {
			m = (l + h) / 2.0;
			double bb = (m*B - m*b)/H + b;
			double base = (b*b + b*bb + bb*bb);
			double vol = 1.0/3.0*PI*m*base;

			if (vol >= v) {
				h = m;
			} else {
				l = m;
			}
		}
		printf("%.2lf\n", m);
	}
    return 0;
}
