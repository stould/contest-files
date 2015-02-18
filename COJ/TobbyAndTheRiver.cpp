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
int P[10];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		int sum = 0;

		for (int i = 0; i < 6; i++) {
			scanf("%d", &P[i]);
			sum += P[i];
		}
		
		bool ok = false;

		if (sum % 2 == 0) {
			for (int i = 0; !ok && i < (1 << 6); i++) {
				int p = 0;

				for (int j = 0; j < 6; j++) {
					if (i & (1 << j)) {
						p += P[j];
					}
				}
				if (p == sum / 2) {
					ok = true;
				}
			}
		}


		if (ok) {
			puts("Tobby puede cruzar");
		} else {
			puts("Tobby no puede cruzar");
		}
	}
    return 0;
}
