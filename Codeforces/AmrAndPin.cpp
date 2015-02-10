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

int R;
int Xa, Ya, Xb, Yb;

int main(void) {
	cin >> R >> Xa >> Ya >> Xb >> Yb;

	double dst = hypot(Xa - Xb, Ya - Yb);

	if (Xa == Xb && Ya == Yb) {
		cout << 0 << endl;
	} else {
		int ans = (int) ceil(dst / (double) (2.0 * R));

		cout << ans << endl;
	}
	
    return 0;
}
