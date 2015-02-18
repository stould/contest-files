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

int A, B, C;

int main(void) {
	for ( ; cin >> A && A != 0; ) {
		cin >> B >> C;

		double CC = C / 100.0;
		
		double l = 0, h = 100101010100.0, m;
		double ans = 1001010101010.0;
		for (int x = 0; x <= 100; x++) {
			m = (l + h) / 2.0;

			double perc = m * m * CC;

			if (perc < A * B) {
				l = m;
			} else {
				ans = min(ans, m);
				h = m;
			}
		}
		printf("%.0lf\n", floor(ans));		
	}
    return 0;
}
