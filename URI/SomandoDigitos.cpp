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

Int N;

Int len(int x) {
	int ans = 0;

	for ( ; x > 0; ) {
		ans += 1;
		x /= 10;
	}

	return ans;
}

Int sum(Int x) {
	Int ans = 0;

	for ( ; x > 0; ) {
		ans += (x % 10);
		x /= 10;
	}

	return ans;
}

Int func(Int x) {
	for ( ; len(x) > 1; ) {
		x = sum(x);
	}
	return x;
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		cout << func(N) << "\n";
	}
    return 0;
}
