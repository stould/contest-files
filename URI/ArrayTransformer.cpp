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

const int MAXN = 300010;
const Int INF = 100101001001010LL;

int N, M;
Int U;
Int P[MAXN];

int main(void) {
	for ( ; scanf("%d%d%lld", &N, &M, &U) == 3; ) {
		for (int i = 0; i < N; i++) {
			scanf("%lld", &P[i]);
		}

		for ( ; M--; ) {
			int L, R, v, p;
			scanf("%d%d%d%d", &L, &R, &v, &p);
			
			L -= 1;
			R -= 1;
			p -= 1;

			int cnt = 0;

			for (int i = L; i <= R; i++) {
				if (P[i] < v) {
					cnt += 1;
				}
			}
			P[p] = U * cnt / (R - L + 1);
		}
		
		for (int i = 0; i < N; i++) {
			printf("%lld\n", P[i]);
		}
	}
    return 0;
}
