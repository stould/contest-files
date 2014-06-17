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

double X1, X2, Y1, Y2;

int main(void) {
	for ( ; cin >> X1 >> Y1 >> X2 >> Y2; ) {
		if (X1 == X2 && Y1 == Y2) {
			cout << "Impossible.\n";
			continue;
		}
		double xm = (X1 + X2) / 2.0;
		double ym = (Y1 + Y2) / 2.0;

		cout << fixed << setprecision(10) << xm+(ym-Y1)  << " " << ym-(xm-X1) << " " << xm+(ym-Y2) << " " << ym-(xm-X2) << "\n";
	}
    return 0;
}
