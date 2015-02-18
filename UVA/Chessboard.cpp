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

int T, N;

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d", &N);

		double L = 0.0;

		if (N != 1) {
			L = N * N;

			if (N % 2 == 1) L += sqrt(2.0) - 1.0;
		}

		printf("%.3lf\n", L);
	}
    return 0;
}
