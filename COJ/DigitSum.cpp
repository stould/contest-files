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

const int MAXN = 20;

int N;
int D[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &D[i]);
		}
		int ans = 0;		
		sort(D, D + N);
		
		int lz = 0;

		while (D[lz] == 0) {
			lz += 1;
		}

		for (int i = 0; i < 2; i++) {
			if (D[i] == 0) {
				swap(D[i], D[i + lz]);
			}
		}

		int d1 = 0, d2 = 0;
		for (int i = 0; i < N; i += 2) {
			d1 = d1 * 10 + D[i];
			if (i + 1 < N) {
				d2 = d2 * 10 + D[i + 1];
			}
		}
		printf("%d\n", d1 + d2);
		
	}
    return 0;
}
