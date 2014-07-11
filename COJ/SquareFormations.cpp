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

int T, K;

set<Int> perf;
set<Int>::iterator it;

bool func(int p) {
	if (p <= 0) return false;

	if ((p - K) % 2 == 0 && perf.count((p - K) / 2 + K)) {
		return true;
	}
	return false;
}

int main(void) {
	scanf("%d", &T);

	for (Int i = 1; i * i <= 10000000; i++) {
		perf.insert(i * i);
	}
	for (int t = 1; t <= T; t++) {
		scanf("%d", &K);

		int ans = -1;

		for (it = perf.begin(); ans == -1 && it != perf.end(); it++) {
			if (func(*it) && *it - K > 0) {
				ans = *it - K;
				break;
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
    return 0;
}
