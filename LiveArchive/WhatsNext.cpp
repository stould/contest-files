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

int A, B, C;

int main(void) {
	for ( ; scanf("%d%d%d", &A, &B, &C) == 3 && !(A == 0 && B == 0 && C == 0); ) {
		int da = B - A, db = C - B;

		if (da == db) {
			printf("AP %lld\n", (Int) C + da);
		} else if (B * (B / A) == C) {
			printf("GP %lld\n", (Int) C * (Int) (C / B));
		}
	}
    return 0;
}
