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
int M;

int A[25];
int B[25];
int C[25];

int main(void) {
	int i;

	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (i = 0; i < M; i++)	{
			scanf("%d%d%d", &A[i], &B[i], &C[i]);
		}

		int ar[N];
		int ps[N];

		int ans = 0;

		for (i = 0; i < N; i++) ar[i] = i;

		do {
			for (i = 0; i < N; i++) ps[ar[i]] = i;

			bool ok = true;

			for (i = 0; i < M && ok; i++) {
				int d = abs(ps[A[i]] - ps[B[i]]) ;

				if ((C[i] > 0 && d > C[i]) || (C[i] < 0 && d < -C[i])) {
					ok = false;
				}
			}

			if (ok) ans += 1;

		} while (next_permutation(ar, ar + N));

		printf("%d\n", ans);
	}
    return 0;
}
