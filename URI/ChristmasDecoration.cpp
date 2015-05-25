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

const double PI = 3.141592654;
double A, B, C;

int main(void) {
	while (cin >> A >> B >> C) {
		double ans = 5.0 * (B * tan(A * PI / 180.0) + C);
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
