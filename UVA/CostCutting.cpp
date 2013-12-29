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

int T;
int A[5];

int main(void) {
	T = in();

	int x;

	for (x = 1; x <= T; x++) {
		A[0] = in();
		A[1] = in();
		A[2] = in();

		sort(A, A + 3);

		printf("Case %d: %d\n", x, A[1]);
	}
    return 0;
}