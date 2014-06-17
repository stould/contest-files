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

int T;
double D, U, V;

int main(void) {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> V >> U;

		cout << "Case " << t << ": ";

		if (V >= U || U == 0.0 || V == 0.0) {
			cout << "can't determine\n";
 		} else {
			double da = D / U;
			double db = D / sqrt(U*U - V*V);

			cout << fixed << setprecision(3) << fabs(da - db) << "\n";
		}
	}
    return 0;
}
