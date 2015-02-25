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
double X, Y;

int pt(double ds) {
	if (ds <= 2.0) {
		return 7;
	} else if (ds <= 4.0) {
		return 5;
	} else if (ds <= 6.0) {
		return 3;
	} else if (ds <= 8.0) {
		return 1;
	}
	return 0;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf", &X, &Y);
			ans += pt(hypot(X, Y));
		}
		printf("%d\n", ans);
	}
    return 0;
}
