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

const int MAXN = 40;

int N;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		int sum = 0, part = 0;
		bool ok = false;
		int p = -1;

		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			sum += P[i];
		}
		if (sum % 2 == 0) {
			for (int i = 0; i < N; i++) {
				part += P[i];
				
				if (part == sum / 2) {
					ok = true;
					p = i + 1;
					break;
				}					
			}
		}
		if (ok) {
			printf("Sam stops at position %d and Ella stops at position %d.\n", p, p + 1);
		} else {
			printf("No equal partitioning.\n");
		}
	}
    return 0;
}
