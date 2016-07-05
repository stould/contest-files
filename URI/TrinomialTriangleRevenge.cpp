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

const Int MOD = 2147483647LL;
Int N;

Int modPow(Int base, int p) {
	if (p == 0) return 1LL;
	
	Int ans = base;
	
	while (p > 1) {
		if (p % 2 == 0) {
			ans = (ans * ans) % MOD;
			p /= 2;
		} else {
			ans = (ans * base) % MOD;
			p -= 1;
		}
		ans = ((ans % MOD) + MOD) % MOD;
	}
	return ans;
}

int main(void) {
	cin >> N;

	cout << modPow(3, N) << endl;
	
	return 0;
}
