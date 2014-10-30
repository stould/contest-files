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

int X1, Y1, X2, Y2;

int main(void) {
	for ( ; cin >> X1 >> Y1 >> X2 >> Y2; ) {
		if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) break;
		if (X1 == X2 && Y1 == Y2) {
			cout << 0 << "\n";
		} else if (abs(X1 - X2) == abs(Y1 - Y2) || X1 == X2 || Y1 == Y2) {
			cout << 1 << "\n"; 
		} else {
			cout << 2 << "\n";
		}
	}
    return 0;
}
