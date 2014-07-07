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

double X, Y, P;
int D, A;

int main(void) {
	X = 0.0;
	Y = 0.0;
	P = 90.0;

	for ( ; scanf("%d,%d", &D, &A) == 2 && !(A == 0 && D == 0); ) {
		X = X + cos(P * PI / 180) * D;
		Y = Y + sin(P * PI / 180) * D;
		P -= A;
	}
	printf("%d\n%d\n", (int) X, (int) Y);
    return 0;
}
