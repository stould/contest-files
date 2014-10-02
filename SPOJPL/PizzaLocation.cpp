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

const double EPS = 1e-7;
const int MAXN = 105;

int K, R, N, M;
int Lx[25], Ly[25], Sx[110], Sy[110], Sp[110];
bitset<MAXN> reach[25];


int main(void) {
	scanf("%d%d%d", &K, &R, &M);
	
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &Lx[i], &Ly[i]);
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &Sx[i], &Sy[i], &Sp[i]);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			double dst = hypot(Lx[i]- Sx[j], Ly[i] - Sy[j]);
			
			if (dst - EPS <= R) {
				reach[i].set(j);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i < (1 << M); i++) {
		if (__builtin_popcount(i) == K) {
			bitset<MAXN> buff;
			int s = 0;

			for (int j = 0; j < M; j++) {
				if (i & (1 << j)) {
					buff |= reach[j];
				}
			}
			
			for (int j = 0; j < MAXN; j++) {
				if (buff.test(j)) {
					s += Sp[j];
				}
			}
			ans = max(ans, s);
		}
	}

	printf("%d\n", ans);

    return 0;
}
