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

int Q, D, P;

int main(void) {
	for ( ; cin >> Q && Q != 0; ) {
		cin >> D >> P;
		double l = 0.0, h = 10010101010020.0, m;

		for (int x = 0; x <= 500; x++) {
			m = (l + h) / 2.0;

			double ratio = (m / Q - D) * P;

			if (ratio <= m) {
				l = m;
			} else {
				h = m;
			}
		}
		if (m >= 10010101010020.0) {
			cout << "1 pagina\n";
		} else {
			cout << fixed << setprecision(0) << floor(l) << " ";		

			if ((int) floor(l) == 1) {
				cout << "pagina\n";
			} else {
				cout << "paginas\n";
			}	
		}
	}
    return 0;
}
