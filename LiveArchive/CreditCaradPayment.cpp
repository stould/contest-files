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

double EPS = 1e-8;

int T;
double R, B, M;

int main(void) {
	T = in();

	for ( ; T--; ) {
		scanf("%lf%lf%lf", &R, &B, &M);

		int x;
		bool ok = false;
		double last = 50000.0;

		for (x = 1; x <= 1200 && B > 0 && B <= last && !ok; x++) {
			last = B;
			B *= (1.0 + R / 100.0);
			B = (Int) (B * 100.0 + 0.5 + EPS) / 100.0;
			B -= M;

			if (B - EPS < 0.0) {
				printf("%d", x);
				ok = true;
				break;
			}
		}
		if (!ok) {
			printf("impossible");
		}
		if (T != 0) printf("\n");
	}
    return 0;
}