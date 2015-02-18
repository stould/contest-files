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

int A[3], B[3];

int main(void) {
	for (int i = 0; i < 3; i++) {
		A[i] = in();
	}

	bool ok = false;

	for (int i = 0; i < 3; i++) {
		B[i] = in();

		ok |= (B[i] == A[i]);
	}

	if (ok) {
		puts("YES");
	} else {
		puts("NO");
	}

    return 0;
}
