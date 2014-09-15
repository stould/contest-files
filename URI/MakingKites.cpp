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
int A, B;

int main(void) {
	cin >> T;
	
	for ( ; T--; ) {
		cin >> A >> B;
		
		cout << fixed << setprecision(0) << floor(2.0 * (A / 2.0) * (B / 2.0)) << " cm2" << endl;
	}
    return 0;
}
