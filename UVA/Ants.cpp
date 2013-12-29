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
int N, M;

int main(void) {
	T = in();

	int i;

	for ( ; T--; ) {
		M = in();
		N = in();

		int mid = M / 2;

		int A = 0;
		int B = 0;

		for (i = 0; i < N; i++) {
			int curr = in();

			if (curr <= mid) {
				chmax(A, curr);
				chmax(B, M - curr);
			} else {
				chmax(A, M - curr);
				chmax(B, curr);
			}
		}

		printf("%d %d\n", A, B);
	}
    return 0;
}
