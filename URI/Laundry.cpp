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

int N, LA, LB, SA, SB;

int main(void) {
	while (cin >> N) {
		cin >> LA >> LB >> SA >> SB;

		if (N >= LA && N <= LB && N >= SA && N <= SB) {
			cout << "possivel" << endl;
		} else {
			cout << "impossivel" << endl;
		}
	}
	return 0;
}
