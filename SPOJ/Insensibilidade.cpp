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

int N;
Int XA, XB, YA, YB;

int main(void) {
	Int ans = 0LL;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> XA >> YA >> XB >> YB;
		Int da = XA - XB;
		Int db = YA - YB;
		ans += da * da + db * db;
	}
	
	cout << ans << "\n";
    return 0;
}
