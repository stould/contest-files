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

int P1, C1, P2, C2;

int main(void) {
	cin >> P1 >> C1 >> P2 >> C2;

	int a = P1 * C1, b = P2 * C2;

	if (a > b) {
		cout << "-1\n";
	} else if (a == b) {
		cout << "0\n";
	} else {
		cout << "1\n";
	}
	
    return 0;
}
