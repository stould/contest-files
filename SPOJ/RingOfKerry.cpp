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

const int MAXN = 1010;

int N;
int P[MAXN], C[MAXN];

int prev(int p) {
	return (((p - 1) % N) + N) % N;
}

int main(void) {
	for ( ; scanf("%d", &N) && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &C[i]);
		}
		int A = -1, B = -1;

		for (int i = 0; (A == -1 || B == -1) && i < N; i++) {
			if (A == -1) {
				int pos = i, used = 0;
				for (int j = 0; j < N - 1; j++) {
					used += P[pos];
					used -= C[pos];

					if (used < 0) {
						break;
					}
					pos = (pos + 1) % N;
				}
				if (used >= 0) A = i + 1;
			}
			if (B == -1) {
				int pos = i, used = 0;
				for (int j = 0; j < N - 1; j++) {
					used += P[pos];
					used -= C[prev(pos)];

					if (used < 0) {
						break;
					}
					pos = prev(pos);
				}
				if (used >= 0) B = i + 1;
			}

		}

		printf("%d %d\n", A, B);
	}
    return 0;
}
