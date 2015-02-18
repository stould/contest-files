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

const int MAXN = 100005;

int N, Q;
int P[MAXN], S[MAXN];;

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			if (i == 0) {
				S[i] = 0;
			} else {
				S[i] = S[i - 1] + P[i];
			}
		}
		for (int i = 0; i < Q; i++) {
			int K, id = 1;
			scanf("%d", &K);
			int l = 1, h = N - 1, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				if (K - S[m] > 0) {
					id = m + 1;
					l = m + 1;
				} else {
					h = m - 1;					
				}
			}			

			if (i > 0) printf(" ");
			printf("%d", id);		
			
		}
		printf("\n");
	}
    return 0;
}
