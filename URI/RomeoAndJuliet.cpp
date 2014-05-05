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

double X1, X2, Y1, Y2, alpha, beta;

int main(void) {
	for ( ; cin >> X1 >> Y1 >> X2 >> Y2 >> alpha >> beta; ) {
		double ans = 0.0;
		double d = hypot(X1 - X2, Y1 - Y2);

		double a = (d * tan((90 - alpha) * M_PI / 180.0));
		double b = (d * tan((90 - beta) * M_PI / 180.0));

		printf("%.3lf\n", a + b);
	}
    return 0;
}
