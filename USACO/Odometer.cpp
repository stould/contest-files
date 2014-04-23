#include <iostream>
#include <cstdio>
#include <cmath>

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

Int N, M;

int getLen(Int x) {
	return (int) floor(log10((double)x)) + 1;
}

int cnt(Int x, Int goal, int mask, int yet, int len, int us_mask) {
	if (yet == len) {
		return x <= goal && us_mask == mask;
	} else {
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			if (mask & (1 << i)) {
				if (yet == 0 && i == 0) continue;
				ans += cnt(10L * x + i, goal, mask, yet + 1, len, us_mask | (1 << i));
			}
		}
		return ans;
	}
}

int func(Int x) {
	int ans = 0;
	int len = getLen(x);

	for (int i = 2; i <= len; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j + 1; k < 10; k++) {						
				ans += cnt(0LL, x, (1 << j) | (1 << k), 0, i, 0);				
			}
		}
	}

	return ans;
}

int main(void) {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);
	cin >> N >> M;

	cout << func(M) - func(N - 1) << "\n";

    return 0;
}
