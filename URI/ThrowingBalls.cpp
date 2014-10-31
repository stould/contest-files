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

int N, V;

int main(void) {
	for ( ; scanf("%d%d", &N, &V) == 2 && N + V != 0; ) {
		bool ok = false;

		for (int i = 1; !ok && i <= V; i++) {
			int p = i, pos = 0;

			for ( ; p > 0; ) {
				for (int j = 0; j < p; j++) {
					pos += p;
					if (pos == N) {
						ok = true;
					}
				}
				p -= 1;
			}
		}
		if (ok) {
			puts("possivel");
		} else {
			puts("impossivel");
		}
	}
    return 0;
}
