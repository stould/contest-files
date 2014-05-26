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
double X1, Y1, X2, Y2;

bool eq(double a, double b) {
	return fabs(a - b)< EPS;
}

int main(void) {
	for ( ; cin >> X1 >> Y1 >> X2 >> Y2 && X1 + X2 + Y1 + Y2 != 0; ) {
		if (X1 > X2 || Y1 > Y2) {
			puts("nao");
		} else {
			if (eq(Y1/X1, Y2/X2)) {
				puts("sim");
			} else {
				puts("nao");
			}
		}
	}
    return 0;
}
