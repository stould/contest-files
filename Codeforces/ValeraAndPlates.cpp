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

int N, M, K;

int main(void) {
	N = in();
	M = in();
	K = in();

	int i;
	int ans = 0;

	for (i = 0; i < N; i++) {
		int curr = in();

		if (curr == 1) {
			if (M > 0) {
				M -= 1;
			} else {
				ans += 1;
			}
		} else {
			if (K > 0) {
				K -= 1;
			} else if (M > 0) {
				M -= 1;
			} else {
				ans += 1;
			}
		}
	}

	printf("%d\n", ans);

    return 0;
}
