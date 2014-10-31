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

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int A = 0, B = 0;
		int A_c = 0, B_c = 0;

		int x, y;

		scanf("%d x %d", &x, &y);
		A += x;
		B += y;
		B_c += y;
		scanf("%d x %d", &x, &y);
		B += x;
		A += y;
		A_c += y;

		if (A != B) {
			if (A > B) {
				puts("Time 1");
			} else {
				puts("Time 2");
			}
		} else {
			if (A_c != B_c) {
				if (A_c > B_c) {
					puts("Time 1");
				} else {
					puts("Time 2");
				}
			} else {
				puts("Penaltis");
			}
		}
	}

    return 0;
}
