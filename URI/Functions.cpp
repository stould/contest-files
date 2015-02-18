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

Int rafael(int x, int y) {
	return (3*x)*(3*x) + y*y;
}
Int beto(int x, int y) {
	return 2*(x*x) + (5*y)*(5*y);
}
Int carlos(int x, int y) {
	return -100*x + (y*y*y);
}

int T;

int main(void) {
	cin >> T;
	for ( ; T--; ) {
		int x, y;
		cin >> x >> y;

		int a = rafael(x, y);
		int b = beto(x, y);
		int c = carlos(x, y);
		if (a > max(b, c)) {
			cout << "Rafael ganhou\n";
		} else if (b > max(a, c)) {
			cout << "Beto ganhou\n";
		} else {
			cout << "Carlos ganhou\n";
		}
	}
    return 0;
}
