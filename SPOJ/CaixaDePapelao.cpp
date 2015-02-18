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

int A, B;

int main(void) {
	for ( ; scanf("%d%d", &A, &B) && A + B != 0; ) {
		double a = 12.0, b = -4.0 * A - 4.0 * B, c = (double) A * B;

		double delta = sqrt(b * b - 4.0 * a * c);

		double x1 = (-b + delta) / (2.0 * a);
		double x2 = (-b - delta) / (2.0 * a);

		double root1 = x1 * (B - 2.0*x1) * (A - 2.0*x1);
		double root2 = x2 * (B - 2.0*x2) * (A - 2.0*x2);


		if (root2 > root1) {
			swap(root1, root2);
			swap(x1, x2);
		}

		printf("%.4lf %.4lf\n", x1, root1);
	}
    return 0;
}
