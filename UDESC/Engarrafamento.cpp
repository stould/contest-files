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
	for ( ; scanf("%d", &N) && N != 0; ) {
		double run = 0.0;
		double spd = 0.0;

		int last = 0;
		
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &A[i], &B[i]);

			last = B[i];
		}
	}
    return 0;
}
