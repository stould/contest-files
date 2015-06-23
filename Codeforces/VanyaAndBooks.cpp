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

Int func(int val) {
	int digitCount = (int) log10(val) + 1;
	Int ans = 0LL;
	Int p = 1LL;

	for (int i = 0; i < digitCount - 1; i++) {
		ans += p * 9 * (i + 1);
		p *= 10;
	}
	
	ans += (val - p + 1) * digitCount;
	
	return ans;
}

int main(void) {
	cin >> N;

	cout << func(N) << "\n";
	
	return 0;
}
